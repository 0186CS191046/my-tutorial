import crypto from "crypto";

function verifyWebhook(rawBody, signature, secret) {
  try {
    const parts = signature.split(";");

    const ts = parts.find(p => p.startsWith("ts="))?.split("=")[1];
    const h1 = parts.find(p => p.startsWith("h1="))?.split("=")[1];

    if (!ts || !h1) return false;

    const payload = `${ts}:${rawBody.toString()}`;

    const expected = crypto
      .createHmac("sha256", secret)
      .update(payload)
      .digest("hex");

    return expected === h1;
  } catch (err) {
    console.log("Verify error:", err);
    return false;
  }
}
const verifyPaddleWebhook = async (req, res, next) => {
    const signature = req.headers["paddle-signature"]; // 🔥 header se aata hai
    const secret = "pdl_ntfset_01kmd380wyfjav9x8es71znke2_2DVeyY6iMexUhcfTKJZmf865qHJqyLh7"; // Paddle dashboard se
console.log("+++++++",signature);

    const isValid = verifyWebhook(req.body, signature, secret);

    console.log("++??????????+",isValid);

    if (!isValid) {
        console.log("❌ Invalid webhook");
        return res.status(400).send("Invalid signature");
    }

    // 🔥 ab JSON parse karo
    const event = JSON.parse(req.body.toString());
    req.event = event;
    next()
}

export default verifyPaddleWebhook;