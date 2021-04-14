# constant time - O(1)
def f1(a)
  1 + a[0]
end

# linear time - O(n)
def f2(a)
  sum = 0
  a.each { |int| sum += int }
  sum
end

# quadratic time O(n^2)
def f3(a)
  pairs = []
  a.each do |int_1|
    a.each do |int_2|
      pairs << [int_1, int_2]
    end
  end
  pairs
end

array = Array.new(4_000, 1)

require 'benchmark'

puts "Array of size: #{array.size}"
Benchmark.bm do |x|
  x.report { f1(array) }
  x.report { f2(array) }
  x.report { f3(array) }
end
