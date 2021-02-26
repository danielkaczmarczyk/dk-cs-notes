import math

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
    rows = int(math.ceil(len(ciphertext) / float(key)))
    grid_size = rows * key
    shaded_boxes = grid_size - len(ciphertext)
    skip_over = key - shaded_boxes
    count = 1
    for row in range(rows):
        i = row
        while i < len(ciphertext):
            if row == rows - 1 and count > skip_over:
                break
            result += ciphertext[i]
            if count <= skip_over:
                i += rows
            else:
                i += rows - 1
            count += 1
        count = 1
    return result

def brute_force(ciphertext):
    """
        brute forces all possible solutions, returns an array
        of various transpositions of the ciphertext
    """
    results = []
    for n in range(1, len(ciphertext)):
        crack_attempt = crack_columnar_transposition(ciphertext, n)
        results.append(crack_attempt)

    return results

def practice_question_task():
    messages = [
        "H▪cb▪▪irhdeuousBdi▪▪▪prrtyevdgp▪nir▪▪eerit▪eatoreechadihf▪paken▪ge▪b▪te▪dih▪aoa.da▪tts▪tn",
        "A▪b▪▪drottthawa▪nwar▪eci▪t▪nlel▪ktShw▪leec,hheat▪.na▪▪e▪soogmah▪a▪▪ateniAcgakh▪dmnor▪▪",
        "Bmmsrl▪dpnaua!toeboo’ktn▪uknrwos.▪yaregonr▪w▪nd,tu▪▪oiady▪hgtRwt▪▪▪A▪hhanhhasthtev▪▪e▪t▪e▪▪eo"
    ]
    for msg in messages:
        msg = msg.replace("▪", " ")
        attempts = brute_force(msg)
        # from the book we know the key is 9
        print(attempts[8])

if __name__ == '__main__':
    print('hi')
