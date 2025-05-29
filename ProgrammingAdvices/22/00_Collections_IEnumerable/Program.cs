using System.Collections;

public class Person
{
  public string firstName;
  public string lastName;

  public Person(string firstName, string lastName)
  {
    this.firstName = firstName;
    this.lastName = lastName;
  }
}

public class customCollection<T> : IEnumerable<T>
{
  private List<T> items = new List<T>();

  public IEnumerator<T> GetEnumerator()
  {
    for (int i = 0; i < items.Count; i++)
    {
      yield return items[i];
    }
  }

  IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();

  public void Add(T item) => items.Add(item);
}

public class Program
{
  static void Main()
  {
    customCollection<Person> s = new customCollection<Person>() {
      new Person("foo", "foz"),
      new Person("bar", "bas"),
      new Person("qux", "qus"),
    };

    foreach (var item in s)
    {
      Console.WriteLine(item.firstName + ", " + item.lastName);
    }
  }
}
