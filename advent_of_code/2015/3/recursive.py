import sys

sys.setrecursionlimit(10**6)

real_input = open('input.txt', 'r').read()
test_input = '^v<>'

santa = [0, 0]
robo_santa = [0, 0]
visited = []

def deliver_present(location):
    stringified_location = str(location)
    if stringified_location not in visited:
        visited.append(stringified_location)


def make_mover(agent):
    def mover(move):
        if move == 'v':
            agent[1] -= 1
        elif move == '^':
            agent[1] += 1
        elif move == '>':
            agent[0] += 1
        elif move == '<':
            agent[0] -= 1

        deliver_present(agent)
    return mover

def verify_call(caller_fn):
    def wrapper(string):
        if len(string) == 0:
            return
        else:
            caller_fn(string)
    return wrapper

santa_mover = make_mover(santa)
robo_mover = make_mover(robo_santa)

@verify_call
def santa_caller(string):
    santa_mover(string[-1])
    robo_caller(string[:-1])

@verify_call
def robo_caller(string):
    robo_mover(string[-1])
    santa_caller(string[:-1])

santa_caller(real_input)

print(santa, robo_santa)
print(len(visited))
