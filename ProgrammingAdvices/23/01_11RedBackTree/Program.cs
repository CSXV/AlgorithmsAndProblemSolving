namespace program {
class RedBlackTree {
  private Node Root;

  private class Node {
    public int Value;
    public Node Right, Left, Parent;
    public bool IsRed = true; // new node are always red

    public Node(int value) { this.Value = value; }
  }

  public void Insert(int value) {
    Node newNode = new Node(value);

    if (Root == null) {
      Root = newNode;
      newNode.IsRed = false;
      return;
    }

    Node current = Root;
    Node parent = null;

    while (current != null) {
      parent = current;

      if (value < current.Value)
        current = current.Left;
      else
        current = current.Right;
    }

    newNode.Parent = parent;

    if (value < parent.Value)
      parent.Left = newNode;
    else
      parent.Right = newNode;

    // restore red-black properties
    FixInsert(newNode);
  }

  private void FixInsert(Node node) {
    Node parent = null;
    Node grandparent = null;

    while ((node != Root) && (node.IsRed) && (node.Parent.IsRed)) {
      parent = node.Parent;
      grandparent = parent.Parent;

      // if parent is left child of grandparent
      if (parent == grandparent.Left) {
        Node uncle = grandparent.Right;

        // case 01: uncle is red
        if (uncle != null && uncle.IsRed) {
          grandparent.IsRed = true;
          parent.IsRed = false;
          uncle.IsRed = false;
          node = grandparent;
        } else {
          // case 02: triangle
          if (node == parent.Right) {
            LeftRotate(parent);
            node = parent;
            parent = node.Parent;
          }

          // case 03: Line
          // 03.1 rotate grandparent
          RightRotate(grandparent);
          // 03.2 swap colors
          bool tmp = parent.IsRed;
          parent.IsRed = grandparent.IsRed;
          grandparent.IsRed = tmp;
          node = parent;
        }
      } else { // if parent is rigth child of grandparent
        Node uncle = grandparent.Left;

        // case 01: uncle is red
        if (uncle != null && uncle.IsRed) {
          grandparent.IsRed = true;
          parent.IsRed = false;
          uncle.IsRed = false;
          node = grandparent;
        } else {
          // case 02: triangle
          if (node == parent.Left) {
            RightRotate(parent);
            node = parent;
            parent = node.Parent;
          }

          // case 03: Line
          // 03.1 rotate grandparent
          LeftRotate(grandparent);
          // 03.2 swap colors
          bool tmp = parent.IsRed;
          parent.IsRed = grandparent.IsRed;
          grandparent.IsRed = tmp;
          node = parent;
        }
      }
    }

    // root must always be black
    Root.IsRed = false;
  }

  private void RightRotate(Node node) {
    Node left = node.Left;
    node.Left = left.Right;

    if (node.Left != null)
      node.Left.Parent = node;

    left.Parent = node.Parent;

    if (node.Parent == null)
      Root = left;
    else if (node == node.Parent.Right)
      node.Parent.Right = left;
    else
      node.Parent.Left = left;

    left.Right = node;
    node.Parent = left;
  }

  private void LeftRotate(Node node) {
    Node right = node.Right;
    node.Right = right.Left;

    if (node.Right != null)
      node.Right.Parent = node;

    right.Parent = node.Parent;

    if (node.Parent == null)
      Root = right;
    else if (node == node.Parent.Left)
      node.Parent.Left = right;
    else
      node.Parent.Right = right;

    right.Left = node;
    node.Parent = right;
  }

  public void PrintTree() { PrintTree(Root, "", true); }

  private void PrintTree(Node node, string indent, bool last) {
    if (node != null) {
      Console.Write(indent);

      if (last) {
        Console.Write("R----");
        indent += "   ";
      } else {
        Console.Write("L----");
        indent += "|  ";
      }

      var color = node.IsRed ? "🟥" : "⬛";
      Console.WriteLine($"[{node.Value}{color}]");

      PrintTree(node.Left, indent, false);
      PrintTree(node.Right, indent, true);
    }
  }
}

class Program {
  static void Main(string[] args) {
    RedBlackTree tree = new RedBlackTree();
    int[] values = { 10, 20, 30, 15, 25, 35, 5, 19 };

    foreach (var value in values) {
      Console.WriteLine($"inserting {value} into the Red-Black tree.");
      tree.Insert(value);
      tree.PrintTree();
      Console.WriteLine("---------------------------------------");
    }
  }
}
}
