using System.Collections;

public class customCollection<T> : List<T>
{
  private List<T> _items = new List<T>();

  public T this[int index]
  {
    get => _items[index];
    set => _items[index] = value;
  }

  public int Count => _items.Count;

  public bool IsReadOnly => false;

  public void Add(T item) => _items.Add(item);

  public void Clear() => _items.Clear();

  public bool Contains(T item) => _items.Contains(item);

  public void CopyTo(T[] array, int index) => _items.CopyTo(array, index);

  public int IndexOf(T item) => _items.IndexOf(item);

  public void Insert(int index, T item) => _items.Insert(index, item);

  public bool Remove(T item) => _items.Remove(item);

  public void RemoveAt(int index) => _items.RemoveAt(index);

  public IEnumerator<T> GetEnumerator() => _items.GetEnumerator();

  // IEnumerator IEnumerable.GetEnumerator() => _items.GetEnumerator();
}

public class Program
{
  static void Main()
  {
    customCollection<string> s = new customCollection<string>() {
      "Apple",
      "Banana",
      "Orange",
      "Cherry"
    };

    s.Add("Melon");
    s.Remove("Apple");

    Console.WriteLine(s.Contains("Banana"));
    Console.WriteLine(s.Contains("WaterMelon"));

    s.Insert(2, "WaterMelon");

    foreach (var item in s)
    {
      Console.WriteLine(item);
    }
  }
}
