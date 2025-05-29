using System.Collections;

public class customCollection<T> : ICollection<T>
{
  private List<T> items = new List<T>();

  IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();

  public IEnumerator<T> GetEnumerator()
  {
    return items.GetEnumerator();
  }

  public void Add(T item) => items.Add(item);

  public bool IsReadOnly => false;

  public int Count => items.Count;

  public bool Remove(T item) => items.Remove(item);

  public void CopyTo(T[] array, int index)
  {
    items.CopyTo(array, index);
  }

  public void Clear() => items.Clear();

  public bool Contains(T item) => items.Contains(item);

  //
}

public class Program
{
  static void Main()
  {
    customCollection<string> s = new customCollection<string>() {
      "banaba",
      "apple",
      "orange",
    };

    Console.WriteLine(s.Contains("apple"));
    Console.WriteLine(s.Contains("cherry"));

    if (s.Remove("orange"))
    {
      Console.WriteLine("item removed");
    }
    else
    {
      Console.WriteLine("item not found");
    }

    foreach (var item in s)
    {
      Console.WriteLine(item);
    }
  }
}
