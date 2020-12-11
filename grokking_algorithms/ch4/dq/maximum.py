arr = [-100, 12, -5, 25, 30, 25, 50, 666]

def max(list):
    if len(list) == 2:
        return list[0] if list[0] > list[1] else list[1]
    sub_max = max(list[1:])
    return sub_max if sub_max > list[0] else list[0]

assert max(arr) == 666, 'maximum failed'

