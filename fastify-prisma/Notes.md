## dependencies
npm install @prisma/client fastify fastify-zod zod zod-to-json-schema fastify-jwt

## devdependencies
npm install  ts-node-dev typescript @types/node --include=dev

## Initialize prisma
npx prisma init --datasource-provider postgresql

## migrate the schema
npx prisma migrate dev --name init

## to generate prismaClient
npx prisma generate