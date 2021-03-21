input = File.read('input_gh.txt')
#input = input[0..20]

floor = 0
index = 0

input.each_char do |char|
  puts "#{floor} #{index} #{char}"
  break if floor == -1
  if char == '('
    floor += 1
  elsif char == ')'
    floor -= 1
  end
  if floor == -1
    break
  end
  index += 1
end
puts floor, index
