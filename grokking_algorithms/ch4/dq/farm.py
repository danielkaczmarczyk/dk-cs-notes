farm_size = [1680, 640]

"""
task: find smallest square plot of land to divide the whole
farm evenly. 

method: using Euclidean Algorithm, if we can prove the
smallest square for a subset of the problem, we can
prove the smallest square for the whole problem
"""

def find_smallest_square(farm_size):
    farm_size.sort()
    [x, y] = farm_size

    if y == 2 * x:
        return x

    new_side = y % x
    return find_smallest_square([new_side, x])



smallest_square = find_smallest_square(farm_size)
assert smallest_square == 80, 'the smallest_square fn failed'

