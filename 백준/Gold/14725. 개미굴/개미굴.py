N = int(input())

class Trie:
    def __init__(self):
        self._data = dict()
    
    def create(self, item):
        self._data[item] = Trie()

    def find(self, item):
        if item not in self._data:
            return None
        return self._data[item]

    def children(self):
        return self._data.keys()

def traverse_trie(cursor, depth=0):
    for child in sorted(cursor.children()):
        print('--'*depth+child)
        traverse_trie(cursor.find(child), depth+1)

ant = Trie()
for i in range(N):
    raw = input().split()
    n, ls = int(raw[0]),raw[1:]
    cursor = ant
    for item in ls:
        next = cursor.find(item)
        if next is None:
            cursor.create(item)
            next = cursor.find(item)
        cursor = next
        
traverse_trie(ant)