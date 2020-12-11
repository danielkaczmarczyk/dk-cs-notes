'''
As another example of mutual recursion, consider a two-player game in which there are n initial pebbles on a table. The players take turns, removing either one or two pebbles from the table, and the player who removes the final pebble wins. Suppose that Alice and Bob play this game, each using a simple strategy:

    Alice always removes a single pebble
    Bob removes two pebbles if an even number of pebbles is on the table, and one otherwise

Given n initial pebbles and Alice starting, who wins the game?

A natural decomposition of this problem is to encapsulate each strategy in its own function. This allows us to modify one strategy without affecting the other, maintaining the abstraction barrier between the two. In order to incorporate the turn-by-turn nature of the game, these two functions call each other at the end of each turn.
'''

def play_alice(n):
    print(f'Alice: {n}')
    if n == 0:
        return 'Bob wins!'
    return play_bob(n - 1)

def play_bob(n):
    print(f'Bob: {n}')
    if n == 0:
        return 'Alice wins!'
    if n % 2 == 0:
        return play_alice(n - 2)
    else:
        return play_alice(n - 1)

print(play_alice(900))
# assert play_alice(20) == 'Bob wins!', 'alice did not lose'
