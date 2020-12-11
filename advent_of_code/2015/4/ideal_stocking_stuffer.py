import hashlib

class Miner():
    def __init__(self, secret):
        self.secret = secret
        self.number = 1
        self.mined = False

    def get_hex_from_hash(self, input_string):
        return hashlib.md5(input_string.encode()).hexdigest()

    def check_trailing_zeroes(self, n, hash_hex):
        return hash_hex.startswith('0' * n)

    def mine(self, n):
        while not self.mined:
            hash_hex = self.get_hex_from_hash(self.secret + str(self.number))
            if self.check_trailing_zeroes(n, hash_hex):
                self.mined = True
                print(self.number)
            self.number += 1
        self.mined = False



secret = 'ckczppom'
miner = Miner(secret)
miner.mine(5)
miner.mine(6)

