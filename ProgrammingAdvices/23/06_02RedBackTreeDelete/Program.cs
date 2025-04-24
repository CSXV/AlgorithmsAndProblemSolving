class RedBlackTree {
  private Node Root;

  public class Node {
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

  public Node Search(int value) { return Search(Root, value); }

  private Node Search(Node node, int value) {
    if (node == null || node.Value == value)
      return node;
    else if (value > node.Value)
      return Search(node.Right, value);
    else if (value < node.Value)
      return Search(node.Left, value);

    return null;
  }

  public bool Delete(int value) {
    Node nodeToDelete = Search(Root, value);

    if (nodeToDelete == null)
      return false;

    DeleteNode(nodeToDelete);
    return true;
  }

  private void DeleteNode(Node node) {
    Node nodeToFix = null, child = null, parent = null;
    bool originalColor = node.IsRed;

    if (node.Left == null) { // case 01: node has no left child
      child = node.Right;
      Transplant(node, child);
    } else if (node.Right == null) { // case 02: node has no right child
      child = node.Left;
      Transplant(node, child);
    } else { // case 03: node have both children
      Node successor = Minimum(node.Right);
      originalColor = successor.IsRed;
      child = successor.Right;

      if (successor.Parent == node) {
        if (child != null)
          child.Parent = successor;
      } else {
        Transplant(successor, successor.Right);
        successor.Right = node.Right;
        successor.Right.Parent = successor;
      }

      Transplant(node, successor);
      successor.Left = node.Left;
      successor.Left.Parent = successor;
      successor.IsRed = node.IsRed;
    }

    // if node was black, then we get double black
    if (!originalColor && child != null) {
      FixDelete(child);
    }
  }

  private void Transplant(Node target, Node with) {
    if (target.Parent == null)
      Root = with;
    else if (target == target.Parent.Left)
      target.Parent.Left = with;
    else
      target.Parent.Right = with;

    if (with != null)
      with.Parent = target.Parent;
  }

  private Node Minimum(Node node) {
    while (node.Left != null) {
      node = node.Left;
    }

    return node;
  }

  private void FixDelete(Node node) {
    while (node != Root && !node.IsRed) {
      // IF NODE IS LEFT CHILD OF PARENT
      if (node == node.Parent.Left) {
        Node sibling = node.Parent.Right;

        // case 01
        if (sibling.IsRed) {
          sibling.IsRed = false;
          node.Parent.IsRed = true;
          LeftRotate(node.Parent);
          sibling = node.Parent.Right;
        }

        // case 02
        // case 02.1: both sibling children are black
        if (!sibling.Left.IsRed && !sibling.Right.IsRed) {
          sibling.IsRed = true;
          node = node.Parent;
        } else {
          // case 02.2: left child of sibling is red
          if (!sibling.Right.IsRed) {
            sibling.Left.IsRed = false;
            sibling.IsRed = true;
            RightRotate(sibling);
            sibling = node.Parent.Right;
          }

          // case 02.1: right child of sibling is red
          sibling.IsRed = node.Parent.IsRed;
          node.Parent.IsRed = false;
          sibling.Right.IsRed = false;
          LeftRotate(node.Parent);
          node = Root;
        }
      } else { // IF NODE IS RIGHT CHILD OF PARENT
        Node sibling = node.Parent.Left;

        // case 01
        if (sibling.IsRed) {
          sibling.IsRed = false;
          node.Parent.IsRed = true;
          RightRotate(node.Parent);
          sibling = node.Parent.Left;
        }

        // case 02
        // case 02.1: both sibling children are black
        if (!sibling.Left.IsRed && !sibling.Right.IsRed) {
          sibling.IsRed = true;
          node = node.Parent;
        } else {
          // case 02.2: left child of sibling is red
          if (!sibling.Left.IsRed) {
            sibling.Right.IsRed = false;
            sibling.IsRed = true;
            LeftRotate(sibling);
            sibling = node.Parent.Left;
          }

          // case 02.1: right child of sibling is red
          sibling.IsRed = node.Parent.IsRed;
          node.Parent.IsRed = false;
          sibling.Left.IsRed = false;
          RightRotate(node.Parent);
          node = Root;
        }
      }
    }

    node.IsRed = false;
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
  public static void PrintLine() {
    Console.WriteLine("---------------------------------------");
  }

  static void Main(string[] args) {
    RedBlackTree tree = new RedBlackTree();
    int[] values = { 10, 20, 30, 15, 25, 35, 5, 19 };

    ///////////////////////////////////////////////////////////////////
    foreach (var value in values) {
      /*Console.WriteLine($"inserting {value} into the Red-Black tree.");*/
      tree.Insert(value);
      /*PrintLine();*/
      /*tree.PrintTree();*/
    }

    tree.PrintTree();
    PrintLine();

    ///////////////////////////////////////////////////////////////////
    int searchValue = 10;
    var s = tree.Search(searchValue);

    if (s != null) {
      Console.WriteLine(
          $"[{searchValue}] found with color [{(s.IsRed ? "🟥" : "⬛")}] :)");
    } else {
      Console.WriteLine($"[{searchValue}] not Found :(");
    }

    PrintLine();

    ///////////////////////////////////////////////////////////////////
    int delete = 10;
    if (tree.Delete(delete)) {
      Console.WriteLine($"after deleting {delete}:");
    } else {
      Console.WriteLine($"node {delete} not found");
    }

    tree.PrintTree();
    PrintLine();

    ///////////////////////////////////////////////////////////////////
  }
}
