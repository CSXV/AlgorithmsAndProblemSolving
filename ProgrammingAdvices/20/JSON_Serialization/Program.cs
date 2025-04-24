using System.IO;
using System.Runtime.Serialization.Json;

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
    DataContractJsonSerializer ser = new DataContractJsonSerializer(typeof(Person));

    // Serializer
    using (MemoryStream stream = new MemoryStream())
    {
      ser.WriteObject(stream, person);
      string jsonString = System.Text.Encoding.UTF8.GetString(stream.ToArray());

      File.WriteAllText("Person.json", jsonString);
    }

    // Deserializer
    using (FileStream stream = new FileStream("Person.json", FileMode.Open))
    {
      Person dePerson = (Person)ser.ReadObject(stream);
      Console.WriteLine($"Name: {dePerson.name} | Age: {dePerson.Age}");
    }

    //
  }
}
