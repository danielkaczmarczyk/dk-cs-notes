require 'set'

input = File.read('./input_gh.txt')

position = [0, 0]
houses_visited = Set.new

houses_visited << "#{position[0]}:#{position[1]}"

input.each_char do |char|
  if char == 'v'
    position[0] -= 1
  elsif char == '^'
    position[0] += 1
  elsif char == '>'
    position[1] += 1
  elsif char == '<'
    position[1] -= 1
  end
  houses_visited << "#{position[0]}:#{position[1]}"
end


p position
p houses_visited.size