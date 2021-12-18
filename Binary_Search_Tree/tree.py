class Node:
    def __init__(self, val):
        self.val = val
        self.l = None
        self.r = None


def search(root, val):
    if root is None:
        return False
    elif root.val == val:
        return True
    elif root.val > val:
        return search(root.l, val)
    else:
        return search(root.r, val)

def insert(node, val):
    if node is None:
        return Node(val)
    
    if val > node.val:
        node.r = insert(node.r, val)
    else:
        node.l = insert(node.l, val)
    
    return node


root = insert(None, 5)
root = insert(root, 2)
root = insert(root, 6)
root = insert(root, 1)
root = insert(root, 3)

# for i in [1,2,3,4,5,6]:
#     print(i, search(root, i))

# root = insert(root, 4)
# print()
# for i in [1,2,3,4,5,6]:
#     print(i, search(root, i))

print(root.val)
print(root.l.val)
print(root.r.val)
print(root.l.l.val)
print(root.l.r.val)

