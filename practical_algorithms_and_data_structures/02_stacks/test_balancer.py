from balancer import Balancer
import unittest

class BalancerTest(unittest.TestCase):

    def test_init(self):
        input_string = '(())'
        balancer = Balancer(input_string)

        self.assertEqual(balancer.input_string, input_string)

    def test_matching(self):
        balancer = Balancer('')

        op = '('
        cl = ')'

        self.assertTrue(balancer.matching_brackets(op, cl))

        op = '('
        cl = ']'

        self.assertFalse(balancer.matching_brackets(op, cl))

        op = '['
        cl = ']'

        self.assertTrue(balancer.matching_brackets(op, cl))

    def test_balanced(self):

        input_string = '()'
        balancer = Balancer(input_string)
        self.assertTrue(balancer.balanced)


        input_string = '(())'
        balancer = Balancer(input_string)
        self.assertTrue(balancer.balanced)

        input_string = '({})'
        balancer = Balancer(input_string)
        self.assertTrue(balancer.balanced)

        input_string = '[({})]'
        balancer = Balancer(input_string)
        self.assertTrue(balancer.balanced)

        input_string = '[[({}{}[]()([]))]]'
        balancer = Balancer(input_string)
        self.assertTrue(balancer.balanced)

if __name__ == "__main__":
    unittest.main()

