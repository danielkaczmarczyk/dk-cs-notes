class Present
  @@all = []

  def self.all
    @@all
  end

  def initialize(size_string)
    @size_string = size_string.strip
    self.parse_size
    self.calculate_area
    @@all << self
  end

  def to_s
    "P> dim:#{@size_string} s_a:#{@size_array.to_s} area:#{@area} "
  end

  def self.parse_bulk(sizes_array)
    sizes_array.each do |size|
      Present.new size
    end
  end

  def parse_size
    @size_array = @size_string.strip.split('x').map { |n| n.to_i }.sort
  end

  def calculate_area
    sa = @size_array
    @area = 2 * ((sa[0] * sa[1]) + (sa[1] * sa[2]) + (sa[2] * sa[0]))
    @area += self.calculate_shortest_side_area
    @area
  end

  def calculate_shortest_side_area
    @size_array[0] * @size_array[1]
  end
end

class Main
  def self.run
    input = File.readlines('input_gh.txt')[..-2] # cut off the last empty line
    input = input[0..5] # cut down on input size for debugging brevity
    Present.parse_bulk input
  end
end

Main::run
puts Present.all

