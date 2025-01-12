namespace program {
public class BinaryTreeNode<T>
    where T : IComparable<T> {
  public T Value { get; set; }
  public BinaryTreeNode<T> Left { get; set; }
  public BinaryTreeNode<T> Right { get; set; }

  public BinaryTreeNode(T value) {
    Value = value;
    Left = null;
    Right = null;
  }
}

public class BinaryTree<T>
    where T : IComparable<T> {
  public BinaryTreeNode<T> Root { get; private set; }

  public BinaryTree() { Root = null; }

  public void Insert(T value) { Root = Insert(Root, value); }

  private BinaryTreeNode<T> Insert(BinaryTreeNode<T> node, T value) {
    // root
    if (node == null) {
      return new BinaryTreeNode<T>(value);
      // left
    } else if (value.CompareTo(node.Value) < 0) {
      node.Left = Insert(node.Left, value);
      // right
    } else if (value.CompareTo(node.Value) > 0) {
      node.Right = Insert(node.Right, value);
    }

    return node;
  }

  public void PrintTree() { PrintTree(Root, 0); }

  private void PrintTree(BinaryTreeNode<T> root, int space) {
    int COUNT = 10;

    if (root == null) {
      return;
    }

    space += COUNT;

    PrintTree(root.Right, space);

    Console.WriteLine();
    for (int i = COUNT; i < space; i++) {
      Console.Write(" ");
    }

    Console.WriteLine(root.Value);

    PrintTree(root.Left, space);
  }

  // My Method
  public void Search(T value) {
    Console.WriteLine($"Does the tree contains {value}? {Search(Root,
      value)}");
  }

  private bool Search(BinaryTreeNode<T> node, T x) {
    bool y = false;

    if (node != null) {
      if (x.Equals(node.Value)) {
        return y = true;
      }
      if (x.CompareTo(node.Value) < 0) {
        y = Search(node.Left, x);
      }
      if (x.CompareTo(node.Value) > 0) {
        y = Search(node.Right, x);
      }
    }

    return y;
  }

  // Another Method
  /*
    public bool Search(T value) { return Search(Root, value) != null; }

    private BinaryTreeNode<T> Search(BinaryTreeNode<T> node, T value) {
      if (node == null || node.Value.Equals(value))
        return node;

      if (value.CompareTo(node.Value) < 0)
        return Search(node.Left, value);

      if (value.CompareTo(node.Value) > 0)
        return Search(node.Right, value);

      return null;
    }
    */
}

class Program {
  static void Main() {
    var binaryTree = new BinaryTree<int>();

    binaryTree.Insert(45);
    binaryTree.Insert(15);
    binaryTree.Insert(79);
    binaryTree.Insert(90);
    binaryTree.Insert(10);
    binaryTree.Insert(55);
    binaryTree.Insert(12);
    binaryTree.Insert(20);
    binaryTree.Insert(50);

    binaryTree.PrintTree();

    binaryTree.Search(10);
  }
}
}
