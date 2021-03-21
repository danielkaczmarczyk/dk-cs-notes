ls = IO.popen("ls", "r")
while line = ls.gets
  puts line
end
ls.close
