string = 'aeiou xyz' # 5 vowels

def is_vowel(letter):
    vowels = 'aeiou'
    if letter in vowels:
        return 1
    return 0

def count_vowels(string):
    if len(string) == 0:
        return 0

    return is_vowel(string[0]) + count_vowels(string[1:]) 

print(count_vowels(string))
