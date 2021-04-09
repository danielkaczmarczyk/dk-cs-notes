input = 'bgvyzdsv'
n = 0
require 'digest'

while true
  hash = Digest::MD5.new
  hash.update "#{input}#{n.to_s}"
  puts hash.to_s
  # the only difference between pt 1 and pt2 is the number of zeroes
  if hash.to_s.start_with? '000000'
    puts "We found n: #{n}"
    break
  end
  n += 1
end