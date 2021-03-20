class MyClass
  def initialize
    @my_variable = 'Hello, world!'
  end

  def another
    puts rand(100) * 3
  end
end

obj = MyClass.new
obj.instance_eval { puts @my_variable }
obj.instance_eval { another }
