def break_this
  10 / 0
end

def breakable
  begin
    break_this
  rescue => e
    puts "#{e.class}"
    puts "#{e}"
  end
end

class Person
  def initialize(name)
    raise ArgumentError, "No name present" if name.empty?
  end
end

def breakable_person
  daniel = Person.new
end

def ca_fi
  catch(:finish) do
    1000.times do
      x = rand(1000)
      puts x
      throw :finish if x == 123
    end

    puts "Generated 1000 random numbers without generating 123!"
  end
end

def generate_random_number_except_123
  x = rand(1000)
  print "#{x} "
  throw :finish if x > 123 && x < 200
end

catch(:finish) do
  1000.times { generate_random_number_except_123 }
  puts "Generated 1000 random numbers without generating 123!"
end
