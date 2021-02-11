def iterative_sum(numbers):
    total = 0
    for n in numbers:
        total += n
    return total

def recursive_sum(numbers):
    if len(numbers) == 1:
        return numbers[0]
    return numbers[0] + recursive_sum(numbers[1:])

if __name__ == '__main__':
    numbers = [1, 3, 5, 7, 9]
    print(iterative_sum(numbers))
    print(recursive_sum(numbers))
