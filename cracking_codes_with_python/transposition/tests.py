import math
import random
import unittest

from transposition import columnar_transposition, crack_columnar_transposition, brute_force

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
