function feed(parent, args, context, info) {
  return context.prisma.link.findMany();
}

module.exports = {
  feed,
};
