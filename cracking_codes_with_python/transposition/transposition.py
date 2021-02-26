def columnar_transposition(message, key):
    transposed = ''
    for i in range(len(message)): 
        if i == key:
            break
        while i < len(message):
            transposed += message[i]
            i += key
    return transposed

def crack_columnar_transposition(ciphertext, key):
    result = ''
    for i in range(len(ciphertext)):
        if i == key + 1:
            break
        while i < len(ciphertext):
            result += ciphertext[i]
            i += key + 1
    return result

def brute_force(ciphertext):
    """
        brute forces all possible solutions, returns an array
        of various transpositions of the ciphertext
    """
    results = []
    for n in range(len(ciphertext)):
        results.append(crack_columnar_transposition(ciphertext, n))
    return results

def filter_english(bruted, words):
    results = []
    for line in bruted:
        split = line.split(" ")
        for word in split:
            pass
    return results

if __name__ == '__main__':
    from reader import get_words
    words = get_words()

    messages = [
        "H▪cb▪▪irhdeuousBdi▪▪▪prrtyevdgp▪nir▪▪eerit▪eatoreechadihf▪paken▪ge▪b▪te▪dih▪aoa.da▪tts▪tn",
        "A▪b▪▪drottthawa▪nwar▪eci▪t▪nlel▪ktShw▪leec,hheat▪.na▪▪e▪soogmah▪a▪▪ateniAcgakh▪dmnor▪▪",
        "Bmmsrl▪dpnaua!toeboo’ktn▪uknrwos.▪yaregonr▪w▪nd,tu▪▪oiady▪h gtRwt▪▪▪A▪hhanhhasthtev▪▪e▪t▪e▪▪eo"
    ]

    for msg in messages:
        msg = msg.replace("▪", " ")

