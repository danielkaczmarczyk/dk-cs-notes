def columnar_transposition(message, key):
    transposed = ''
    for i in range(len(message)): 
        if i == key:
            break
        while i < len(message):
            transposed += message[i]
            i += key
    return transposed

if __name__ == '__main__':
    encrypted = columnar_transposition("HELLO WORLD", 3)
    print(encrypted)

