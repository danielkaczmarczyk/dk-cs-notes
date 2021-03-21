sg = Fiber.new do
  s = 0
  loop do
    square = s * s
    s += 1
    s = Fiber.yield(square) || s
  end
end

puts sg.resume
puts sg.resume
puts sg.resume
puts sg.resume
puts sg.resume
puts sg.resume 50
puts sg.resume
puts sg.resume
puts sg.resume 0

