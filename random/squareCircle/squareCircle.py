import sys 
import random
from math import sqrt

def pointDist(x1, y1, x2, y2):
    return sqrt((x2 - x1)**2 + (y2 - y1)**2)

def main():
    total = 0
    inside = 0
    for i in range(0, int(sys.argv[1])):
        total += 1
        x = random.random()
        y = random.random()
        if pointDist(x, y, 0.5, 0.5) <= 0.5:
            inside += 1
    print(4*(inside/total))

main()
