instructions = File.readlines('./input.txt')[0..10]

def parse_instruction(inst)
  inst.match(/(?<instruction>[a-z\s]+)(?<x1>\d+),(?<y1>\d+)(?<thru>[a-z\s]+)(?<x2>\d+),(?<y2>\d+)/).named_captures
end

instructions.each do |instruction|
  p instruction
  p parse_instruction(instruction)
  puts  ""
end