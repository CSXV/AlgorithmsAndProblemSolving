public class TreeNode<T>
{
  public T Value { get; set; }
  public List<TreeNode<T>> children { get; set; }

  public TreeNode(T Value)
  {
    this.Value = Value;
    this.children = new List<TreeNode<T>>();
  }

  public void AddChild(TreeNode<T> child)
  {
    children.Add(child);
  }

  public TreeNode<T> Find(T value)
  {
    if (EqualityComparer<T>.Default.Equals(Value, value)) return this;

    foreach (var child in children)
    {
      var found = child.Find(value);
      if (found != null) return found;
    }

    return null;
  }
}

public class Tree<T>
{
  public TreeNode<T> Root { get; set; }

  public Tree(T rootValue)
  {
    Root = new TreeNode<T>(rootValue);
  }

  public void PrintTree(string indint = " ")
  {
    _PrintTree(this.Root);
  }

  private void _PrintTree(TreeNode<T> node, string indint = " ")
  {
    Console.WriteLine(indint + node.Value);

    foreach (var child in node.children)
    {
      _PrintTree(child, indint + " ");
    }
  }
}

public class Program
{
  static void Main()
  {
    var companyTree = new Tree<string>("CEO");

    var finance = new TreeNode<string>("CFO");
    var tech = new TreeNode<string>("CTO");
    var markiting = new TreeNode<string>("CMO");

    companyTree.Root.AddChild(finance);
    companyTree.Root.AddChild(tech);
    companyTree.Root.AddChild(markiting);

    finance.AddChild(new TreeNode<string>("Acountant"));
    tech.AddChild(new TreeNode<string>("developer"));
    tech.AddChild(new TreeNode<string>("UX and UI"));
    markiting.AddChild(new TreeNode<string>("social media manager"));

    var search = companyTree.Root.Find("CTO");

    if (search != null)
      Console.WriteLine("found it :)");
    else
      Console.WriteLine("not found");

    companyTree.PrintTree();
  }
}
