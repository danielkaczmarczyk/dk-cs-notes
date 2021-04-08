const CONFIG = require("./config");
const { sleep } = require("./utils");

/**
 * This function pauses script execution by `backoffTime`, with an amount of
 * jitter added or subtracted from `backoffTime`.
 * @param {Number} backoffTime - number of milliseconds to wait
 * @param {Number} jitterAmount - suggested jitterAmount
 * @returns {undefined}
 */
const backoffBeforeNextAttempt = async (backoffTime, jitterAmount) => {
  logEvent(`backing off`);
  // if jitterAmount specified by user is too small, use a default starting point of
  // half of the backoff time
  if (backoffTime / jitterAmount < 2) jitterAmount = backoffTime / 2;

  jitterAmount = Math.floor(calculateJitter(jitterAmount));

  backoffTime += jitterAmount;
  backoffTime = Math.floor(backoffTime);

  logEvent(
    `${jitterAmount}ms jitter amount applied, ${backoffTime}ms total backoff time`
  );
  await sleep(backoffTime);
};

/**
 * Recalculates amount of jitter to provide a reasonable amount of variety.
 * @param {Number} jitterAmount - initial amount of jitter
 * @returns {Number} jitter after recalculation
 */
const calculateJitter = (jitterAmount) => {
  // use jitter between 50% and 150% of the original value
  jitterAmount = Math.floor(jitterAmount * Math.random());
  // on a 50% chance, reverse the sign
  if (Math.random() > 0.5) jitterAmount = -jitterAmount;
  return jitterAmount;
};

/**
 * @param {Function} operation - operation to attempt, must return a promise
 * @param {Array} backoffPeriods - array of backoff periods to wait between attempts
 * @param {Array} giveUpCriteria - array of messages upon receiving which attempts stop
 * @param {Number} jitterAmount - amount of jitter to apply to calls
 * @returns {Object} - result and the log of the operation
 */
const caller = async (
  operation,
  backoffPeriods,
  giveUpCriteria,
  jitterAmount
) => {
  eventsLog = [];
  nRetries = 0;
  const resultObject = {
    eventsLog,
    result: "",
  };

  const time = process.hrtime();
  for (let i = 0; i <= backoffPeriods.length; i++) {
    // there is no backoff for the first iteration of this loop,
    // hence why i - 1 index.
    const backoffTime = backoffPeriods[i - 1];
    try {
      logEvent(`call ${nRetries + 1} attempted...`);
      if (nRetries !== 0) {
        await backoffBeforeNextAttempt(backoffTime, jitterAmount);
      }
      const callResult = await operation();
      logEvent(`call ${nRetries + 1} successful. result: ${callResult}`);
      resultObject.result = callResult;
      break;
    } catch (rejectionMessage) {
      logEvent(`call ${nRetries + 1} failed. error: ${rejectionMessage}`);
      if (giveUpCriteria.includes(rejectionMessage)) {
        logEvent(`calling abandoned. cause:${rejectionMessage}`);
        break;
      }
      nRetries++;
    }
  }

  if (resultObject.result) {
    logEvent(`procedure successful.`);
  } else {
    resultObject.result = null;
    logEvent(`procedure failed.`);
  }

  const diff = process.hrtime(time);
  logEvent(`total time: ${diff[0]}s ${diff[1]}ns`);

  return resultObject;
};

/**
 * generates an array of `n` backoff periods as consecutive
 * powers of 2 in seconds, represented in milliseconds.
 * @param {Number} n - number of desired backoff periods
 * @returns {Array} - before mentioned array of backoff periods.
 */
const generateBackoffPeriods = (n) => {
  const backoffPeriods = [];
  for (let i = 0; i < n; i++) {
    backoffPeriods.push(2 ** i * 1000);
  }
  return backoffPeriods;
};

/**
 * returns a timestamp.
 * @returns {String}
 */
const timeStamp = () => {
  return new Date().toISOString();
};

/**
 * Logs the event, if the global module variable CONFIG.verbose is truthy,
 * also logs to stdout.
 * @param {string} eventString - the string to log.
 * @returns {undefined} no return value
 */
const logEvent = (eventString) => {
  const msg = `${timeStamp()} ${eventString}`;
  if (CONFIG.verbose) {
    console.log(`--LOG: ${msg}`);
  }
  eventsLog.push(msg);
};

module.exports.caller = caller;
module.exports.generateBackoffPeriods = generateBackoffPeriods;
