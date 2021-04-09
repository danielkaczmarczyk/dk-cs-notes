input = 'bgvyzdsv'
n = 0
require 'digest'

while true
  hash = Digest::MD5.new
  hash.update "#{input}#{n.to_s}"
  puts hash.to_s
  if hash.to_s.start_with? '00000'
    puts "We found n: #{n}"
    break
  end
  n += 1
end