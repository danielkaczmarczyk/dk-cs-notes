/*
 * the input is in the format of
 * lxwxh
 * where l is length, w is width, and h is height.
 * surface area of the box is 2*l*w + 2*w*h + 2*h*l
 * every box needs an extra of the smallest side too
 * question: how many total sq ft of wrapping paper should they order?
 *
 * the input file is only 1k lines long, 7.9K big, thus no need to use streams
 *
 * after solving it I realised I could have used a re for the whole file -
 * it makes turning it into array, and clearning unnecessary - could have been
 * a series of matches.
 */

const fs = require("fs");

const getBoxSizes = () => {
  return new Promise((resolve, reject) => {
    const parseBoxSizesFile = (err, data) => {
      if (err) reject(err);
      resolve(data);
    };
    fs.readFile(`${__dirname}/input.txt`, "utf8", parseBoxSizesFile);
  });
};

/**
 * @param {String} boxSizeString
 * @returns {Object} containing three keys, l,h, and w, as ints
 */
const parseBoxSizeString = (boxSizeString) => {
  const sizeStringRe = /^(?<l>\d+)x(?<w>\d+)x(?<h>\d+)$/;
  const boxSizes = sizeStringRe.exec(boxSizeString).groups;
  for (let entry in boxSizes) {
    boxSizes[entry] = parseInt(boxSizes[entry], 10);
  }
  return boxSizes;
};

/**
 *
 * @param {Object} boxSizes
 * @returns {Number} amount of square feet needed for the wrapping
 */
const calculateAmountOfPaperNeeded = (boxSizeString) => {
  const boxSizes = parseBoxSizeString(boxSizeString);
  const { l, h, w } = boxSizes;
  const side1Surface = 2 * l * w;
  const side2Surface = 2 * h * w;
  const side3Surface = 2 * l * h;

  const surfaces = [side1Surface, side2Surface, side3Surface];
  surfaces.sort((a, b) => a - b);
  surfaces.push(surfaces[0] / 2); // add slack
  const totalPaperNeeded = surfaces.reduce(
    (acc, currentVal) => acc + currentVal,
    0
  );
  return totalPaperNeeded;
};

const calculateRibbonLength = (boxSizeString) => {
  const boxSizes = parseBoxSizeString(boxSizeString);
  const boxSizesAsArray = [];
  for (const size of Object.values(boxSizes)) {
    boxSizesAsArray.push(size);
  }
  let ribbonLength = 0;
  boxSizesAsArray.sort((a, b) => a - b);

  // the wrap-around
  for (let i = 0; i <= 1; i++) {
    ribbonLength += boxSizesAsArray[i] * 2;
  }

  // the bow
  let bowBit = boxSizesAsArray[0];
  for (let i = 1; i <= 2; i++) {
    bowBit *= boxSizesAsArray[i];
  }

  ribbonLength += bowBit;
  return ribbonLength;
};

const solve = async () => {
  const boxSizes = await getBoxSizes();
  let boxSizesArray = boxSizes.split("\n");
  boxSizesArray = boxSizesArray.filter((bs) => Boolean(bs));
  let totalFeetOfWrappingPaper = 0;
  let totalFeetOfRibbon = 0;
  for (let boxSize of boxSizesArray) {
    totalFeetOfWrappingPaper += calculateAmountOfPaperNeeded(boxSize);
    totalFeetOfRibbon += calculateRibbonLength(boxSize);
  }
  console.log(
    `The elves need ${totalFeetOfWrappingPaper} ft of wrapping paper, and ${totalFeetOfRibbon} ft of ribbon.`
  );
  return totalFeetOfWrappingPaper;
};

solve();
