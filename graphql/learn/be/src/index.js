const { PrismaClient } = require("@prisma/client");
const { ApolloServer } = require("apollo-server");
const fs = require("fs");
const path = require("path");
const { getUserId } = require("./utils");

const Query = require("./resolvers/Query");
const Mutation = require("./resolvers/Mutation");
const User = require("./resolvers/User");
const Link = require("./resolvers/Link");

const prisma = new PrismaClient();

const resolvers = {
  Link,
  Mutation,
  Query,
  User,
};

const server = new ApolloServer({
  typeDefs: fs.readFileSync(path.join(__dirname, "./schema.graphql"), "utf-8"),
  resolvers,
  context: ({ req }) => {
    return {
      ...req,
      prisma,
      userId: req && req.headers.authorization ? getUserId(req) : null,
    };
  },
});

server.listen().then(({ url }) => console.log(`Server is running on ${url}`));
