public class Graph
{
    private Dictionary<string, int> _VertexDictionary;
    private int[,] _AdjacencyMatrix;
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
        this._AdjacencyMatrix = new int[_NumberOfVertices, _NumberOfVertices];
        this._VertexDictionary = new Dictionary<string, int>();

        for (int i = 0; i < vertices.Count; i++)
        {
            _VertexDictionary[vertices[i]] = i;
        }
    }

    public void AddEdge(string A, string B, int weight)
    {
        if (_VertexDictionary.ContainsKey(A) && _VertexDictionary.ContainsKey(B))
        {
            int sourceIndex = _VertexDictionary[A];
            int DestinationIndex = _VertexDictionary[B];

            _AdjacencyMatrix[sourceIndex, DestinationIndex] = weight;

            if (_GraphType == enGraphDirection.unDirected)
            {
                _AdjacencyMatrix[DestinationIndex, sourceIndex] = weight;
            }
        }
        else
        {
            Console.WriteLine($"Ignored: InValid vertices: {A}->{B}.");
        }
    }

    public void DisplayGraph(string message)
    {
        Console.WriteLine(message);

        Console.WriteLine("  " + string.Join(" ", _VertexDictionary.Keys));

        foreach (var source in _VertexDictionary)
        {
            Console.Write(source.Key + " ");

            for (int j = 0; j < _NumberOfVertices; j++)
            {
                Console.Write(_AdjacencyMatrix[source.Value, j] + " ");
            }

            Console.WriteLine();
        }
    }

    public bool IsEdge(string A, string B)
    {
        if (_VertexDictionary.ContainsKey(A) && _VertexDictionary.ContainsKey(B))
        {
            int sourceIndex = _VertexDictionary[A];
            int DestinationIndex = _VertexDictionary[B];

            return _AdjacencyMatrix[sourceIndex, DestinationIndex] > 0;
        }

        return false;
    }

    public int GetOutDegree(string vertex)
    {
        int degree = 0;

        if (_VertexDictionary.ContainsKey(vertex))
        {
            int vertexIndex = _VertexDictionary[vertex];

            for (int i = 0; i < _NumberOfVertices; i++)
            {
                if (_AdjacencyMatrix[vertexIndex, i] > 0)
                    degree++;
            }
        }

        return degree;
    }

    public int GetInDegree(string vertex)
    {
        int degree = 0;

        if (_VertexDictionary.ContainsKey(vertex))
        {
            int vertexIndex = _VertexDictionary[vertex];

            for (int i = 0; i < _NumberOfVertices; i++)
            {
                if (_AdjacencyMatrix[i, vertexIndex] > 0)
                    degree++;
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
