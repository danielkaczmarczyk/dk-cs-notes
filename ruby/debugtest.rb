i = 1
j = 0
until i > 1_000_000
  i *= 2
  j += 1
  puts "i = #{i}, j = #{j}"
end

