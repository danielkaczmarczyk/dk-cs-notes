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
      puts "#{substring} #{substring_two}"
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

strings= [
  'qjhvhtzxzqqjkmpb',
  'xxyxx',
  'uurcxstgmygtbstg',
  'ieodomkazucvgmuy',
]

require 'pry'; binding.pry

count = 0
strings.each do |string|
  count += 1 if is_nice? string
end
puts count