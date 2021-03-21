non_blocking = Fiber.new(blocking: false) do
  puts Fiber.methods.sort
  puts "Blocking Fiber? #{Fiber.current.blocking?}"

  # Will not block
  sleep 2
end

3.times { puts non_blocking.resume }
