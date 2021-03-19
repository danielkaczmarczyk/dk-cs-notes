def v1
  a = gets
  puts a
end

def v2
  lines = readlines
  puts lines
end

def v3(filename)
  File.open(filename).each { |line| puts line }
end

def v4
  File.new('text.txt', 'r').each { |line| puts line }
end

class MyFile
  attr_reader :handle

  def initialize(filename)
    @handle = File.new(filename, "r")
  end

  def finished
    @handle.close
  end
end

def v5
  f = MyFile.new("text.txt")
  puts f.handle.readlines
  f.finished
end

def v6
  File.open("text.txt").each_char { |line| puts line }
end

def v7
  File.open('text.txt') do |f|
    12.times { puts f.gets }
  end
end

def v8
  File.open('text.txt') do |f|
    22.times { puts f.getc }
  end
end

def v9
  puts File.open("text.txt").readlines.join("--")
end

def v10
  f = File.open("text.txt")
  f.pos = 15
  puts f.gets
  puts f.pos
end

def v11
  File.open("text.txt", "w") do |f|
    10.times { f.puts rand(1000) }
  end

  puts File.read("text.txt")
end

def log1
  f = File.new("logfile.txt", "a")
  f.puts Time.now
  f.close
end

def log2
  f = File.open("text.txt", "r+")
  puts f.gets
  f.puts "This is a test"
  puts f.gets
  f.close
end

log2
