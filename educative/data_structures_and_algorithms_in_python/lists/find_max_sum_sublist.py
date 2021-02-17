def find_max_sum_sublist(array):
    max_sum = 0
    
    i = 0
    ln = len(array)

    while i < len(array) - 1:
        j = i + 1
        print(f"starting from: {array[i]}, index {i}")

        while j <= len(array):
            if i == 0 and j == ln or j - i == 1:
                j += 1
                continue
            current_sum = sum(array[i:j])
            if current_sum > max_sum:
                max_sum = current_sum
            print(f"{i=}:{j=} sum of {array[i:j]} is {sum(array[i:j])}")
            j += 1
        i += 1
        print("\n")

    return max_sum



array = [-4, 2, -5, 1, 2, 3, 6, -5, 1]
array = [3, 7, -10, 7]
result = find_max_sum_sublist(array)
print(result)

