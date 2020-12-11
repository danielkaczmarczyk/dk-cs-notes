const fs = require("fs");

const readFile = (path) => {
  return new Promise((resolve, reject) => {
    const handler = (err, data) => {
      if (err) reject(err);
      resolve(data);
    };
    fs.readFile(path, "utf8", handler);
  });
};

module.exports = readFile;
