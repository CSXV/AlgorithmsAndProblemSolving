using Microsoft.Win32;

public class Generic
{
  private string keyPath { get; set; }
  private string ValueName { get; set; }
  private string ValueData { get; set; }

  public Generic(string path, string name, string data)
  {
    this.keyPath = path;
    this.ValueName = name;
    this.ValueData = data;
  }

  public void WriteToReg()
  {
    try
    {
      Registry.SetValue(keyPath, ValueName, ValueData, RegistryValueKind.String);
      System.Console.WriteLine($"Value {ValueName} successfully written to the registry");
    }
    catch (Exception ex)
    {
      System.Console.WriteLine($"An error: {ex.Message}");
    }
  }

  public void ReadFromReg()
  {
    try
    {
      string Value = Registry.GetValue(keyPath, ValueName, null) as string;
      if (Value != null)
      {
        System.Console.WriteLine($"The value for {ValueName} is : {Value}");
      }
      else
      {
        System.Console.WriteLine($"No value found");
      }
    }
    catch (System.Exception ex)
    {
      System.Console.WriteLine($"Error: {ex.Message}");
      throw;
    }
  }

  public void DeleteFromReg()
  {
    try
    {
      using (RegistryKey baseKey = RegistryKey.OpenBaseKey(RegistryHive.CurrentUser, RegistryView.Registry64))
      {
        string TrimmedKey = keyPath.Remove(0, 18);

        using (RegistryKey key = baseKey.OpenSubKey(TrimmedKey, true))
        {
          if (key != null)
          {
            key.DeleteValue(ValueName);
            System.Console.WriteLine($"successfully deleted value {ValueName}");
          }
          else
          {
            System.Console.WriteLine($"Key {keyPath} not found");
          }
        }
      }
    }
    catch (System.Exception ex)
    {
      System.Console.WriteLine($"Error: {ex.Message}");
      throw;
    }
  }
}

class Program
{
  static void Main(string[] args)
  {
    Generic gen = new Generic(@"HKEY_CURRENT_USER\SOFTWARE\YourSoftware", "YourValue", "YourName");

    gen.WriteToReg();
    gen.ReadFromReg();

    System.Console.WriteLine("Deleting value...");
    gen.DeleteFromReg();
    gen.ReadFromReg();
  }
}
