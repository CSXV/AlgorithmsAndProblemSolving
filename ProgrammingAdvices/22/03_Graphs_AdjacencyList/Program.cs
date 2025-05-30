public class Graph
{
    private Dictionary<string, int> _VertexDictionary;
    private Dictionary<string, List<Tuple<string, int>>> _AdjacencyList;
    private int _NumberOfVertices;
    private enGraphDirection _GraphType = enGraphDirection.unDirected;

    public enum enGraphDirection
    {
        unDirected = 1,
        Directed = 2,
    }

    public Graph(List<string> vertices, enGraphDirection graphType)
    {
        this._GraphType = graphType;
        this._NumberOfVertices = vertices.Count;
        this._AdjacencyList = new Dictionary<string, List<Tuple<string, int>>>();
        this._VertexDictionary = new Dictionary<string, int>();

        for (int i = 0; i < vertices.Count; i++)
        {
            _VertexDictionary[vertices[i]] = i;
            _AdjacencyList[vertices[i]] = new List<Tuple<string, int>>();
        }
    }

    public void AddEdge(string A, string B, int weight)
    {
        if (_VertexDictionary.ContainsKey(A) && _VertexDictionary.ContainsKey(B))
        {
            int sourceIndex = _VertexDictionary[A];
            int DestinationIndex = _VertexDictionary[B];

            // _AdjacencyMatrix[sourceIndex, DestinationIndex] = weight;
            _AdjacencyList[A].Add((new Tuple<string, int>(B, weight)));

            if (_GraphType == enGraphDirection.unDirected)
            {
                _AdjacencyList[B].Add((new Tuple<string, int>(A, weight)));
            }
        }
        else
        {
            Console.WriteLine($"Ignored: InValid vertices: {A}->{B}.");
        }
    }

    public void RemoveEdge(string A, string B)
    {
        if (_VertexDictionary.ContainsKey(A) && _VertexDictionary.ContainsKey(B))
        {
            _AdjacencyList[A].RemoveAll(edge => edge.Item1 == B);

            if (_GraphType == enGraphDirection.unDirected)
            {
                _AdjacencyList[B].RemoveAll(edge => edge.Item1 == A);
            }
        }
        else
        {
            Console.WriteLine("Invalid vertices");
        }
    }

    public void DisplayGraph(string message)
    {
        Console.WriteLine(message);

        foreach (var source in _AdjacencyList)
        {
            Console.Write(source.Key + " -> ");

            foreach (var edge in source.Value)
            {
                Console.Write($"{edge.Item1}({edge.Item2}) ");
            }

            Console.WriteLine();
        }
    }

    public bool IsEdge(string A, string B)
    {
        if (_VertexDictionary.ContainsKey(A) && _VertexDictionary.ContainsKey(B))
        {
            foreach (var edge in _AdjacencyList[A])
            {
                return (edge.Item1 == B);
            }
        }

        return false;
    }

    public int GetOutDegree(string vertex)
    {
        int degree = 0;

        if (_VertexDictionary.ContainsKey(vertex))
        {
            degree = _AdjacencyList[vertex].Count;
        }

        return degree;
    }

    public int GetInDegree(string vertex)
    {
        int degree = 0;

        if (_VertexDictionary.ContainsKey(vertex))
        {
            foreach (var source in _AdjacencyList)
            {
                foreach (var edge in source.Value)
                {
                    if (edge.Item1 == vertex)
                        degree++;
                }
            }
        }

        return degree;
    }

    //
}

public class Program
{
    static void Main()
    {
        var vertices = new List<string> { "A", "B", "C", "D", "E" };

        Graph graph1 = new Graph(vertices, Graph.enGraphDirection.unDirected);

        graph1.AddEdge("A", "B", 1);
        graph1.AddEdge("A", "C", 1);
        graph1.AddEdge("B", "D", 1);
        graph1.AddEdge("B", "E", 1);
        graph1.AddEdge("C", "D", 1);
        graph1.AddEdge("D", "E", 1);

        graph1.DisplayGraph("Adjacency matrix:");

        if (graph1.IsEdge("A", "B"))
        {
            Console.WriteLine("YES, there is an edge between A and B");
        }
        else
        {
            Console.WriteLine("NO, there is no edge between A and B");
        }

        if (graph1.IsEdge("A", "E"))
        {
            Console.WriteLine("YES, there is an edge between A and E");
        }
        else
        {
            Console.WriteLine("NO, there is no edge between A and E");
        }

        Console.WriteLine("out degree for A: " + graph1.GetOutDegree("A"));

        //
    }
}
