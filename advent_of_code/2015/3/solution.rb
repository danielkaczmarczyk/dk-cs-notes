class Solver
  def initialize(file_location, mode='')
    @input = File.read(file_location)
    @santa_position = [0, 0]
    @houses_visited = {}

    if mode == 'dev'
      self.trim_input
    end
  end

  def trim_input(bound_a=0, bound_b=0)
    @input = @input[bound_a..bound_b]
  end

  def act(char)
    if char == 'v'
      @santa_position[1] -= 1
    elsif char == '^'
      @santa_position[1] += 1
    elsif char == '>'
      @santa_position[0] += 1
    elsif char == '<'
      @santa_position[0] -= 1
    end
  end

  def deliver_present
    puts @santa_position
  end

  def solve
    print @santa_positionA
    self.deliver_present
    @input.each_char do |char|
      p char
      self.act char
      self.deliver_present
      print @santa_position
    end
    puts ''
    puts @houses_visited
  end
end

solver = Solver.new 'input_gh.txt', 'dev'
solver.solve
