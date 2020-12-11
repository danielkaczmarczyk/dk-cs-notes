string = 'daniel'

def reverse_string(string):
    if len(string) == 1:
        return string

    return reverse_string(string[1:]) + string[0] 

print(reverse_string(string))

