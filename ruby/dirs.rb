puts Dir.pwd
puts Dir[Dir.pwd.to_s]
Dir.chdir("/usr/bin")
puts Dir.pwd

