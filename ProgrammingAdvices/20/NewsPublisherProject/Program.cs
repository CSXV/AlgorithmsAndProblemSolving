// this is the container class that will have the data to send it to subscribers
public class NewsArticle
{
  public string Title { get; }
  public string Body { get; }

  public NewsArticle(string title, string body)
  {
    this.Body = body;
    this.Title = title;
  }
}

// the service class
public class NewsPublisher
{
  // new event delegate
  public event EventHandler<NewsArticle> Publish;

  // this will write new articles
  public void PublishNewArticle(string title, string body)
  {
    var article = new NewsArticle(title, body);

    OnNewArticlePublished(article);
  }

  // this will send article to the subscribers
  protected virtual void OnNewArticlePublished(NewsArticle article)
  {
    Publish?.Invoke(this, article);
  }
}

public class NewsSubscriber
{
  string SubscriberName { get; }

  public NewsSubscriber(string name)
  {
    this.SubscriberName = name;
  }

  public void Subscribe(NewsPublisher publisher)
  {
    publisher.Publish += Print;
  }

  public void UnSubscribe(NewsPublisher publisher)
  {
    publisher.Publish -= Print;
  }

  // PRINT SOME NOISE
  private void Print(object sender, NewsArticle e)
  {
    Console.WriteLine($"[{SubscriberName}] received New Article:");
    Console.WriteLine($"\tTITLE  : {e.Title}");
    Console.WriteLine($"\tCONTENT: {e.Body}\n");
  }
}

// main program
class Program
{
  public static void Main(string[] args)
  {
    NewsPublisher publisher = new NewsPublisher();

    // new Subscriber instainces
    NewsSubscriber sub1 = new NewsSubscriber("NY post");
    sub1.Subscribe(publisher);

    NewsSubscriber sub2 = new NewsSubscriber("WSJ");
    sub2.Subscribe(publisher);

    // publish new articles
    publisher.PublishNewArticle("Breaking news!", "New hiking price for bitcoin in 2025");

    // UnSubscribe from the publisher
    sub2.UnSubscribe(publisher);

    publisher.PublishNewArticle("New Technology", "China get new battery Technology for electric cars!");
  }
}
