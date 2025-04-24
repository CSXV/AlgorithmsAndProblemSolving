// this is the container class for the data that will be sent to the Subscribers
public class TempratureChangeEventArgs : EventArgs
{
  public double Current { get; }
  public double Prev { get; }
  public double Change { get; }

  public TempratureChangeEventArgs(double current, double prev)
  {
    this.Change = current - prev;
    this.Prev = prev;
    this.Current = current;
  }
}

public class Thermostate
{
  // New event delegate
  public event EventHandler<TempratureChangeEventArgs> TempChanged;

  private double _oldTemp;
  private double _currentTemp;

  public void SetTemperature(double newTemp)
  {
    if (newTemp != _currentTemp)
    {
      _oldTemp = _currentTemp;
      _currentTemp = newTemp;

      _OnTempChange(_oldTemp, _currentTemp);
    }
  }

  // put the data in the container class, to send it to the next stage below
  private void _OnTempChange(double OldTemp, double CurrentTemp)
  {
    OnTempChange(new TempratureChangeEventArgs(OldTemp, CurrentTemp));
  }

  // this will invoke the delegate to the Subscribers
  protected virtual void OnTempChange(TempratureChangeEventArgs e)
  {
    TempChanged?.Invoke(this, e);
  }
}

public class Display
{
  // this will Subscribe to the delegate
  public void Subscribe(Thermostate thermo)
  {
    thermo.TempChanged += HandleTempChange;
  }

  public void UnSubscribe(Thermostate thermo)
  {
    thermo.TempChanged -= HandleTempChange;
  }

  // PRINT SOME NOISE
  public void HandleTempChange(object sender, TempratureChangeEventArgs e)
  {
    Console.WriteLine($"Temprature changed:");
    Console.WriteLine($"Old   : {e.Prev}");
    Console.WriteLine($"New   : {e.Current}");
    Console.WriteLine($"Change: {e.Change}");
  }
}

// the main program is here
class Program
{
  public static void Main(string[] args)
  {
    // make an instance of the Thermostate
    Thermostate thermo = new Thermostate();

    // make an instance of Display
    Display dis = new Display();
    // Subscribe Display with the thermo instance above
    dis.Subscribe(thermo);

    // make some changes in temps
    thermo.SetTemperature(5);
    thermo.SetTemperature(10);
    thermo.SetTemperature(10);
    thermo.SetTemperature(13);
    thermo.SetTemperature(12);
  }
}
