import edu.princeton.cs.algs4.In;
public class Library
{
  public static void main(String[] args)
  { 
    In in = new In(args[0]);
    int takeOut = in.readInt();
    int books = in.readInt();
    int day = in.readInt();
    int count = 1;
    while(books >= 0)
    { 
      if (day == 6 || day == 7)
        books -= count;
      else
        books = books + takeOut - count;      
      count++;
      if (day == 7) 
        day = 1;
      else
        day++;
    }
    int res = 0;
    if (count != 1)
      res = count - 2;
    System.out.print(res);
  }
}