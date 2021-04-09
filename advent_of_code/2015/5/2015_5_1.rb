input = File.readlines 'input.txt'
require 'set'

def is_nice?(string)
  bad_strings = ['ab', 'cd', 'pq', 'xy']
  bad_strings.each do |bs|
    return false if string.include? bs
  end

  requirements = [false, false]

  no_of_vowels = string.count 'aeiou'
  requirements[0] = true if no_of_vowels >= 3

  double_strings = Set.new(string.split("")).to_a.map {|l| "#{l}#{l}"}
  double_strings.each do |ds|
    if string.include? ds
      requirements[1] = true
      break
    end
  end

  requirements[0] && requirements[1]
end

strings= [
  'ugknbfddgicrmopn',
  'aaa',
  'jchzalrnumimnmhp',
  'haegwjzuvuyypxyu',
  'dvszwmarrgswjxmb'
]

strings.map! {|s| is_nice?(s)}

count = 0
input.each do |string|
  count += 1 if is_nice? string
end
puts count