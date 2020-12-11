const {
  act,
  applyInstructions,
  countOn,
  createGrid,
  parseInstructions,
} = require("./solution2.js");

describe("createGrid", () => {
  test("is defined", () => {
    expect(createGrid).toBeDefined();
  });

  describe("creates a grid correctly", () => {
    test("of 0 squares", () => {
      const grid = createGrid(0);
      expect(grid).toEqual([]);
    });

    test("of 1 square", () => {
      const grid = createGrid(1);
      expect(grid).toEqual([[0]]);
    });

    test("of 3 squares", () => {
      const grid = createGrid(3);
      const expectedGrid = [
        [0, 0, 0],
        [0, 0, 0],
        [0, 0, 0],
      ];
      expect(grid).toEqual(expectedGrid);
    });
  });
});

describe("parseInstructions", () => {
  test("is defined", () => {
    expect(parseInstructions).toBeDefined();
  });

  test("correctly parses the input string", () => {
    const inputString = "turn on 119,486 through 246,900";
    const instructions = parseInstructions(inputString);

    expect(instructions.start.x).toBe(119);
    expect(instructions.start.y).toBe(486);
    expect(instructions.end.x).toBe(246);
    expect(instructions.end.y).toBe(900);
  });
});

describe("applyInstructions", () => {
  test("is defined", () => {
    expect(applyInstructions).toBeDefined();
  });

  describe("correctly applies the instruction to", () => {
    test("turn on the lights", () => {
      const grid = createGrid(3);
      const instructionsString = "turn on 0,0 through 1,1";
      const instructions = parseInstructions(instructionsString);
      applyInstructions(grid, instructions);

      const expectedGrid = [
        [1, 1, 0],
        [1, 1, 0],
        [0, 0, 0],
      ];

      expect(grid).toEqual(expectedGrid);
    });

    test("turn off the lights", () => {
      const grid = [
        [1, 1, 0],
        [1, 1, 0],
        [0, 0, 0],
      ];

      const instructionsString = "turn off 1,1 through 2,2";
      const instructions = parseInstructions(instructionsString);
      applyInstructions(grid, instructions);

      const expectedGrid = [
        [1, 1, 0],
        [1, 0, 0],
        [0, 0, 0],
      ];

      expect(grid).toEqual(expectedGrid);
    });

    test("toggle the lights", () => {
      const grid = [
        [1, 1, 0],
        [1, 1, 0],
        [0, 0, 0],
      ];

      const instructionsString = "toggle 0,0 through 2,2";
      const instructions = parseInstructions(instructionsString);
      applyInstructions(grid, instructions);

      const expectedGrid = [
        [3, 3, 2],
        [3, 3, 2],
        [2, 2, 2],
      ];

      expect(grid).toEqual(expectedGrid);
    });
  });
});

describe("act", () => {
  test("is defined", () => {
    expect(act).toBeDefined();
  });

  describe("works correctly when", () => {
    describe("the instruction is", () => {
      describe("turn on", () => {
        test("and the input is 0", () => {
          expect(act(0, "turn on")).toBe(1);
        });
        test("and the input is 1", () => {
          expect(act(1, "turn on")).toBe(2);
        });
      });
      describe("turn off", () => {
        test("and the input is 0", () => {
          expect(act(0, "turn off")).toBe(0);
        });
        test("and the input is 1", () => {
          expect(act(1, "turn off")).toBe(0);
        });
      });
      describe("toggle", () => {
        test("and the input is 0", () => {
          expect(act(0, "toggle")).toBe(2);
        });
        test("and the input is 1", () => {
          expect(act(1, "toggle")).toBe(3);
        });
      });
    });
  });
});

describe('countOn', () => {
  test('is defined', () => {
    expect(countOn).toBeDefined();
  });

  test('counts the lights that are on correctly', () => {
    const grid = [
        [1, 1, 0],
        [1, 1, 0],
        [0, 0, 0],
      ];

    expect(countOn(grid)).toBe(4);
  })
});
