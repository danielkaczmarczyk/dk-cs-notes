class Present
  def initialize(size_string)
    puts size_string
  end

  def self.parse_bulk(sizes_array)
    sizes_array.each do |size|
      puts size
    end
  end
end

class Main
  def self.run
    input = File.readlines('input_gh.txt')
    input = input[..-2] # cut off the last empty line 
    input = input[0..5] # cut down on input size for debugging brevity
    Present.parse_bulk input
  end
end

Main::run
