
presents = File.readlines('./input_gh.txt')

total_ribbon = 0

presents.each do |present|
  p present.split("x").map(&:to_i)
end