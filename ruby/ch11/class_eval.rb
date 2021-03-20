class Class
  def addz
    puts 'addz'
  end
  def add_accessor(accessor_name)
    self.class_eval %{
      attr_accessor :#{accessor_name}
    }
  end
end

class Person
end

person = Person.new
Person.add_accessor :name
Person.add_accessor :gender
Person.addz
person.name = "Daniel Kaczmarczyk"
person.gender = "male"

puts "#{person.name} is #{person.gender}"
