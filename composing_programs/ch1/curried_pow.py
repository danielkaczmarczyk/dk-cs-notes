def curried_pow(n):
    def pow(x):
        return x ** n
    return pow

print(curried_pow(2)(2))
