namespace program {
class AVLNode {
  public int Value { get; set; }
  public int Height { get; set; }

  public AVLNode Right { get; set; }
  public AVLNode Left { get; set; }

  public AVLNode(int value) {
    this.Value = value;
    this.Height = 1;
  }
}

class AVLTree {
  private AVLNode Root;

  public void Insert(int value) { Root = Insert(Root, value); }

  private AVLNode Insert(AVLNode node, int value) {
    if (node == null) {
      return new AVLNode(value);
    }

    if (value < node.Value) {
      node.Left = Insert(node.Left, value);
    } else if (value > node.Value) {
      node.Right = Insert(node.Right, value);
    } else
      return node;

    UpdateHeight(node);

    return Balance(node);
  }

  private void UpdateHeight(AVLNode node) {
    node.Height = 1 + Math.Max(Height(node.Left), Height(node.Right));
  }

  private int Height(AVLNode node) { return node != null ? node.Height : 0; }

  private int GetBalanceFactor(AVLNode node) {
    return (node != null) ? Height(node.Left) - Height(node.Right) : 0;
  }

  private AVLNode Balance(AVLNode node) {
    int BalanceFactor = GetBalanceFactor(node);

    if (BalanceFactor < -1 && GetBalanceFactor(node.Right) <= 0) {
      return LeftRotate(node);
    }

    if (BalanceFactor > 1 && GetBalanceFactor(node.Left) >= 0) {
      return RightRotate(node);
    }

    if (BalanceFactor > 1 && GetBalanceFactor(node.Left) < 0) {
      node.Left = LeftRotate(node.Left);
      return RightRotate(node);
    }

    if (BalanceFactor < -1 && GetBalanceFactor(node.Right) > 0) {
      node.Right = RightRotate(node.Right);
      return LeftRotate(node);
    }

    return node;
  }

  private AVLNode RightRotate(AVLNode node) {
    AVLNode NewRoot = node.Left;
    AVLNode OriginalRightChild = NewRoot.Right;

    NewRoot.Right = node;
    node.Left = OriginalRightChild;

    UpdateHeight(node);
    UpdateHeight(NewRoot);

    return NewRoot;
  }

  private AVLNode LeftRotate(AVLNode node) {
    AVLNode NewRoot = node.Right;
    AVLNode OriginalLeftChild = NewRoot.Left;

    NewRoot.Left = node;
    node.Right = OriginalLeftChild;

    UpdateHeight(node);
    UpdateHeight(NewRoot);

    return NewRoot;
  }

  public void PrintTree() { PrintTree(Root, "", true); }

  private void PrintTree(AVLNode node, string indent, bool last) {
    if (node != null) {
      Console.Write(indent);

      if (last) {
        Console.Write("R----");
        indent += "     ";
      } else {
        Console.Write("L----");
        indent += "|    ";
      }

      Console.WriteLine(node.Value);

      PrintTree(node.Left, indent, false);
      PrintTree(node.Right, indent, true);
    }
  }
}

class Program {
  static void Main(string[] args) {
    AVLTree tree = new AVLTree();
    int[] values = { 10, 20, 30, 40, 50, 25 };

    foreach (var value in values) {
      Console.WriteLine($"inserting {value} into the AVL tree.");
      tree.Insert(value);
      tree.PrintTree();
      Console.WriteLine("\n---------------------------------------\n");
    }
  }
}
}
