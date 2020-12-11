const readFile = require('../../utils/readFile');

// not a good solution. incorrect, in the state it is now, and also very wet. 
// parking it for the day

const validate = (passport, field, predicate) => {
  if (!passport[field]) return;
  const value = passport[field].value;
  const validationResult = predicate(value);
  if (validationResult) {
    passport[field].valid = true;
  }
}

// really not dry here. instead of composing those functions, I practiced yanking in vim.
const validateBirthYear = (year) => {
  if (year >= 1920 && year <= 2002) return true;
  return false;
}

const validateIssueYear = (year) => {
  if (year >= 2010 && year <= 2020) return true;
  return false;
}

const validateExpirationYear = (year) => {
  if (year >= 2020 && year <= 2030) return true;
  return false;
}

const validateHeight = (height) => {
  const re = /(?<num>\d+)(?<unit>[a-z]+)/g;
  const match = re.exec(height);
  if (match === null) {
    return false;
  }
  let {num, unit} = match.groups;
  num = parseInt(num, 10);
  if (unit === 'in') {
    if (num >= 59 && num <= 76) return true;
    return false;
  } else if (unit === 'cm') {
    if (num >= 150 && num <= 193) return true;
    return false;
  }
}

const validateHairColor = (hairColor) => {
  const re = /#[a-f|0-9]+/g;
  const match = re.exec(hairColor);
  if (match) return true;
  return false;
}

const validateEyeColor = (eyeColor) => {
  const validColors = 'amb blu brn gry grn hzl oth'.split(' ');
  if (validColors.includes(eyeColor)) return true;
  return false;
}

const validatePassportId = (pid) => {
  const re = /^\d{9}$/g;
  const match = re.exec(pid);
  if (match) return true;
  return false;
}

const solve = async () => {
  let input = await readFile('./input.txt');
  input = input.split('\n');

  const time = process.hrtime();
  const passports = [];
  let tempPassport = '';
  let validPassports = 0;

  for (line of input) {
    if (line !== '') {
      tempPassport += ` ${line}`;
    } else {
      passports.push(tempPassport);
      tempPassport = '';
    }
  }

  const re = /(?<key>\w{3}):(?<val>[\w+|#]+)/g
  for (passport of passports) {
    const passportObject = {};

    const passportData = [...passport.matchAll(re)]
      .map(match => match.groups)
      .forEach(kvPair => {
        passportObject[kvPair.key] = { value: kvPair.val, valid: false };
      })

    const keys = Object.keys(passportObject);
    passportObject.n = keys.length;

    if (keys.length === 8) passportObject.validate = true;
    if (keys.length === 7 && !keys.includes('cid')) passportObject.validate = true;

    // validations
    // WET
    validate(passportObject, 'byr', validateBirthYear);
    validate(passportObject, 'iyr', validateIssueYear);
    validate(passportObject, 'eyr', validateExpirationYear);
    validate(passportObject, 'hgt', validateHeight);
    validate(passportObject, 'hcl', validateHairColor);
    validate(passportObject, 'ecl', validateEyeColor);
    validate(passportObject, 'pid', validatePassportId);

    passportObject.valid = true;
    for (field in passportObject) {
      if (passportObject[field].valid === false) passportObject.valid = false;
    }

    if (passportObject.valid === true) validPassports++;
    console.log(passportObject);
  }
  
  console.log(`we've got ${validPassports} valid passports.`);
  const diff = process.hrtime(time);
  const nanoseconds = diff[0] * 1e9 + diff[1];
  console.log(`\nCompleted in: ${nanoseconds * 1e-6} ms`);
}

solve();

