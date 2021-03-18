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
  File.open("text.txt").each { |line| puts line }
end

v6
