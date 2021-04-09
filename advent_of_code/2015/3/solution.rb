require 'set'

input = File.read('./input_gh.txt')

# there are two 'drivers' now delivering packages - santa, and robo-santa
# they both have a position, but we can still assume that they're just cool with having one houses_visited slot

positions = [[0, 0], [0,0]]
houses_visited = Set.new

def visit_house(driver_index, houses_visited, positions)
  houses_visited << "#{positions[driver_index][0]}:#{positions[driver_index][1]}"
end

def move(char, driver_index, positions)
  if char == 'v'
    positions[driver_index][0] -= 1
  elsif char == '^'
    positions[driver_index][0] += 1
  elsif char == '>'
    positions[driver_index][1] += 1
  elsif char == '<'
    positions[driver_index][1] -= 1
  end
end

visit_house(0, houses_visited, positions)
visit_house(1, houses_visited, positions)

input.each_char.with_index do |char, i|
  move(char, i % 2, positions)
  visit_house(i % 2, houses_visited, positions)
end


p positions
p houses_visited.size