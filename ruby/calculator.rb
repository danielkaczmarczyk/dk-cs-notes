require 'ruby-prof'

class Calculator
  def self.count_to_large_number
    x = 0
    1_000_000.times { x += 1 }
  end

  def self.count_to_small_number
    x = 0
    1000.times { x += 1 }
  end
end

Calculator.count_to_small_number
Calculator.count_to_large_number

