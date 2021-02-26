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
    import math
    result = ''
    rows = int(math.ceil(len(ciphertext) / float(key)))
    grid_size = rows * key
    shaded_boxes = grid_size - len(ciphertext)
    skip_over = key - shaded_boxes
    str_limit = grid_size - shaded_boxes - 1
    print(f"{grid_size=} {rows=} {key=} {shaded_boxes=} {skip_over=}")

    count = 1
    for row in range(rows):
        i = row
        while i < len(ciphertext):
            print(f"{i=} {count=}")
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
        results.append(crack_columnar_transposition(ciphertext, n))
    return results

def practice_question():
    messages = [
        "H▪cb▪▪irhdeuousBdi▪▪▪prrtyevdgp▪nir▪▪eerit▪eatoreechadihf▪paken▪ge▪b▪te▪dih▪aoa.da▪tts▪tn",
        "A▪b▪▪drottthawa▪nwar▪eci▪t▪nlel▪ktShw▪leec,hheat▪.na▪▪e▪soogmah▪a▪▪ateniAcgakh▪dmnor▪▪",
        "Bmmsrl▪dpnaua!toeboo’ktn▪uknrwos.▪yaregonr▪w▪nd,tu▪▪oiady▪h gtRwt▪▪▪A▪hhanhhasthtev▪▪e▪t▪e▪▪eo"
    ]
    for msg in messages:
        msg = msg.replace("▪", " ")


if __name__ == '__main__':
    import unittest

    class TranspositionTests(unittest.TestCase):

        def test_book_example_encryption(self):
            plaintext = "Common sense is not so common."
            key = 8
            ciphertext = columnar_transposition(plaintext, key)
            expected = "Cenoonommstmme oo snnio. s s c"
            self.assertEqual(ciphertext, expected)

        def test_book_example_decryption(self):
            plaintext  = "Common sense is not so common."
            ciphertext = "Cenoonommstmme oo snnio. s s c"
            cracked = brute_force(ciphertext)
            found = False

            for string in cracked:
                print(string)
                if string == plaintext:
                    found = True
                    break

            self.assertTrue(found)

    
    #unittest.main()
    ciphertext = "Cenoonommstmme oo snnio. s s c"
    crack_columnar_transposition(ciphertext, 8)


