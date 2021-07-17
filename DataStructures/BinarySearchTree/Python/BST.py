# Binary Search Tree
# BSTs have only unique values
# Smaller values are on left, bigger values are on right

from typing import List, Union


print("Binary Search Tree")

class Node:
    def __init__(self, data):
        self.data = data
        self.left = []
        self.right = []

    def print(self):
        print(f"Node: data = {self.data}")
        if(self.left):
            print(f"    Left child: {self.left.data}")
        else:
            print(f"    Left child:  NONE")
        if(self.right):
            print(f"    Right child: {self.right.data}")
        else:
            print(f"    Right child:  NONE")



class BinarySearchTree():
    def __init__(self, vals: List[int]):
        self._head = None
        self.insert_list(vals)
        self.balance()

    def insert_list(self, vals: List[int]) -> None:
        for v in vals:
            self.insert(v)

    def insert(self, v: int) -> bool:
        if not self._head:
            self._head = Node(v)
        else:
            new_node = Node(v)
            curr = self._head
            while(curr):
                if v == curr.data:
                    return False
                elif v < curr.data:
                    if curr.left:
                        curr = curr.left
                    else:
                        curr.left = new_node
                        return True
                else:
                    if curr.right:
                        curr = curr.right
                    else:
                        curr.right = new_node
                        return True


    def swap(self, n1, n2):
        # swap node values
        n1.data, n2.data = n2.data, n1.data

    def get_depth(self) -> int:
        return self._get_node_depth(self._head)

    def _get_node_depth(self, n: Node) -> int:
        if not n:
            return 0
        ld = self._get_node_depth(n.left)
        rd = self._get_node_depth(n.right)
        ret = 1
        if ld > rd:
            ret += ld
        else:
            ret += rd
        return ret

    def breadth_first_search(self) -> List[int]:
        if not self._head:
            return []
        queue = [self._head]
        vals = []
        while(len(queue) > 0):
            tmp = queue[0]
            vals.append(tmp.data)
            queue = queue[1:]
            if tmp.left:
                queue.append(tmp.left)
            if tmp.right:
                queue.append(tmp.right)
        return vals

    def depth_first_search(self, order='in') -> List[int]:
        """order options = ['in', 'pre', 'post']"""
        if order == 'in':
            return self._in_order_traversal(self._head)
        elif order == 'pre':
            return self._pre_order_traversal(self._head)
        elif order == 'post':
            return self._post_order_traversal(self._head)
        else:
            raise Exception(f"order = '{order}' is not valid for depth_first_search")

    def _pre_order_traversal(self, n: Node) -> List[int]:
        if not n:
            return []
        vals = [n.data]
        vals += self._pre_order_traversal(n.left)
        vals += self._pre_order_traversal(n.right)
        return vals

    def _in_order_traversal(self, n: Node) -> List[int]:
        """Return a sorted list of ints!"""
        if not n:
            return []
        vals = self._in_order_traversal(n.left)
        vals += [n.data]
        vals += self._in_order_traversal(n.right)
        return vals

    def _post_order_traversal(self, n: Node) -> List[int]:
        if not n:
            return []
        vals = self._post_order_traversal(n.left)
        vals += self._post_order_traversal(n.right)
        vals += [n.data]
        return vals

    def find(self, val: int) -> Union[Node, None]:
        if not self._head:
            return None
        curr = self._head
        while(curr):
            if val == curr.data:
                return curr
            if val > curr.data:
                curr = curr.right
            else:
                curr = curr.left

        return None

    def balance(self) -> None:
        # sort the nodes
        # pick the one in the middle as the new head
        # the left half of the list goes on the left
        # the right half of the list goes on the right
        # recurse the hell out of it
        print("Balancing the tree...")
        sorted_vals = self.depth_first_search()  # in order traversal returns sorted list
        self._head = self._sub_balance(sorted_vals)
        
    def _sub_balance(self, vals) -> Node:
        size = len(vals)
        if size == 1:

            return Node(vals[0])
        else:
            mid = size // 2

            new_node = Node(vals[mid])
            left_vals = vals[:mid]
            right_vals = vals[mid+1:]
            if len(left_vals) > 0:
                new_node.left = self._sub_balance(left_vals)
            if len(right_vals) > 0:
                new_node.right = self._sub_balance(right_vals)
            return new_node

    def remove(self, val: int) -> bool:
        print(f"Removing {val}")
        # find it
        if not self._head:
            return False
        prev = None
        curr = self._head
        while(curr):
            if val == curr.data:
                if not curr.left and not curr.right:
                    if curr == prev.left:
                        prev.left = None
                    else:
                        prev.right = None
                    return True
                elif curr.left and curr.right:
                    # find smallest element in right sub-tree 
                    # swap val with curr
                    # remove leaf
                    smallest_prev = curr
                    smallest = smallest_prev.right
                    while(smallest.left):
                        smallest_prev = smallest
                        smallest = smallest.left

                    curr.data = smallest.data
                    if smallest == smallest_prev.left:
                        smallest_prev.left = None
                    else:
                        smallest_prev.right = None
                    return True
                else:
                    # node has only 1 child
                    if curr == prev.left:
                        if curr.left:
                            prev.left = curr.left
                        else:
                            prev.left = curr.right
                    else:
                        if curr.left:
                            prev.right = curr.left
                        else:
                            prev.right = curr.right
                    return True

            if val > curr.data:
                prev = curr
                curr = curr.right
            else:
                prev = curr
                curr = curr.left

    def print_tree(self):
        print()
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



if __name__ == "__main__":
    arr = [1, 12, 54, 83, 36, 11, 91, 3, 17]
    bst = BinarySearchTree(arr)
    bst.print_tree()
    print(f'depth: {bst.get_depth()}')

    bfs_vals = bst.breadth_first_search()
    print(f'BFS values: {bfs_vals}')

    print()
    print("in order depth first search ...")
    dfs_vals = bst.depth_first_search('in')
    print(f'DFS values: {dfs_vals}')

    print()
    print("pre order depth first search ...")
    dfs_vals = bst.depth_first_search('pre')
    print(f'DFS values: {dfs_vals}')

    print()
    print("post order depth first search ...")
    dfs_vals = bst.depth_first_search('post')
    print(f'DFS values: {dfs_vals}')

    print()
    val = 13
    print(f"searching for node with value of {val}")
    node = bst.find(val)
    if node:
        node.print()
    else:
        print(f"Node not found with value of {val}")
        

    print()
    val = 54
    print(f"searching for node with value of {val}")
    node = bst.find(val)
    if node:
        node.print()
    else:
        print(f"Node not found with value of {val}")


    val = 888
    if bst.remove(val):
        print(f"{val} was removed")
    else:
        print(f"{val} wasn't found")
    bst.print_tree()

    val = 11
    if bst.remove(val):
        print(f"{val} was removed")
        bst.balance()
    else:
        print(f"{val} wasn't found")
    bst.print_tree()
        
    val = 17
    if bst.remove(val):
        print(f"{val} was removed")
        bst.balance()
    else:
        print(f"{val} wasn't found")
    bst.print_tree()


    arr = [1, 12, 54, 83] + [3*x for x in range(20)]
    bst.insert_list(arr)
    bst.print_tree()
    bst.balance()
    bst.print_tree()
    