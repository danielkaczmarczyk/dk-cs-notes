# 1. create a hash with the 'definitions'

input = File.readlines('./test_input.txt')
$answers = File.readlines('./test_output.txt')

$wires = {}

input.each do |line|
  wire_data = line.split('->').map { |str| str.strip }
  $wires[wire_data[1]] = wire_data[0]
end



#2 resolve a value by jumping around the hash

# if it resolves to a integer, that's your value.
# if it doesn't resolve to an integer, it means it's not yet fully resolved
# it may have 2-3 tokens to be parsed
  # if it's 2, then it's a binary operation and we perform it and we're done
  # if it's 3, we provide the _same_ method of resolution we did in the original mode - just call upon this recursively

def remap(operation)
  # p "input to remap: #{operation}"
  ops = {
    "LSHIFT": "<<",
    "RSHIFT": ">>",
    "AND": "&",
    "OR": "|",
  }
  ops[operation.to_sym]
end

def resolve(string)
  # puts "input: #{string}"
  split_string = string.split(' ')
  size = split_string.size

  if size == 1
    begin
      Integer(string)
    rescue
      # puts 'in the rescue clause'
      # puts "$wires:[string]: #{$wires[string]}"
      return Integer($wires[string])
    end
  elsif size == 2
    # that's the NOT case
    #puts "in the size==2 case. split_string:#{split_string}"
    #return ~resolve(split_string[1])
    return 65535 - resolve(split_string[1])
  elsif size == 3
    # that's the <VAR> <OPERAND> <VAR> case.
    # basically I need to make some recursive calls and when they both
    # resolve, I need to perform the actual operation.
    #p "#{resolve(split_string[0])} #{remap(split_string[1])} #{resolve(split_string[2])}"
    return eval "#{resolve(split_string[0])} #{remap(split_string[1])} #{resolve(split_string[2])}"
  end
end

def test_input_cases
  pp $wires
  pp $answers
  puts ""

  print('d: ')
  p resolve $wires['d']
  print('e: ')
  p resolve $wires['e']
  print('f: ')
  p resolve $wires['f']
  print('g: ')
  p resolve $wires['g']
  print('h: ')
  p resolve $wires['h']
  print('i: ')
  p resolve $wires['i']
  print('x: ')
  p resolve $wires['x']
  print('y: ')
  p resolve $wires['y']
end
#test_input_cases