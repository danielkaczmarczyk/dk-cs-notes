const randInt = (min, max) => Math.floor(Math.random() * (max - min + 1)) + min;

const sleep = (sleepTime) => {
  return new Promise((resolve) => {
    setTimeout(resolve, sleepTime);
  });
};

module.exports.randInt = randInt;
module.exports.sleep = sleep;
