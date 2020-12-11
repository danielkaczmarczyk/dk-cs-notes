const readFile = require('../../utils/readFile');

const solve = async () => {
  let input = await readFile('./input.txt');
  input = input.split('\n');

  const time = process.hrtime();
  const passports = [];
  let tempPassport = '';
  let validPassports = 0;

  const requiredFields = ['byr', 'iyr', 'eyr', 'hgt', 'hcl', 'ecl', 'pid', 'cid'];

  for (line of input) {
    if (line !== '') {
      tempPassport += ` ${line}`;
    } else {
      passports.push(tempPassport);
      tempPassport = '';
    }
  }

  for (passport of passports) {
    let cidPresent = false;
    let validFields = 0;
    let p = passport.split(':')
    p = p.map(str => str.slice(str.length - 3))
    passportSliced = p.slice(0, p.length - 1);

    for (let i = 0; i < passportSliced.length; i++) {
      let field = passportSliced[i];
      if (field === 'cid') cidPresent = true;
      if (requiredFields.includes(field)) validFields++;
    }

    /*
     * the passport is valid if:
     * there are 8 fields present
     * if there are 7, the field 'cid' is not present
     */

    if (validFields === 8) validPassports++;
    if (validFields ===7 && !cidPresent) validPassports++;

    console.log(passport);
    console.log(validFields);
    console.log('-'.repeat(12));
  }

  console.log(validPassports);

  const diff = process.hrtime(time);
  const nanoseconds = diff[0] * 1e9 + diff[1];
  console.log(`\nCompleted in: ${nanoseconds * 1e-6} ms`);
}

solve();

