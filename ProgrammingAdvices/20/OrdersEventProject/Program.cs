public class OrderEvnetArgs : EventArgs
{
  public int OrderID { get; }
  public string ClientEmail { get; }
  public double Total { get; }

  public OrderEvnetArgs(int id, string email, double total)
  {
    this.Total = total;
    this.OrderID = id;
    this.ClientEmail = email;
  }
}

public class Sender
{
  public EventHandler<OrderEvnetArgs> MakeOrder;

  public void NewOrder(int id, string email, double total)
  {
    if (MakeOrder != null)
    {
      MakeOrder(this, new OrderEvnetArgs(id, email, total));
    }
  }
}

public class Shipper
{
  string Name { get; }

  public Shipper(string name)
  {
    this.Name = name;
  }

  public void Subscribe(Sender sender)
  {
    sender.MakeOrder += ShipTheOrder;
  }

  public void UnSubscribe(Sender sender)
  {
    sender.MakeOrder -= ShipTheOrder;
  }

  private void ShipTheOrder(object sender, OrderEvnetArgs e)
  {
    Console.WriteLine($"{Name} received new order:");
    Console.WriteLine($"\tOrder ID     : {e.OrderID}");
    Console.WriteLine($"\tClient E-Mail: {e.ClientEmail}");
    Console.WriteLine($"\tOrder Total  : {e.Total}");
    Console.WriteLine($"Shipping to customer...");
    Console.WriteLine($"---------------------------\n");
  }
}

public class EmailService
{
  public void Subscribe(Sender sender)
  {
    sender.MakeOrder += HandleNewOrder;
  }

  public void UnSubscribe(Sender sender)
  {
    sender.MakeOrder -= HandleNewOrder;
  }

  private void HandleNewOrder(object sender, OrderEvnetArgs e)
  {
    Console.WriteLine($"------E-Mail  service------");
    Console.WriteLine($"received new order:");
    Console.WriteLine($"\tOrder ID     : {e.OrderID}");
    Console.WriteLine($"\tClient E-Mail: {e.ClientEmail}");
    Console.WriteLine($"\tOrder Total  : {e.Total}");
    Console.WriteLine($"Sending an e-mail...");
    Console.WriteLine($"---------------------------\n");
  }
}

public class SMSService
{
  public void Subscribe(Sender sender)
  {
    sender.MakeOrder += HandleNewOrder;
  }

  public void UnSubscribe(Sender sender)
  {
    sender.MakeOrder -= HandleNewOrder;
  }

  private void HandleNewOrder(object sender, OrderEvnetArgs e)
  {
    Console.WriteLine($"--------SMS service--------");
    Console.WriteLine($"received new order:");
    Console.WriteLine($"\tOrder ID     : {e.OrderID}");
    Console.WriteLine($"\tClient E-Mail: {e.ClientEmail}");
    Console.WriteLine($"\tOrder Total  : {e.Total}");
    Console.WriteLine($"Sending an SMS...");
    Console.WriteLine($"---------------------------\n");
  }
}

class Program
{
  public static void Main(string[] args)
  {
    Sender sender1 = new Sender();

    EmailService emailService = new EmailService();
    emailService.Subscribe(sender1);

    SMSService smsService = new SMSService();
    smsService.Subscribe(sender1);

    Shipper shipper1 = new Shipper("HDL");
    shipper1.Subscribe(sender1);

    sender1.NewOrder(1, "foobar@example.com", 5000);
  }
}
