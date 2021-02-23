message = "secretz"
key = 1
SYMBOLS = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890 !?.'

translated = ''

for symbol in message:
    if symbol in SYMBOLS:
        new_symbol_index = SYMBOLS.index(symbol) + key
        if new_symbol_index >= len(SYMBOLS):
            new_symbol_index %= len(SYMBOLS)
        replaced = SYMBOLS[new_symbol_index]
        translated += replaced
        print(f"{symbol=} replaced by: {replaced=}")
    else:
        print(f"{symbol=} NOT IN SYMBOLS")
        translated += symbol

print(message)
print(translated)
