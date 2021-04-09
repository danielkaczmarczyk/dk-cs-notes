# a quick win to make this more optimised is to
# rewrite the checkers to check for both properties during 
# a single run-through the string

input = File.readlines 'input.txt'
require 'set'

def is_nice?(string)
end

def check_first_property(string)
  i = 0
  j = 2
  while i <= string.size - 2
    substring = string[i..j-1]
    while j <= string.size - 2
      substring_two = string[j..j+1]
      if substring == substring_two
        return true
      end
      j += 1
    end
    i += 1
    j = i + 2
  end
  false
end

def check_second_property(string)
  i = 0

  while i <= string.size - 3
    if string[i] == string[i + 2] 
      return true
    end
    i += 1
  end
  false
end

strings= [
  'qjhvhtzxzqqjkmpb',
  'xxyxx',
  'uurcxstgmygtbstg',
  'ieodomkazucvgmuy',
]

count = 0
input.each do |string|
  if check_first_property(string) and check_second_property(string)
    count += 1
  end
end
puts count