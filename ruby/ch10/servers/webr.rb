require 'webrick'

server = WEBrick::GenericServer.new( :Port => 1234 )

trap("INT") { server.shutdown }

server.start do |socket|
  socket.puts "hello world. thank you for visiting my server"
  socket.puts Time.now
  socket.puts "Goodbye"
end
