# v 0.0.1 - no refactors or optimizations yet
require 'byebug'

input = File.readlines('./input.txt')
$answers = File.readlines('./test_output.txt')

$wires = {}

input.each do |line|
  wire_data = line.split('->').map { |str| str.strip }
  $wires[wire_data[1]] = wire_data[0]
end

def remap(operation)
  ops = {
    "LSHIFT": "<<",
    "RSHIFT": ">>",
    "AND": "&",
    "OR": "|",
  }
  ops[operation.to_sym]
end

$count = 0
def resolve(string, previous=nil)
  throw "the input was NIL buddy" if string.nil?

  $count += 1
  print "___#{$count} "
  puts "input to resolve: #{string}"

  if string.is_a? Integer
    return string
  end

  split_string = string.split(' ')
  size = split_string.size

  if size == 1
    begin
      num = Integer(string)
      return num
    rescue
      num = resolve($wires[string], string)
      $wires[string] = num
      return num
    end
  elsif size == 2
    num = 65535 - resolve(split_string[1])
    $wires[previous] = num
    return num
  elsif size == 3
    num = eval "#{resolve(split_string[0])} #{remap(split_string[1])} #{resolve(split_string[2])}"
    $wires[previous] = num
    return num
  end
end

p resolve 'a'

