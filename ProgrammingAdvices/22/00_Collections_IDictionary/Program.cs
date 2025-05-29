// using System.Collections;

public class customCollection<TKey, TValue> : Dictionary<TKey, TValue>
{
  private List<KeyValuePair<TKey, TValue>> _items = new List<KeyValuePair<TKey, TValue>>();

  public TValue this[TKey key]
  {
    get
    {
      foreach (var kvp in _items)
      {
        if (Equals(kvp.Key, key)) return kvp.Value;
      }

      throw new KeyNotFoundException("the given key is not found");
    }

    set
    {
      bool found = false;

      for (int i = 0; i < _items.Count; i++)
      {
        if (Equals(_items[i].Key, key))
        {
          _items[i] = new KeyValuePair<TKey, TValue>(key, value);
          found = true;
          break;
        }
      }

      if (!found) _items.Add(new KeyValuePair<TKey, TValue>(key, value));
    }
  }

  public ICollection<TKey> Keys => _items.ConvertAll(kvp => kvp.Key);
  public ICollection<TValue> Values => _items.ConvertAll(kvp => kvp.Value);

  public int Count => _items.Count;

  public bool IsReadOnly => false;

  public void Add(TKey key, TValue value)
  {
    foreach (var kvp in _items)
    {
      if (Equals(kvp.Key, key)) throw new ArgumentException("an element with the same key already exists");
    }

    _items.Add(new KeyValuePair<TKey, TValue>(key, value));
  }

  public void Add(KeyValuePair<TKey, TValue> item)
  {
    Add(item.Key, item.Value);
  }

  public void Clear() => _items.Clear();

  public bool Contains(KeyValuePair<TKey, TValue> item) => _items.Contains(item);

  public bool ContainsKey(TKey key)
  {
    foreach (var kvp in _items)
    {
      if (Equals(kvp.Key, key)) return true;
    }

    return false;
  }

  public void CopyTo(KeyValuePair<TKey, TValue>[] array, int index) => _items.CopyTo(array, index);

  // public int IndexOf(T item) => _items.IndexOf(item);

  // public void Insert(int index, T item) => _items.Insert(index, item);

  public bool Remove(TKey key)
  {
    for (int i = 0; i < _items.Count; i++)
    {
      if (Equals(_items[i].Key, key))
      {
        _items.RemoveAt(i);
        return true;
      }
    }

    return false;
  }

  public bool Remove(KeyValuePair<TKey, TValue> item) => _items.Remove(item);

  public bool TryGetValue(TKey key, out TValue value)
  {
    foreach (var kvp in _items)
    {
      if (Equals(kvp.Key, key))
      {
        value = kvp.Value;
        return true;
      }
    }

    value = default;
    return false;
  }

  public IEnumerator<KeyValuePair<TKey, TValue>> GetEnumerator() => _items.GetEnumerator();

  // IEnumerator IEnumerable.GetEnumerator() => _items.GetEnumerator();
}

public class Program
{
  static void Main()
  {
    customCollection<int, string> s = new customCollection<int, string>() { };
    s.Add(1, "Apple");
    s.Add(2, "Banana");
    s.Add(3, "Orange");
    s.Add(4, "Cherry");

    s.Remove(3);
    s[2] = "Melon";

    Console.WriteLine(s.ContainsValue("Banana"));
    Console.WriteLine(s.ContainsKey(1));

    foreach (var item in s)
    {
      Console.WriteLine($"{item.Key}, {item.Value}");
    }
  }
}
