'''
    input has exactly one solution, and i can't use the same indice twice

    the naive solution of iterating over the array to find complements
    ends up being a O(n^2) time complexity solution.

    it is possible to do it more efficiently if instead of nesting a loop i will
    maintain a lookup table and check if compliments exist in it as i iterate

    that approach yields the best result in terms of time to solve, as it is
    going to take O(n) operations to look up the complement.

    the tradeoff is space, in the worst case scenario, storing O(n) items.
'''
class Solution:

    def twoSum(self, nums, target):
        lookup = {}
        for i, n in enumerate(nums):
            complement = target - n
            if complement in lookup:
                return [lookup[complement], i]
            if n not in lookup:
                lookup[n] = i

    def twoSum_iter(self, nums, target):
        for i, n in enumerate(nums):
            for j, m in enumerate(nums):
                if i == j:
                    pass
                elif n + m == target:
                    return [i, j]

    def assertions(self):
        assert self.twoSum([2,7,11,15], 9) == [0, 1], 'twoSum failed'
        assert self.twoSum([3,2,4], 6) == [1, 2], 'twoSum failed'
        assert self.twoSum([3,3], 6) == [0, 1], 'twoSum failed'

sol = Solution()
sol.assertions()
