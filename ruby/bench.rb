require 'benchmark'

def v1
  puts Benchmark.measure { 10_000.times { print "." } }
end

def v2
  iterations = 1_000_000_000

  b = Benchmark.measure do
    for i in 1..iterations
      x = i
    end
  end

  c = Benchmark.measure do
    iterations.times do |i|
      x = i
    end
  end

  puts b
  puts c
end

def v3
  iterations = 1_000_000
  Benchmark.bm do |bm|
    bm.report("for:  ") do
      for i in 1..iterations
        x = i
      end
    end

    bm.report("times:") do
      iterations.times do |i|
        x = i
      end
    end
  end
end

v3
