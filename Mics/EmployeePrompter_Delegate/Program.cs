public delegate bool Promotion(Employee emp);

public class Employee
{
  public int ID { get; set; }
  public string Name { get; set; }
  public string Gender { get; set; }
  public double Salary { get; set; }
  public int Experience { get; set; }

  public static void PromoteEmployee(List<Employee> employeesList, Promotion employeeEligible)
  {
    foreach (var emp in employeesList)
    {
      if (employeeEligible(emp))
      {
        Console.WriteLine($"Employee {emp.Name} promoted");
      }
    }
  }
  //
}

class Program
{
  public static void Main(string[] args)
  {
    Employee emp1 = new Employee() { ID = 1, Name = "Foo", Gender = "Male", Experience = 5, Salary = 1000 };
    Employee emp2 = new Employee() { ID = 2, Name = "Bar", Gender = "Female", Experience = 2, Salary = 2000 };
    Employee emp3 = new Employee() { ID = 3, Name = "Baz", Gender = "Male", Experience = 9, Salary = 3000 };

    List<Employee> employeesList = new List<Employee>();
    employeesList.Add(emp1);
    employeesList.Add(emp2);
    employeesList.Add(emp3);

    Promotion pro = new Promotion(Promote);
    Employee.PromoteEmployee(employeesList, pro);
  }

  public static bool Promote(Employee emp)
  {
    if (emp.Salary > 1000)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
}
