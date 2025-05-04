import sys
input = sys.stdin.readline  # 입력 속도 개선
print = sys.stdout.write    # 출력 속도 개선

class AbsoluteHeap:
    HeapTree = []
    def __init__(self):
        self.HeapTree = []

    def __heapify_up(self, idx: int):
        if idx == 1:
             return
        
        parent_idx = idx // 2

        if abs(self.HeapTree[parent_idx-1]) > abs(self.HeapTree[idx-1]) or \
            (abs(self.HeapTree[parent_idx-1]) == abs(self.HeapTree[idx-1]) and self.HeapTree[parent_idx-1] > self.HeapTree[idx-1]):

            self.HeapTree[parent_idx-1], self.HeapTree[idx-1] = self.HeapTree[idx-1], self.HeapTree[parent_idx-1]

            self.__heapify_up(parent_idx)
    
    def push(self, value):
        self.HeapTree.append(value)
        self.__heapify_up(len(self.HeapTree))

    def __heapify_down(self, idx: int):

        left_idx = idx*2
        right_idx = idx*2+1

        if len(self.HeapTree) < left_idx:
            return
        
        left_swap = False
        right_swap = False
        
        if abs(self.HeapTree[left_idx-1]) < abs(self.HeapTree[idx-1]) or \
            (abs(self.HeapTree[left_idx-1]) == abs(self.HeapTree[idx-1]) and self.HeapTree[left_idx-1] < self.HeapTree[idx-1]):
            left_swap = True
             
        if len(self.HeapTree) >= right_idx:
            if abs(self.HeapTree[right_idx-1]) < abs(self.HeapTree[idx-1]) or \
                (abs(self.HeapTree[right_idx-1]) == abs(self.HeapTree[idx-1]) and self.HeapTree[right_idx-1] < self.HeapTree[idx-1]):
                right_swap = True
        
        if left_swap == True or right_swap == True:
            if left_swap == False:
                swap_idx = right_idx
            elif right_swap == False:
                swap_idx = left_idx
            else:
                if abs(self.HeapTree[left_idx-1]) < abs(self.HeapTree[right_idx-1]) or \
                (abs(self.HeapTree[left_idx-1]) == abs(self.HeapTree[right_idx-1]) and self.HeapTree[left_idx-1] < self.HeapTree[right_idx-1]):
                    swap_idx = left_idx
                else:
                    swap_idx = right_idx


            self.HeapTree[swap_idx-1], self.HeapTree[idx-1] = self.HeapTree[idx-1], self.HeapTree[swap_idx-1]
            
            self.__heapify_down(swap_idx)

    def pop(self) -> int:
        if len(self.HeapTree) == 0:
            return 0

        top = self.HeapTree[0]
        self.HeapTree[0] = self.HeapTree[-1]
        self.HeapTree.pop()
        self.__heapify_down(1)
        return top

ah = AbsoluteHeap()

N = int(input())
for i in range(N):
    x = int(input())
    if x == 0:
        result = ah.pop()
        print(str(result) + '\n')
    else:
         ah.push(x)
        

# 두개 부모보다 작을경우 -> 둘중 더 작은애를 올려야함
# 한개만 작을경우 -> 그 애를 올려야함
# 둘다 클경우 -> 그대로