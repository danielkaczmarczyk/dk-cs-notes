def example_1
  def binding_elsewhere
    x = 20
    return binding
  end

  remote_binding = binding_elsewhere

  x = 10
  eval("puts x")
  eval("puts x", remote_binding)
end

def example_2
  def binding_elsewhere
    x = 20
    return binding
  end

  remote_binding = binding_elsewhere
  x = 10
  eval("x = 10")
  eval("x = 50", remote_binding)
  eval("puts x")
  eval("puts x", remote_binding)
end

example_2
