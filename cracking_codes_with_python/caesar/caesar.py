message = 'hello'
key = 213
SYMBOLS = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890 !?.'
translated = ''

for symbol in message:
    if symbol in SYMBOLS:
        new_symbol_index = SYMBOLS.index(symbol) + key
        if new_symbol_index >= len(SYMBOLS):
            new_symbol_index %= len(SYMBOLS)
        replaced = SYMBOLS[new_symbol_index]
        translated += replaced
    else:
        translated += symbol

print(message)
print(translated)

