import sys
import functools


@functools.lru_cache(None)
def band(val_one, val_two):
    val_one, val_two = min(val_one, val_two), max(val_one, val_two)
    
    return max(algo(a) for a in range(val_one, val_two+1))


@functools.lru_cache(None)
def algo(a):
    cycle = 1

    while 1 != a:
        if a % 2 != 0:
            a = 3*a + 1
        else:
            a = a // 2
            
        cycle += 1
    
    return cycle


if __name__ == '__main__':    
    for a in sys.stdin:
        val_one, val_two = map(int, a.split())
        print(val_one, val_two, band(val_one, val_two))
        
    exit(0)