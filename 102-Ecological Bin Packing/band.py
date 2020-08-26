import sys


def BGC(bin_one, bin_two, bin_three):
    sum = 0
    maxSum = -1
    order = ''

    for a in range(3):
        if a == 0:
            sum = bin_one[1]+bin_one[2]+bin_two[0]+bin_two[2]+bin_three[0]+bin_three[1]
            maxSum = sum
            order = "BGC"
        elif a == 1:
            sum = bin_one[0]+bin_one[2]+bin_two[0]+bin_two[1]+bin_three[1]+bin_three[2]
            if maxSum != sum:
                maxSum = min(maxSum, sum)
                if maxSum == sum:
                    order = "GCB"
            else:
                order = min("GCB", order)
        elif a == 2:
            sum = bin_one[0]+bin_one[1]+bin_two[1]+bin_two[2]+bin_three[0]+bin_three[2]
            if maxSum != sum:
                maxSum = min(maxSum, sum)
                if maxSum == sum:
                    order = "CBG"
            else:
                order = min("CBG", order)

    return maxSum, order


def BCG(bin_one, bin_two, bin_three, maxSum, order):
    sum = 0

    for a in range(3):
        if a == 0:
            sum = bin_one[1]+bin_one[2]+bin_two[0]+bin_two[1]+bin_three[0]+bin_three[2]
            if maxSum != sum:
                maxSum = min(maxSum, sum)
                if maxSum == sum:
                    order = "BCG"
            else:
                order = min(order, "BCG")
        elif a == 1:
            sum = bin_one[0]+bin_one[1]+bin_two[0]+bin_two[2]+bin_three[1]+bin_three[2]
            if maxSum != sum:
                maxSum = min(maxSum, sum)
                if maxSum == sum:
                    order = "CGB"
            else:
                order = min("CGB", order)
        elif a == 2:
            sum = bin_one[0]+bin_one[2]+bin_two[1]+bin_two[2]+bin_three[0]+bin_three[1]
            if maxSum != sum:
                maxSum = min(maxSum, sum)
                if maxSum == sum:
                    order = "GBC"
            else:
                order = min("GBC", order)

    print(order, maxSum)

    return


if __name__ == "__main__":
    for a in sys.stdin:
        line = a.split()

        bin_one = []
        [bin_one.append(int(line[b])) for b in range(0, 3)]

        bin_two = []
        [bin_two.append(int(line[b])) for b in range(3, 6)]

        bin_three = []
        [bin_three.append(int(line[b])) for b in range(6, 9)]

        maxSum, order = BGC(bin_one, bin_two, bin_three)
        BCG(bin_one, bin_two, bin_three, maxSum, order)

    exit(0)
