require 'yaml'

class Person
  attr_accessor :name, :age
end

def yamlize
  fred = Person.new
  fred.name = "Fred Bloggs"
  fred.age = 45

  laura = Person.new
  laura.name = "Laura Briggs"
  laura.age = 23

  test_data = [fred, laura]

  puts test_data.to_yaml
end

def load_yaml
  yaml_string = <<END_OF_DATA
---
- !ruby/object:Person
  age: 45
  name: Jimmy
- !ruby/object:Person
  age: 23
  name: Lora Smoth
END_OF_DATA

  test_data = YAML.load(yaml_string)
  puts test_data[1].name
end

load_yaml
