# idea for making it better: do not use an array of arrays
# use a single array representing the lights and modulo arithmetic to access indexes in O(1)
instructions = File.readlines('./input.txt')

def create_grid(grid_size=1000)
  grid = Array.new

  grid_size.times do 
    grid << []
  end

  grid_size.times.with_index do |i|
    grid_size.times do 
      grid[i] << 0
    end
  end
  grid
end

def parse_instruction(inst)
  inst.match(/(?<instruction>[a-z\s]+)(?<x1>\d+),(?<y1>\d+)(?<thru>[a-z\s]+)(?<x2>\d+),(?<y2>\d+)/).named_captures
end

def turn_on(x, y)
  $grid[x][y] += 1
end

def turn_off(x, y)
  if $grid[x][y] >= 1
    $grid[x][y] -= 1
  end
end

def toggle(x, y)
  $grid[x][y] += 2
end

def act(x1, y1, x2, y2, action)
  #p "acting. #{action} on #{x1},#{y1} #{x2},#{y2}"
  (x1..x2).to_a.each do |n|
    (y1..y2).to_a.each do |m|
      method(action).call(n, m)
    end
  end
end

# ----------------------------------

$grid = create_grid

# instructions = [
#   'turn on 0,0 through 9,9',
#   'turn off 0,0 through 5,5',
#   'toggle 5,5 through 7,7',
#   'toggle 3,3 through 9,9',
# ]

instructions.each_with_index do |ins, idx|
  i = parse_instruction ins
  method = i["instruction"].strip.gsub(' ', '_').to_sym
  act(i['x1'].to_i, i['y1'].to_i, i['x2'].to_i, i['y2'].to_i, method)
  if idx % 10 == 0
    puts "#{idx}/#{instructions.size}"
  end
end

puts $grid.flatten.sum

# $grid.each do |g|
#   p g
# end