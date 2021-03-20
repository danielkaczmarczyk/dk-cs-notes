class Person
end

def add_accessor_to_person(accessor_name)
  Person.class_eval %{
    attr_accessor :#{accessor_name}
  }
end

person = Person.new
add_accessor_to_person :name
add_accessor_to_person :gender

person.name = "Carleton DiLeo"
person.gender = "male"

puts "#{person.name} is #{person.gender}"

