class String
  def vowels
    scan(/[aeiou]/i)
  end
end

p "this is a test".vowels
