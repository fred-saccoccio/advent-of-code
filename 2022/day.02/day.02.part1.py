import sys
from enum import Enum

verbose = False

if len(sys.argv) >= 2:
    sys.stdin = open(sys.argv[1], "r")

class RpsHand(Enum):
    ROCK = 1
    PAPER = 2
    SCISSORS = 3

def to_enum(p):
    match p:
        case 'A':
            return RpsHand.ROCK
        case 'X':
            return RpsHand.ROCK
        case 'B':
            return RpsHand.PAPER
        case 'Y':
            return RpsHand.PAPER
        case 'C':
            return RpsHand.SCISSORS
        case 'Z':
            return RpsHand.SCISSORS
        case _:
            raise Exception(f"'{p}' unkown RPS move")

def resolve(p1, p2):
    mp1, mp2 = to_enum(p1), to_enum(p2)

    if mp1 == mp2:
        return -1, [mp1.value + 3, mp1.value + 3] 
    
    winner = -1

    if mp1 == RpsHand.ROCK:
        if mp2 == RpsHand.SCISSORS:
            winner = 1
        else:
            winner = 2
        pass
    elif mp1 == RpsHand.PAPER:
        if mp2 == RpsHand.ROCK:
            winner = 1
        else:
            winner = 2
    elif mp1 == RpsHand.SCISSORS:
        if mp2 == RpsHand.ROCK:
            winner = 2
        else:
            winner = 1
    
    if winner == 1:
        add_score1, add_score2 = 6,0
    else:
        add_score1, add_score2 = 0,6

    return winner, [mp1.value+add_score1, mp2.value+add_score2]

total_score = 0
while True:
    line = sys.stdin.readline()
    if not line:
        break
    line = line.rstrip()

    p1, p2 = line.split()
    w, scores = resolve(p1, p2)
    
    if verbose:
        print(f"input='{line}', winner={w},scores={scores}")
    
    total_score += scores[1]

print(total_score)
