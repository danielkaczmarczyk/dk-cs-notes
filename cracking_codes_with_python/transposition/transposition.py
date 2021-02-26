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
    from reader import get_words
    words = get_words()
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
    import random
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
                if string == plaintext:
                    found = True
                    break

            self.assertTrue(found)

        def test_random_examples(self):
            random.seed(42)
            plaintext = '' 

            for n in range(100):
                for n in range(50):
                    integer = math.floor(random.random() * 10)
                    plaintext += str(integer)
                key = random.randrange(1, len(plaintext) // 2)
                ciphertext = columnar_transposition(plaintext, key)
                plaintext_2 = crack_columnar_transposition(ciphertext, key)
                self.assertEqual(plaintext, plaintext_2)
                plaintext = ''


    unittest.main()


