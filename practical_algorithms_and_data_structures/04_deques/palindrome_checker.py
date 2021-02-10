from collections import deque

def is_palindrome(characters):
    character_deque = deque(characters)

    while len(character_deque) > 1:
        first = character_deque.popleft()
        last = character_deque.pop()
        if first != last:
            return False
    return True

if __name__ == "__main__":
   print(is_palindrome("lsdfasijfdsa"))
   print(is_palindrome("radar"))
