class String
  def titelize
    self.gsub(/(\A|\s)\w/) { |letter| letter.upcase }
  end
end

def assert_titelize(message, input, expected)
  result = input.titelize 
  raise "#{message}\nresult: #{result}" unless result == expected
end

begin
  assert_titelize("Fail 1", "this is a test", "This Is A Test")
  assert_titelize("Fail 2", "another test 1234", "Another Test 1234")
  assert_titelize("Fail 3", "We're testing titelize", "We're Testing Titelize")
  puts "all good"
rescue => e
  puts "error message: #{e}"
end

