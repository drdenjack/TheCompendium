# python has a built-in 'heapq' module

# Most implementations of heaps use a single array of values and restrict that arr[2*i + 1] is 
# the 'left' child and arr[2*i + 2] is the right child.  This is much faster but more abstract than
# the real tree version with nodes.

# left child idx:  2*i + 1
# right child idx: 2*i + 2
# parent node: k = (i-1)//2 
#   i = 1 -> k = (1-1)//2 == 0
#   i = 2 -> k = (2-1)//2 == 0
#   i = 3 -> k = (3-1)//2 == 1
#   i = 4 -> k = (4-1)//2 == 1
#   i = 5 -> k = (5-1)//2 == 2
#   i = 6 -> k = (6-1)//2 == 2



class MinHeap():
    def __init__(self, arr):
        # check if len(arr) > 2, etc ...
        self._heap = []
        for val in arr:
            self.insert(val)

    def size(self):
        return len(self._heap)

    def _last_index(self):
        return self.size() - 1

    def _get_parent_index(self, idx):
        return (idx -1)//2

    def _get_left_child_index(self, idx):
        child_idx = 2*idx + 1
        if child_idx > self.size():
            return 
        return child_idx

    def _get_right_child_index(self, idx):
        child_idx = 2*idx + 2
        if child_idx > self.size():
            return 
        return child_idx

    def _swap(self, i, j):
        # print('')
        # print(f'  SWAPPING INDEXES: {i}, {j}')
        # print(f'  PRE SWAP: {self._heap}')
        self._heap[i], self._heap[j] = self._heap[j], self._heap[i]
        # print(f'  POST SWAP: {self._heap}')

    def insert(self, val):
        print()
        print(f' +++ inserting value: {val}')
        print(f' +++    new index = {self.size()}')
        self._heap.append(val)
        if len(self._heap) > 1:
            self._trickle_up()

    def get_min(self):
        return self._heap[0]

    def pop(self):
        if self.size() == 0:
            return 

        ret = self._heap[0]
        if self.size() == 1:
            self._heap = []
            return ret

        self._swap(0, self._last_index())
        self._heap = self._heap[:-1]
        self._trickle_down()
        return ret

    def _trickle_up(self):
        # print('starting to trickle up ...')
        idx = self._last_index()
        while(idx>0):
            # print(f'idx: {idx}')
            parent_idx = self._get_parent_index(idx)
            # print(f'parent_idx: {parent_idx}')
            # print(f'values: curr, parent: {self._heap[idx]}, {self._heap[parent_idx]}')
            if self._heap[idx] < self._heap[parent_idx]:
                # print(' --- swapping ---')
                self._swap(idx, parent_idx)
                # print(f'    NEW VALUE: {self._heap[idx]}')
                # print(f'    NEW PARENT VALUE: {self._heap[parent_idx]}')
            else:
                # print(' == NOT SWAPPING ==')
                break
            idx = parent_idx

    def _trickle_down(self):
        idx = 0
        while(idx<self.size()):
            left_idx = self._get_left_child_index(idx)
            right_idx = self._get_right_child_index(idx)
            if right_idx == self.size():
                right_idx = None
            # print(f'idx, left_idx, right_idx: {idx}, {left_idx}, {right_idx}')
            if left_idx and right_idx:
                # print(f'size: {self.size()}')
                if self._heap[left_idx] < self._heap[right_idx]:
                    if self._heap[idx] > self._heap[left_idx]:
                        self._swap(idx, left_idx)
                        idx = left_idx
                    else:
                        break
                else:
                    if self._heap[idx] > self._heap[right_idx]:
                        self._swap(idx, right_idx)
                        idx = right_idx
                    else:
                        break
            elif left_idx:
                if self._heap[idx] > self._heap[left_idx]:
                    self._swap(idx, left_idx)
                    idx = left_idx
                else:
                    break
            elif right_idx:
                raise ValueError("right_idx shouldn't exist without left_idx")
            else:
                break

    def print_heap(self):
        print()
        self.print(0)

    def print(self, idx, level=0, child_dir=None):
        if idx < self.size():
            arrow = "-"
            if child_dir == "left":
                arrow = "\\"
            elif child_dir == "right":
                arrow = "/"
            left_idx = self._get_right_child_index(idx)
            right_idx = self._get_left_child_index(idx)
            if left_idx:
                self.print(left_idx, level+1, "right")
            print(' ' * 4 * level + arrow, self._heap[idx])
            if right_idx:
                self.print(right_idx, level+1, "left")



arr = [1, 12, 54, 83, 36, 11, 91, 3, 17]
mh = MinHeap(arr)
mh.print_heap()

print(f'min: {mh.get_min()}')
mh.pop()
mh.print_heap()


print(f'min: {mh.get_min()}')
mh.pop()
mh.print_heap()
print(f'min: {mh.get_min()}')
mh.pop()
mh.print_heap()
print(f'min: {mh.get_min()}')
mh.pop()
mh.print_heap()