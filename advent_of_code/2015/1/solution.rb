input_string = File.read('input_gh.txt')

### Part 1
floor = 0

input_string.each_char do |char|
  if char == '('
    floor += 1
  elsif char == ')'
    floor -= 1
  end
end
puts floor

# cool solution #1
puts eval(input_string.gsub('(', '+1').gsub(')', '-1'))

# cool solution #2
puts eval(input_string.strip.gsub(/\W/) { |char| char == '(' ? '+1' : '-1' })