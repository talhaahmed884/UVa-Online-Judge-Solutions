def printBlocks(blocks, size):
    for a in range(size):
        print(a, end='')
        print(':', end = '')
        temp = blocks[a]
        if temp != []:
            for b in temp:
                print('', b, end='')
        print(end='\n')

    return


def band(blocks):
    while 1:
        line = input()

        if line == 'quit':
            break
            return
        lint = line.split(' ', 4)
        if (int(lint[1]) != int(lint[3])) and (findBlock(blocks, int(lint[1])) != findBlock(blocks, int(lint[3]))):
            if lint[0] == 'move':
                if lint[2] == 'onto':
                    moveOnto(blocks, int(lint[1]), int(lint[3]))
                elif lint[2] == 'over':
                    moveOver(blocks, int(lint[1]), int(lint[3]))
            elif lint[0] == 'pile':
                if lint[2] == 'onto':
                    pileOnto(blocks, int(lint[1]), int(lint[3]))
                elif lint[2] == 'over':
                    pileOver(blocks, int(lint[1]), int(lint[3]))

    return


def moveOnto(blocks, a, b):
    if blocks[a] != []:
        for c in blocks[a]:
            if c != a:
                blocks[c].append(c)

        blocks[a] = []
    else:
        index = findBlock(blocks, a)
        temp = blocks[index]
        temp_1 = []
        while 1:
            if temp[0] != a:
                temp_1.append(temp.pop(0))
            else:
                break
        blocks[index] = temp_1
        temp.pop(0)
        
        for c in temp:
            blocks[c].append(c)
    
    if blocks[b] != []:
        for c in blocks[b]:
            if c != b:
                blocks[c].append(c)

        blocks[b] = []
        blocks[b].append(b)
        blocks[b].append(a)
    else:
        index = findBlock(blocks, b)
        temp = blocks[index]
        temp_1 = []
        while 1:
            if temp[0] != b:
                temp_1.append(temp.pop(0))
            else:
                break
        temp_1.append(temp.pop(0))

        for c in temp:
            blocks[c].append(c)

        temp_1.append(a)
        blocks[index] = temp_1

    return


def moveOver(blocks, a, b):
    if blocks[a] != []:
        for c in blocks[a]:
            if c != a:
                blocks[c].append(c)

        blocks[a] = []
    else:
        index = findBlock(blocks, a)
        temp = blocks[index]
        temp_1 = []
        while 1:
            if temp[0] != a:
                temp_1.append(temp.pop(0))
            else:
                break  
        temp.pop(0)
        blocks[index] = temp_1
        
        for c in temp:
            blocks[c].append(c)

    index = b
    if blocks[index] == []:
        index = findBlock(blocks, b)

    blocks[index].append(a)

    return


def pileOnto(blocks, a, b):
    if blocks[b] != []:
        for c in blocks[b]:
            if c != b:
                blocks[c].append(c)

        blocks[b] = []
        blocks[b].append(b)
    else:
        index = findBlock(blocks, b)
        temp = blocks[index]
        temp_1 = []
        while 1:
            if temp[0]!=b:
                temp_1.append(temp.pop(0))
            else:
                break
        temp_1.append(temp.pop(0))

        for c in temp:
            blocks[c].append(c)
        
        blocks[index] = temp_1
        b = index

    if blocks[a] != []:
        for c in blocks[a]:
            blocks[b].append(c)

        blocks[a] = []
    else:
        index = findBlock(blocks, a)
        temp = blocks[index]
        temp_1 = []
        while 1:
            if temp[0] != a:
                temp_1.append(temp.pop(0))
            else:
                break
        
        blocks[index] = temp_1

        for c in temp:
            blocks[b].append(c)

    return


def pileOver(blocks, a, b):
    if blocks[a] != []:
        temp = blocks[a]
        blocks[a] = []
    else:
        index = findBlock(blocks, a)
        temp = blocks[index]
        temp_1 = []
        while 1:
            if temp[0] != a:
                temp_1.append(temp.pop(0))
            else:
                break

        blocks[index] = temp_1

    if blocks[b] != []:
        for c in temp:
            blocks[b].append(c)
    else:
        index = findBlock(blocks, b)
        for c in temp:
            blocks[index].append(c)

    return


def findBlock(blocks, a):
    index  = 0

    for b in blocks:
        for c in b:
            if c == a:
                return index
        
        index += 1


if __name__ == "__main__":
    blocks = []
    size = int(input())

    for a in range(size):
        temp = []
        temp.append(a)
        blocks.append(temp)
    
    band(blocks)
    printBlocks(blocks, size)

    exit(0)
