class Node():
    def __init__(self, key: int) -> None:
        self._key = key
        self.parent = None
        self.left = None
        self.right = None
        self._color = 1
        self.value = None

    def __repr__(self) -> str:
        return "Key: " + str(self._key) + " Value: " + str(self.value)

    def get_color(self) -> str:
        return "black" if self._color == 0 else "red"

    def set_color(self, color: str) -> None:
        if color == "black":
            self._color = 0
        elif color == "red":
            self._color = 1
        else:
            raise Exception("Unknown color")

    def get_key(self) -> int:
        return self._key

    def is_red(self) -> bool:
        return self._color == 1

    def is_black(self) -> bool:
        return self._color == 0

    def is_null(self) -> bool:
        return self._key is None

    def depth(self) -> int:
        return 0 if self.parent is None else self.parent.depth() + 1

    @classmethod
    def null(cls):
        node = cls(0)
        node._key = None
        node.set_color("black")
        return node

class RedBlackTree():
    def __init__(self) -> None:
        self.TNULL = Node.null()
        self.root = self.TNULL
        self.size = 0
        self._iter_format = 0

    # Dunder Methods #
    def __iter__(self):
        if self._iter_format == 0:
            return iter(self.preorder())
        if self._iter_format == 1:
            return iter(self.inorder())
        if self._iter_format == 2:
            return iter(self.postorder())

    def __getitem__(self, key: int) -> int:
        return self.search(key).value

    def __setitem__(self, key: int, value: int) -> None:
        self.search(key).value = value

    # Setters and Getters #
    def get_root(self) -> Node:
        return self.root

    def set_iteration_style(self, style: str) -> None:
        if style == "pre":
            self._iter_format = 0
        elif style == "in":
            self._iter_format = 1
        elif style == "post":
            self._iter_format = 2
        else:
            raise Exception("Unknown style.")

    # Iterators #
    def preorder(self) -> list:
        return self.pre_order_helper(self.root)

    def inorder(self) -> list:
        return self.in_order_helper(self.root)

    def postorder(self) -> list:
        return self.post_order_helper(self.root)

    def pre_order_helper(self, node: Node) -> list:
        """
        Perform a preorder tree traversal starting at the
        given node.
        """
        output = []
        if not node.is_null():
            left = self.pre_order_helper(node.left)
            right = self.pre_order_helper(node.right)
            output.extend([node])
            output.extend(left)
            output.extend(right)
        return output

    def in_order_helper(self, node: Node) -> list:
        """
        Perform a inorder tree traversal starting at the
        given node.
        """
        output = []
        if not node.is_null():
            left = self.in_order_helper(node.left)
            right = self.in_order_helper(node.right)
            output.extend(left)
            output.extend([node])
            output.extend(right)
        return output

    def post_order_helper(self, node: Node) -> list:
        output = []
        if not node.is_null():
            left = self.post_order_helper(node.left)
            right = self.post_order_helper(node.right)
            output.extend(left)
            output.extend(right)
            output.extend([node])
        return output

    # Search the tree
    def search_tree_helper(self, node: Node, key: int) -> Node:
        if node.is_null() or key == node.get_key():
            return node

        if key < node.get_key():
            return self.search_tree_helper(node.left, key)
        return self.search_tree_helper(node.right, key)

    # Balancing the tree after deletion
    def delete_fix(self, x: Node) -> None:
        while x != self.root and x.is_black():
            if x == x.parent.left:
                s = x.parent.right
                if s.is_red():
                    s.set_color("black")
                    x.parent.set_color("red")
                    self.left_rotate(x.parent)
                    s = x.parent.right

                if s.left.is_black() and s.right.is_black():
                    s.set_color("red")
                    x = x.parent
                else:
                    if s.right.is_black():
                        s.left.set_color("black")
                        s.set_color("red")
                        self.right_rotate(s)
                        s = x.parent.right

                    s.set_color(x.parent.get_color())
                    x.parent.set_color("black")
                    s.right.set_color("black")
                    self.left_rotate(x.parent)
                    x = self.root
            else:
                s = x.parent.left
                if s.is_red():
                    s.set_color("black")
                    x.parent.set_color("red")
                    self.right_rotate(x.parent)
                    s = x.parent.left

                if s.left.is_black() and s.right.is_black():
                    s.set_color("red")
                    x = x.parent
                else:
                    if s.left.is_black():
                        s.right.set_color("black")
                        s.set_color("red")
                        self.left_rotate(s)
                        s = x.parent.left

                    s.set_color(x.parent.get_color())
                    x.parent.set_color("black")
                    s.left.set_color("black")
                    self.right_rotate(x.parent)
                    x = self.root
        x.set_color("black")

    def __rb_transplant(self, u: Node, v: Node) -> None:
        if u.parent is None:
            self.root = v
        elif u == u.parent.left:
            u.parent.left = v
        else:
            u.parent.right = v
        v.parent = u.parent

    # Node deletion
    def delete_node_helper(self, node: Node, key: int) -> None:
        z = self.TNULL
        while not node.is_null():
            if node.get_key() == key:
                z = node

            if node.get_key() <= key:
                node = node.right
            else:
                node = node.left

        if z.is_null():
            # print("Cannot find key in the tree")
            return

        y = z
        y_original_color = y.get_color()
        if z.left.is_null():
            # If no left child, just scoot the right subtree up
            x = z.right
            self.__rb_transplant(z, z.right)
        elif (z.right.is_null()):
            # If no right child, just scoot the left subtree up
            x = z.left
            self.__rb_transplant(z, z.left)
        else:
            y = self.minimum(z.right)
            y_original_color = y.get_color()
            x = y.right
            if y.parent == z:
                x.parent = y
            else:
                self.__rb_transplant(y, y.right)
                y.right = z.right
                y.right.parent = y

            self.__rb_transplant(z, y)
            y.left = z.left
            y.left.parent = y
            y.set_color(z.get_color())
        if y_original_color == "black":
            self.delete_fix(x)

        self.size -= 1

    # Balance the tree after insertion
    def fix_insert(self, node: Node) -> None:
        while node.parent.is_red():
            if node.parent == node.parent.parent.right:
                u = node.parent.parent.left
                if u.is_red():
                    u.set_color("black")
                    node.parent.set_color("black")
                    node.parent.parent.set_color("red")
                    node = node.parent.parent
                else:
                    if node == node.parent.left:
                        node = node.parent
                        self.right_rotate(node)
                    node.parent.set_color("black")
                    node.parent.parent.set_color("red")
                    self.left_rotate(node.parent.parent)
            else:
                u = node.parent.parent.right

                if u.is_red():
                    u.set_color("black")
                    node.parent.set_color("black")
                    node.parent.parent.set_color("red")
                    node = node.parent.parent
                else:
                    if node == node.parent.right:
                        node = node.parent
                        self.left_rotate(node)
                    node.parent.set_color("black")
                    node.parent.parent.set_color("red")
                    self.right_rotate(node.parent.parent)
            if node == self.root:
                break
        self.root.set_color("black")

    # Printing the tree
    def __print_helper(self, node: Node, indent: str, last: bool) -> None:
        if not node.is_null():
            print(indent, end='')
            if last:
                print("R----  ", end='')
                indent += "     "
            else:
                print("L----   ", end='')
                indent += "|    "

            s_color = "RED" if node.is_red() else "BLACK"
            print(str(node.get_key()) + "(" + s_color + ")")
            self.__print_helper(node.left, indent, False)
            self.__print_helper(node.right, indent, True)

    def search(self, key: int) -> Node:
        return self.search_tree_helper(self.root, key)

    def minimum(self, node: Node = None) -> Node:
        if node is None:
            node = self.root
        if node.is_null():
            return self.TNULL
        while not node.left.is_null():
            node = node.left
        return node

    def maximum(self, node: Node = None) -> Node:
        if node is None:
            node = self.root
        if node.is_null():
            return self.TNULL
        while not node.right.is_null():
            node = node.right
        return node

    def successor(self, x: Node) -> Node:
        if not x.right.is_null():
            return self.minimum(x.right)

        y = x.parent
        while not y.is_null() and x == y.right:
            x = y
            y = y.parent
        return y

    def predecessor(self,  x: Node) -> Node:
        if (not x.left.is_null()):
            return self.maximum(x.left)

        y = x.parent
        while not y.is_null() and x == y.left:
            x = y
            y = y.parent

        return y

    def left_rotate(self, x: Node) -> None:
        y = x.right
        x.right = y.left
        if not y.left.is_null():
            y.left.parent = x

        y.parent = x.parent
        if x.parent is None:
            self.root = y
        elif x == x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y
        y.left = x
        x.parent = y

    def right_rotate(self, x: Node) -> None:
        y = x.left
        x.left = y.right
        if not y.right.is_null():
            y.right.parent = x

        y.parent = x.parent
        if x.parent is None:
            self.root = y
        elif x == x.parent.right:
            x.parent.right = y
        else:
            x.parent.left = y
        y.right = x
        x.parent = y

    def insert(self, key: int) -> None:
        node = Node(key)
        node.left = self.TNULL
        node.right = self.TNULL
        node.set_color("red")

        y = None
        x = self.root

        while not x.is_null():
            y = x
            if node.get_key() < x.get_key():
                x = x.left
            else:
                x = x.right

        node.parent = y
        if y is None:
            self.root = node
        elif node.get_key() < y.get_key():
            y.left = node
        else:
            y.right = node

        self.size += 1

        if node.parent is None:
            node.set_color("black")
            return

        if node.parent.parent is None:
            return

        self.fix_insert(node)

    def delete(self, key: int) -> None:
        self.delete_node_helper(self.root, key)

    def print_tree(self) -> None:
        self.__print_helper(self.root, "", True)