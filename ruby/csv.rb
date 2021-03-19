require 'csv'

people = CSV.read('text.csv')
young_people = people.find_all do |p|
  p[3].to_i.between?(20,40)
end

CSV.open("results.csv", "w") do |csv|
  young_people.each do |person|
    csv << person
  end
end
