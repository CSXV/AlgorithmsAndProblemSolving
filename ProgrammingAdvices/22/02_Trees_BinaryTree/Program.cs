public class BinaryTreeNode<T>
{
    public T Value { get; set; }
    public BinaryTreeNode<T> Left { get; set; }
    public BinaryTreeNode<T> Right { get; set; }

    public BinaryTreeNode(T Value)
    {
        this.Value = Value;
        Left = null;
        Right = null;
    }
}

public class BinaryTree<T>
{
    public BinaryTreeNode<T> Root { get; set; }

    public BinaryTree()
    {
        Root = null;
    }

    public void Insert(T value)
    {
        var newNode = new BinaryTreeNode<T>(value);

        if (Root == null)
        {
            Root = newNode;
            return;
        }

        Queue<BinaryTreeNode<T>> queue = new Queue<BinaryTreeNode<T>>();
        queue.Enqueue(Root);

        while (queue.Count > 0)
        {
            var current = queue.Dequeue();

            if (current.Left == null)
            {
                current.Left = newNode;
                break;
            }
            else
            {
                queue.Enqueue(current.Left);
            }

            if (current.Right == null)
            {
                current.Right = newNode;
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
        int count = 2;
        if (node == null)
            return;

        space += count;
        _PrintTree(node.Right, space);

        for (int i = 0; i < space; i++)
        {
            Console.Write(" ");
        }

        Console.WriteLine(node.Value);
        _PrintTree(node.Left, space);
    }
}

public class Program
{
    static void Main()
    {
        var binarytree = new BinaryTree<int>();
        binarytree.Insert(1);
        binarytree.Insert(4);
        binarytree.Insert(3);
        binarytree.Insert(8);
        binarytree.Insert(7);
        binarytree.Insert(9);

        binarytree.PrintTree();
    }
}
