sg = Fiber.new do
  s = 0
  loop do
    s += 10
    if s < 100
      message = "S is less than 100! #{s}"
      Fiber.yield message
    else
      Fiber.yield "FUCK"
    end
  end
end

15.times { puts sg.resume }
