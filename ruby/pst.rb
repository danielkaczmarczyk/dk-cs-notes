class Person
  attr_accessor :name, :job, :gender, :age
end

fred = Person.new
fred.name = "Fred Bloggs"
fred.age = 45

laura = Person.new
laura.name = "Laura Smith"
laura.age = 23

require 'pstore'
store = PStore.new("storagefile")

def store_people
  store.transaction do
    store[:people] ||= Array.new
    store[:people] << fred
    store[:people] << laura
  end
end

def retrieve_people
  store = PStore.new("storagefile")
  people = []

  store.transaction do
    people = store[:people]
  end

  people.each do |person|
    puts person.name
  end
end

retrieve_people
