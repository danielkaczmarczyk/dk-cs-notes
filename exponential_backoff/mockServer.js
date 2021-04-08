const CONFIG = require("./config");
const { randInt } = require("./utils");

const callMockServer = () => {
  const responseTime = randInt(300, 3000);
  const failureChance = randInt(1, 100);

  return new Promise((resolve, reject) => {
    setTimeout(() => {
      if (failureChance > 15) {
        const howManyFailureMessages = CONFIG.REJECTION_MESSAGES.length - 1;
        const message = randInt(0, howManyFailureMessages);
        reject(CONFIG.REJECTION_MESSAGES[message]);
      } else {
        resolve(CONFIG.SUCCESSFUL_RESPONSE);
      }
    }, responseTime);
  });
};

module.exports.callMockServer = callMockServer;
