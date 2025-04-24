public class Logger
{
  public delegate void LogAction(string message);
  // make an instance of the delegate
  public LogAction _LogAction;

  //this will susbcribe to the delegate
  public Logger(LogAction action)
  {
    this._LogAction = action;
  }

  public void Log(string message)
  {
    _LogAction(message);
  }
}

class Program
{
  public static void LogToScreen(string message)
  {
    Console.WriteLine(message);
  }

  public static void LogToFile(string message)
  {
    string fileName = "log.txt";

    using (StreamWriter writer = new StreamWriter(fileName, true))
    {
      writer.WriteLine(message);
    }
  }

  public static void Main(string[] args)
  {
    Logger screenLogger = new Logger(LogToScreen);
    Logger FileLogger = new Logger(LogToFile);

    screenLogger.Log("this message will be logged on the screen.");
    FileLogger.Log("this message will be logged in file.");
  }
}
