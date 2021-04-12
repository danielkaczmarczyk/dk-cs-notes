# v.0.0.1 - just works, no improvements or optimizations.

filename = './input.txt'
data = File.read filename

raw_count = 0

data.each_char do |char|
  if char == "\n"
  else
    raw_count += 1
  end
end

puts "raw_count: #{raw_count}"

data_by_lines = File.readlines filename
data_by_lines = data_by_lines[0..-2]

normal_count = 0
data_by_lines.each do |line|
  size = (eval line).size
  normal_count += size
end

puts "normal_count: #{normal_count}"
diff = raw_count - normal_count
puts "result: #{diff}"
