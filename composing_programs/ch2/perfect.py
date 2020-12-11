def divisors(n):
    return [1] + [i for i in range(2, n) if n % i == 0]

'''
    a perfect integer is a integer that is equal to the sum of its divisors.
'''

def perfect_integers(n):
    return [i for i in range(2, n) if i == sum(divisors(i))]

print(perfect_integers(1000))
