using System.Collections;

public class Person : IComparable<Person>
{
  public string firstName { get; set; }
  public int Age { get; set; }

  public Person(string firsname, int age)
  {
    this.firstName = firsname;
    this.Age = age;
  }

  public int CompareTo(Person otherPeron)
  {
    if (otherPeron == null) return 1;

    return this.Age.CompareTo(otherPeron.Age);
  }

  public override string ToString()
  {
    return $"{firstName}, {Age} years old";
  }
}

public class Program
{
  static void Main()
  {
    List<Person> people = new List<Person> {
    new Person("foo", 21),
    new Person("bar", 20),
    new Person("baz", 30),
    new Person("qux", 28),
    };

    people.Sort();

    foreach (var Person in people)
    {
      Console.WriteLine(Person.ToString());
    }
  }
}
