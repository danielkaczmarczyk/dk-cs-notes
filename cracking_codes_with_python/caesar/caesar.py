SYMBOLS = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890 !?.'

def rotate_wheel(message, key=0, mode='encrypt'):
    target = ''
  
    if mode == 'encrypt':
        for symbol in message:
            target += get_symbol_after_rotation(symbol, key)
        print(message)
        print(target)
    elif mode == 'decrypt':
        for key in range(len(SYMBOLS)):
            for symbol in message:
                target += get_symbol_after_rotation(symbol, key)
            print(f"{key}: {target}")
            target = ''


def get_symbol_after_rotation(symbol, key):
    if symbol not in SYMBOLS:
        return symbol
    else:
        new_symbol_index = SYMBOLS.index(symbol) + key
        if new_symbol_index >= len(SYMBOLS):
            new_symbol_index %= len(SYMBOLS)
        return SYMBOLS[new_symbol_index]

rotate_wheel('hello world', 300)
