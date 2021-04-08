const { caller, generateBackoffPeriods } = require("./caller");
const { callMockServer } = require("./mockServer");

const simulate = async () => {
  const message = "\nStart simulating the exponential backoff procedure";
  console.log(message);
  console.log(`-`.repeat(message.length));

  // config the caller
  const backoffPeriods = generateBackoffPeriods(4);
  const giveUpCriteria = ["<JAM>", "<TRAGIC_FAILURE>"];
  const jitterAmount = 500;

  // initiate procedure
  const result = await caller(
    callMockServer,
    backoffPeriods,
    giveUpCriteria,
    jitterAmount
  );
  console.log(result);
  console.log(`End of the exponential backoff procedure simulation\n`);
};

simulate();
