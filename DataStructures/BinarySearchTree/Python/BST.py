print("Binary Search Tree")

class node:
    def __init__(self,data):
        self.data=data
        self.left=[]
        self.right=[]

    def print_node(self):
        print(self.data)
        if(self.left):
            self.left.print_node()
        if(self.right):
            self.right.print_node()

root=node(8)

root.left=node(5)
root.left.left=node(3)
root.left.right=node(7)
root.left.right.left=node(6)



root.right=node(9)
root.right.right=node(12)
root.right.left=node(10)
root.right.left.right=node(11)

root.print_node()
