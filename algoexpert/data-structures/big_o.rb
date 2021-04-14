def f1(a)
  1 + a[0]
end

def f2(a)
  sum = 0
  a.each { |int| sum += int }
  sum
end

def f3(a)
  pairs = []
  a.each do |int_1|
    a.each do |int_2|
      pairs << [int_1, int_2]
    end
  end
  pairs
end

array = Array.new(1_000, 1)

require 'benchmark'

Benchmark.bm do |x|
  x.report { f1(array) }
  x.report { f2(array) }
  x.report { f3(array) }
end
