using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

[Serializable]
public class Person
{
  public string name { get; set; }
  public int Age { get; set; }
}

class Program
{
  static void Main(string[] args)
  {
    Person person = new Person { name = "foo", Age = 20 };

    //---------------------------------------------------
    BinaryFormatter ser = new BinaryFormatter();

    // Serializer
    using (FileStream stream = new FileStream("person.bin", FileMode.Create))
    {
      ser.Serialize(stream, person);
    }

    // Deserializer
    using (FileStream stream = new FileStream("Person.json", FileMode.Open))
    {
      Person dePerson = (Person)ser.Deserialize(stream);
      Console.WriteLine($"Name: {dePerson.name} | Age: {dePerson.Age}");
    }

    //
  }
}
