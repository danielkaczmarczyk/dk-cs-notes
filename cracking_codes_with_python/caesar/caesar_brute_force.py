message = ''
SYMBOLS = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890 !?.'
translated = 'wt114L!471s'

for key in range(len(SYMBOLS)):
    for symbol in translated:
        if symbol in SYMBOLS:
            new_symbol_index = SYMBOLS.index(symbol) + key
            if new_symbol_index >= len(SYMBOLS):
                new_symbol_index %= len(SYMBOLS)
            replaced = SYMBOLS[new_symbol_index]
            message += replaced
        else:
            message += symbol
    print(f"{key}: {message}")
    message = ''

