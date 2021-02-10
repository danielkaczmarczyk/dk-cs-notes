from balancer import Balancer
import unittest

class BalancerTest(unittest.TestCase):

    def test_init(self):
        input_string = '(())'
        balancer = Balancer(input_string)

        self.assertEqual(balancer.input_string, input_string)

    def test_balanced_1(self):

        input_string = '()'
        balancer = Balancer(input_string)

        self.assertTrue(balancer.balanced)


if __name__ == "__main__":
    unittest.main()

