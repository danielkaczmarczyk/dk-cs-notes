const { findValue, parseInstruction } = require('./solution');

const input = [
  "123 -> x",
  "456 -> y",
  "x AND y -> d",
  "x OR y -> e",
  "x LSHIFT 2 -> f",
  "y RSHIFT 2 -> g",
  "NOT x -> h",
  "NOT y -> i",
];

describe('wires', () => {
  describe('findValue', () => {
   describe('finds the basic value of', () => {
     test('x', () => {
//       expect(findValue('x')).toBe(123);
     });
    });
  });

  describe('parseInstruction', () => {
    describe('correctly parses', () => {
      test('value for x', () => {
        expect(parseInstruction(input[0])).toBe('x = 123');
      });
      test('value for y', () => {
        expect(parseInstruction(input[1])).toBe('y = 456');
      });
      test('value for d', () => {
        expect(parseInstruction(input[2])).toBe('d = x & y')
      });
    });
  });
})

