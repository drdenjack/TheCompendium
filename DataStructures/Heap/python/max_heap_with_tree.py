# python has a built-in 'heapq' module, but it is only a min-heap.  
# It's possible to use the min-heap as a max-heap by just changing the values from positive to negative

# Most implementations of heaps use a single array of values and restrict that arr[2*i + 1] is 
# the 'left' child and arr[2*i + 2] is the right child.  This is much faster but more abstract than
# the real tree version with nodes.

class Node():
    def __init__(self, data, parent=None):
        self.data = data
        self.left = None
        self.right = None
        self.parent = parent

    def print_node(self):
        print(self.data)
        if(self.left):
            print('left: ')
            self.left.print_node()
        if(self.right):
            print('right: ')
            self.right.print_node()

class MaxHeap():
    def __init__(self, arr):
        self._head = None
        self.size = 0
        # check if len(arr) > 2, etc ...
        for val in arr:
            self.insert(val)

    def print_heap(self):
        self.print(self._head)

    def print(self, node, level=0, child_dir=None):
        if node:
            arrow = "-"
            if child_dir == "left":
                arrow = "\\"
            elif child_dir == "right":
                arrow = "/"
            self.print(node.right, level+1, "right")
            print(' ' * 4 * level + arrow, node.data)
            self.print(node.left, level+1, "left")


    def insert(self, val) -> bool:
        self.size += 1
        if not self._head:
            self._head = Node(val)
        else:
            last_node = self.get_last_parent_node()
            new_node = Node(val, parent=last_node)
            if not last_node.left:
                last_node.left = new_node
            elif not last_node.right:
                last_node.right = new_node
            else:
                raise ValueError('Last node had left and right children for some reason')
            self.trickle_up(new_node)

        return False

    def swap(self, n1, n2):
        # swap node values
        n1.data, n2.data = n2.data, n1.data
    
    def get_last_parent_node(self):
        # this is just breadth first search
        queue = [self._head]
        while(len(queue) > 0):
            tmp = queue[0]
            queue = queue[1:]
            if not tmp.left or not tmp.right:
                return tmp
            if tmp.left:
                queue.append(tmp.left)
            if tmp.right:
                queue.append(tmp.right)

        return tmp

    def get_last_node(self):
        # this is just breadth first search
        queue = [self._head]
        while(len(queue) > 0):
            tmp = queue[0]
            queue = queue[1:]
            if tmp.left:
                queue.append(tmp.left)
            if tmp.right:
                queue.append(tmp.right)
        return tmp

    def trickle_up(self, node):
        if not node.parent:
            return
        if node.data > node.parent.data:
            self.swap(node, node.parent)
        self.trickle_up(node.parent)

    def get_max(self):
        if not self._head:
            return
        return self._head.data

    def remove_max(self):
        if not self._head:
            return None
        last_node = self.get_last_node()
        if last_node == self._head:
            self._head = None
        last_parent = last_node.parent
        if last_node == last_parent.left:
            last_parent.left = None
        elif last_node == last_parent.right:
            last_parent.right = None
        self._head.data = last_node.data
        self.trickle_down(self._head)

    def trickle_down(self, node):
        if not node.left and not node.right:
            return
        new_trickler = None
        if node.left and node.right:
            if node.left.data > node.right.data:
                if node.data < node.left.data:
                    self.swap(node, node.left)
                    new_trickler = node.left
            else:
                if node.data < node.right.data:
                    self.swap(node, node.right)
                    new_trickler = node.right
        elif node.left:
            if node.data < node.left.data:
                self.swap(node, node.left)
                new_trickler = node.left
        elif node.right:
            # this shouldn't ever actually be called
            if node.data < node.right.data:
                self.swap(node, node.right)
                new_trickler = node.right
        if new_trickler:
            self.trickle_down(new_trickler)


arr = [1, 12, 54, 83, 36, 11, 91, 3, 17]
mh = MaxHeap(arr)
mh.print_heap()

print(f'max: {mh.get_max()}')
mh.remove_max()
mh.print_heap()


print(f'max: {mh.get_max()}')
mh.remove_max()
mh.print_heap()
print(f'max: {mh.get_max()}')
mh.remove_max()
mh.print_heap()
print(f'max: {mh.get_max()}')
mh.remove_max()
mh.print_heap()