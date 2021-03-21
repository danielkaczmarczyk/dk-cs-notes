if fork.nil?
  exec "ruby a.rb"
end
puts "This Ruby script now runs alongside a.rb"
