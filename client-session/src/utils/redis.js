import { createClient } from "redis";
const client = createClient({url:"redis://default:V4rZklNYE6O8CyP6mOs0lZSe3rNoaN61@redis-10854.crce285.us-east-1-4.ec2.cloud.redislabs.com:10854"});


client.on('error', err => console.log('Redis Client Error', err)); 

// Connect to Redis
client.connect()
  .then(() => console.log('Connected to Redis'))
  .catch(err => console.log('Failed to connect to Redis', err));

export default client;