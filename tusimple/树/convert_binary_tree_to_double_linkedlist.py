class BtoDll:
    def __init__(self):
        self.head = None
        self.tail = None
 
    def convert(self, root):
       
        # Base case
        if root is None:
            return
           
        # Recursively convert left subtree
        self.convert(root.left)
         
        # Now convert this node
        node = root
        if self.head is None:
            self.head = node
        else:
            self.tail.right = node
            node.left = self.tail
        self.tail = node
         
        # Finally convert right subtree
        self.convert(root.right)
        return self.head