# All trees are graphs, not all graphs are trees

# Graphs can also be implemented with dicts and lists:
# {
#     'a': ['b', 'c'],
#     'b': ['a', 'd'],
#     'c': ['a'],
#     'd': ['b'],
# }

class Node():
    def __init__(self, val):
        self.data = val
        self.children = []

class Graph():
    def __init__(self):
        self._nodes = []

    def print(self):
        print()
        print("This is a Graph")
        for n in self._nodes:
            children_data = ', '.join([str(x.data) for x in n.children])
            print(f"{n.data}: [{children_data}]")

    def add_vertex(self, val):
        new_node = Node(val)
        self._nodes.append(new_node)

    def add_edge(self, a, b):
        # make connection from a to b
        # bidirectional graphs add from b to a also
        if a == b:
            return
        node_a = self._get_node(a)
        node_b = self._get_node(b)
        if not node_a:
            raise ValueError(f"Node does not exist with value of {a}")
        if not node_b:
            raise ValueError(f"Node does not exist with value of {b}")
        node_a.children.append(node_b)
        node_b.children.append(node_a)
        
    def remove_edge(self, a, b):
        # make connection from a to b
        # bidirectional graphs add from b to a also
        if a == b:
            return
        node_a = self._get_node(a)
        node_b = self._get_node(b)
        if not node_a:
            raise ValueError(f"Node does not exist with value of {a}")
        if not node_b:
            raise ValueError(f"Node does not exist with value of {b}")
        if node_b in node_a.children:
            node_a.children.remove(node_b)
        if node_a in node_b.children:
            node_b.children.remove(node_a)

    def neighbors(self, val):
        node = self._get_node(val)
        if not node:
            return None
        return node.children

    def _get_node(self, val):
        for n in self._nodes:
            if n.data == val:
                return n
        return

    def breadth_first_search(self, start, goal) -> int:
        """Look for goal (value) and return number of steps to get there.
        
        Return -1 if not found
        """
        # This will find the shortest distance!
        if start == goal:
            return 0

        # NOTE: Make sure not to visit a node more than once
        if len(self._nodes) == 0:
            return
        visited = set()
        start_node = self._get_node(start)
        level = 0
        queue = [(start_node, level)]
        while(len(queue) > 0):
            (curr, level) = queue[0]
            visited.add(curr)
            queue = queue[1:]
            if curr.data == goal:
                return level
            for child in curr.children:
                if child not in visited:
                    queue.append((child, level+1))
        return -1



if __name__ == "__main__":
    g = Graph()
    g.add_vertex(1)
    g.add_vertex(2)
    g.add_vertex(3)
    g.add_vertex(4)
    g.add_vertex(5)
    g.add_vertex(6)
    g.add_vertex(7)
    g.add_vertex(8)
    g.add_vertex(9)
    g.add_edge(1, 2)
    g.add_edge(1, 4)
    g.add_edge(2, 3)
    g.add_edge(3, 6)
    g.add_edge(6, 7)
    g.add_edge(7, 8)
    g.print()

    a, b = 1, 3
    num_steps = g.breadth_first_search(a, b)
    print(f'It takes {num_steps} steps to get from {a} to {b}')

    a, b = 1, 1
    num_steps = g.breadth_first_search(a, b)
    print(f'It takes {num_steps} steps to get from {a} to {b}')

    a, b = 1, 5
    num_steps = g.breadth_first_search(a, b)
    print(f'It takes {num_steps} steps to get from {a} to {b}')

    a, b = 1, 8
    num_steps = g.breadth_first_search(a, b)
    print(f'It takes {num_steps} steps to get from {a} to {b}')