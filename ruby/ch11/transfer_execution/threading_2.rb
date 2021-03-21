threads = []

10.times do
  thread = Thread.new do
    puts "List of threads: #{Thread.list}"  
    10.times { |i| print i; $stdout.flush; sleep rand(2) }
  end

  threads << thread
end

threads.each do |thread|
  puts "Thread #{thread.object_id} didn't finish in 1s" unless thread.join(1)
end
