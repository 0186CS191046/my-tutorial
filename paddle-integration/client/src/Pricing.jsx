import React, { useEffect, useState } from "react";
import axios from "axios";

const Pricing = () => {
  const [plans, setPlans] = useState([]);

  const fetchPlans = async () => {
    try {
      const res = await axios.get("http://localhost:8091/api/v1/plans");
      setPlans(res.data.data);
    } catch (error) {
      console.log(error);
    }
  };


useEffect(() => {
  fetchPlans();

  const interval = setInterval(() => {
    if (window.Paddle) {
      window.Paddle.Environment.set("sandbox");

      window.Paddle.Initialize({
        token: process.env.VITE_PADDLE_API_KEY,
      });

      console.log("✅ Paddle initialized");
      clearInterval(interval);
    }
  }, 500);
}, []);

  // 🔥 dynamic checkout
  const openCheckout = (priceId) => {
    console.log(priceId);
    
    window.Paddle.Checkout.open({
      items: [
        {
          priceId: priceId,
          quantity: 1,
        },
      ],
      customer: {
        email: "kajal.kumari@ficode.com",
      },
    });
  };

  const styles = {
    container: {
      display: "flex",
      gap: "20px",
      justifyContent: "center",
      marginTop: "50px",
      flexWrap: "wrap",
    },
    card: {
      border: "1px solid #ddd",
      padding: "20px",
      borderRadius: "10px",
      width: "250px",
      textAlign: "center",
      boxShadow: "0 2px 10px rgba(0,0,0,0.1)",
    },
    button: {
      marginTop: "10px",
      padding: "10px 15px",
      background: "black",
      color: "white",
      border: "none",
      cursor: "pointer",
    },
  };

  return (
    <div style={styles.container}>
      {plans.map((plan) => {
        // 🔥 amount convert (paise → rupees)
        const price = plan.unit_price.amount / 100;

        // 🔥 fallback name
        const name = plan.name || plan.description || "Plan";

        return (
          <div key={plan.id} style={styles.card}>
            <h2>{name}</h2>

            <h3>
              ₹{price} / {plan.billing_cycle.interval}
            </h3>

            {plan.trial_period && (
              <p>
                {plan.trial_period.frequency}{" "}
                {plan.trial_period.interval} free trial
              </p>
            )}

            <button
              style={styles.button}
              onClick={() => openCheckout(plan.id)} // 🔥 dynamic priceId
            >
              Buy Now
            </button>
          </div>
        );
      })}
    </div>
  );
};

export default Pricing;