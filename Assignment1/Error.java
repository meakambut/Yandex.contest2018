import edu.princeton.cs.algs4.In;
public class Error
{ 
  private int numOfServers;
  private int[] serverProbability;
  private int[] errorProbability;
  private int sum;

  public Error(int n, int[] servers, int[] errors)
  {
    this.numOfServers = n;
    this.serverProbability = new int[n];
    this.errorProbability = new int[n];
    for (int i = 0; i < n; i++)
    {
      this.serverProbability[i] = servers[i];
      this.errorProbability[i] = errors[i];
      sum += servers[i]*errors[i];
    }
  }

  public double errorOnServerProbability(int num)
  {
    return this.serverProbability[num-1]*this.errorProbability[num-1]/(double)this.sum;
  }

  public static void main(String args[])
  { 
    In in = new In(args[0]);
    int n = in.readInt();
    int[] servers = new int[n];
    int[] errors = new int[n];
    for (int i = 0; i < n; i++)
    {
      servers[i] = in.readInt();
      errors[i] = in.readInt();
    }
    Error error = new Error(n, servers, errors);
    for (int i = 1; i <= n; i++)
      System.out.printf("%.10f\n", error.errorOnServerProbability(i));
  }
}