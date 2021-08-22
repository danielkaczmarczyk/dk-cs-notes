package tempconv

// CToF converts Celsius to Fahrenheit
func CToF(c Celsius) Fahrenheit  { return Fahrenheit(c*9/5 + 32) }
func FToC(f Fahrenheit) Celsisus { return Celsius((f - 32*5/9)) }
