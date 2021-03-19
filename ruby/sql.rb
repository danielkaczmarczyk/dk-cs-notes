require 'sqlite3'

def test
  puts "It's all ok" if defined?(SQLite3::Database)
end

def init
  $db = SQLite3::Database.new("dbfile")
  $db.results_as_hash = true
end 

def disconnect_and_quit
  $db.close
  puts "bye! database closed."
  exit
end

def create_table
  puts "creating people table"
  $db.execute %q{
    CREATE TABLE if not exists people (
      id integer primary key,
      name varchar(50),
      job varchar(50),
      gender varchar(6),
      age integer
    )
  }
end

def add_person
  puts "enter name:"
  name = gets.chomp
  puts "enter job:"
  job = gets.chomp
  puts "enter gender:"
  gender = gets.chomp
  puts "enter age"
  age = gets.chomp
  $db.execute("INSERT INTO people (name, job, gender, age) VALUES (?, ?, ?, ?)", name, job, gender, age)
end

def find_person
  puts "Enter name or ID of person to find:"
  id = gets.chomp

  person = $db.execute("select * from people where name = ? or id = ?", id, id.to_i).first

  unless person
    puts "no result found"
    return
  end

  puts %Q{Name: #{person['name']}
Job: #{person['job']}
Gender: #{person['gender']}
Age: #{person['age']}
  }
end

init
create_table
find_person
disconnect_and_quit
