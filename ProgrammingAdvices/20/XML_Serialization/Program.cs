using System.IO;
using System.Xml.Serialization;

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
    XmlSerializer ser = new XmlSerializer(typeof(Person));

    // Serializer
    using (TextWriter writer = new StreamWriter("person.xml"))
    {
      ser.Serialize(writer, person);
    }

    // Deserializer
    using (TextReader reader = new StreamReader("person.xml"))
    {
      Person dePerson = (Person)ser.Deserialize(reader);
      System.Console.WriteLine($"Name: {dePerson.name} | Age: {dePerson.Age}");
    }

    //
  }
}
