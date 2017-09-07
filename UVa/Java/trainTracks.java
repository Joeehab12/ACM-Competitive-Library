import java.util.*;
import java.io.*;
public class trainTracks{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    try{
    int n = sc.nextInt();
    while(n-->0){
      ArrayList<String> pieces = new ArrayList<String>();
      String s = sc.nextLine();
      StringTokenizer st = new StringTokenizer(s);
      while(st.hasMoreTokens()){
        String token = st.nextToken();
        pieces.add(token);
      }
      int fm_mf_count = 0;
      int ff_count = 0;
      int mm_count = 0;

      for (int i = 0;i<pieces.size();i++){
          if (pieces.get(i).equals("MM")){
            mm_count++;
          }
          else if (pieces.get(i).equals("FF")){
            ff_count++;
          }
          else{
            fm_mf_count++;
          }
      }

      if (mm_count == ff_count && pieces.size()!=1){
        System.out.println("LOOP");
      }
      else{
        System.out.println("NO LOOP");
      }

    }
  }
  catch(IOException e){
    e.printStackTrace();
  }
}
  static class Scanner {
  		BufferedReader br;
  		StringTokenizer st;

  		public Scanner(FileReader f) {
  			br = new BufferedReader(f);
  		}

  		public Scanner(InputStream in) {
  			br = new BufferedReader(new InputStreamReader(in));
  		}

  		public String next() throws IOException {
  			while (st == null || !st.hasMoreTokens())
  				st = new StringTokenizer(br.readLine());
  			return st.nextToken();
  		}

  		public String nextLine() throws IOException {
  			return br.readLine();
  		}

  		public int nextInt() throws IOException {
  			return Integer.parseInt(next());
  		}

  		public long nextLong() throws IOException {
  			return Long.parseLong(next());
  		}

  		public double nextDouble() throws IOException {
  			return Double.parseDouble(next());
  		}

  		public boolean Ready() throws IOException {
  			return br.ready();
  		}

  		public void waitForInput(long time) {
  			long ct = System.currentTimeMillis();
  			while(System.currentTimeMillis() - ct < time) {};
  		}

  	}
}
