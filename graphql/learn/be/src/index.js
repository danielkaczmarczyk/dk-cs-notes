const { PrismaClient } = require("@prisma/client");
const { ApolloServer, PubSub } = require("apollo-server");
const fs = require("fs");
const path = require("path");
const { getUserId } = require("./utils");

const Link = require("./resolvers/Link");
const Mutation = require("./resolvers/Mutation");
const Query = require("./resolvers/Query");
const Subscription = require("./resolvers/Subscription");
const User = require("./resolvers/User");
const Vote = require("./resolvers/Vote");

const prisma = new PrismaClient();
const pubsub = new PubSub();

const resolvers = {
  Link,
  Mutation,
  Query,
  Subscription,
  User,
  Vote,
};

const server = new ApolloServer({
  typeDefs: fs.readFileSync(path.join(__dirname, "./schema.graphql"), "utf-8"),
  resolvers,
  context: ({ req }) => {
    return {
      ...req,
      prisma,
      pubsub,
      userId: req && req.headers.authorization ? getUserId(req) : null,
    };
  },
});

server.listen().then(({ url }) => console.log(`Server is running on ${url}`));
