public class BinaryTreeNode<T>
{
    public T Value { get; set; }
    public BinaryTreeNode<T> Left { get; set; }
    public BinaryTreeNode<T> Right { get; set; }

    public BinaryTreeNode(T Value)
    {
        this.Value = Value;
        this.Right = null;
        this.Left = null;
    }
}

public class BinaryTree<T>
{
    public BinaryTreeNode<T> Root { get; set; }

    public BinaryTree()
    {
        this.Root = null;
    }

    public void Add(T value)
    {
        var NewNode = new BinaryTreeNode<T>(value);

        if (Root == null)
        {
            Root = NewNode;
            return;
        }

        Queue<BinaryTreeNode<T>> queue = new Queue<BinaryTreeNode<T>>();
        queue.Enqueue(Root);

        while (queue.Count > 0)
        {
            var current = queue.Dequeue();

            if (current.Left == null)
            {
                current.Left = NewNode;
                break;
            }
            else
            {
                queue.Enqueue(current.Left);
            }

            if (current.Right == null)
            {
                current.Right = NewNode;
                break;
            }
            else
            {
                queue.Enqueue(current.Right);
            }
        }
    }

    public void PrintTree()
    {
        _PrintTree(Root, 0);
    }

    private void _PrintTree(BinaryTreeNode<T> node, int space)
    {
        int Count = 2;
        if (node == null)
            return;

        space += Count;
        _PrintTree(node.Right, space);

        for (int i = Count; i < space; i++)
            Console.Write(" ");

        Console.WriteLine(node.Value);
        _PrintTree(node.Left, space);
    }

    public void PreOrderTraversal()
    {
        _PreOrderTraversal(Root);
    }

    private void _PreOrderTraversal(BinaryTreeNode<T> node)
    {
        if (node != null)
            Console.Write(node.Value + " ");

        if (node.Left != null)
            _PreOrderTraversal(node.Left);

        if (node.Right != null)
            _PreOrderTraversal(node.Right);
    }

    public void PostOrderTraversal()
    {
        _PostOrderTraversal(Root);
    }

    private void _PostOrderTraversal(BinaryTreeNode<T> node)
    {
        if (node.Left != null)
            _PostOrderTraversal(node.Left);

        if (node.Right != null)
            _PostOrderTraversal(node.Right);

        if (node != null)
            Console.Write(node.Value + " ");
    }

    public void InOrderTraversal()
    {
        _InOrderTraversal(Root);
    }

    private void _InOrderTraversal(BinaryTreeNode<T> node)
    {
        if (node.Left != null)
            _InOrderTraversal(node.Left);

        if (node != null)
            Console.Write(node.Value + " ");

        if (node.Right != null)
            _InOrderTraversal(node.Right);
    }
}

public class Program
{
    static void Main()
    {
        BinaryTree<int> Root = new BinaryTree<int>();

        Root.Add(1);
        Root.Add(2);
        Root.Add(3);
        Root.Add(4);
        Root.Add(5);
        Root.Add(6);
        Root.Add(7);
        // Root.Add(8);
        // Root.Add(9);
        // Root.Add(10);
        // Root.Add(11);

        Root.PrintTree();

        Root.PreOrderTraversal();
        Console.WriteLine();

        Root.PostOrderTraversal();
        Console.WriteLine();

        Root.InOrderTraversal();
        Console.WriteLine();
    }
}
