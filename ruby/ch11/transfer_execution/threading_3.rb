Thread.new do
  10.times do |i|
    print i
    $stdout.flush
    Thread.stop
  end
end

Thread.list.each { |thread| thread.run }
Thread.list.each { |thread| thread.run }
Thread.list.each { |thread| thread.run }
Thread.list.each { |thread| thread.run }
Thread.list.each { |thread| thread.run }
