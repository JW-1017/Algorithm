import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.Vector;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	static class FastScanner
    {
        BufferedReader br;
        StringTokenizer st;
        public FastScanner() {br = new BufferedReader(new InputStreamReader(System.in));}
        String next() 
        {
            while (st == null || !st.hasMoreElements()){
                try { st = new StringTokenizer(br.readLine()); }
               
                catch (IOException  e){e.printStackTrace();}
            }
            return st.nextToken();
        }
        
        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
        double nextDouble() { return Double.parseDouble(next()); }
        
        String nextLine()
        {
            String str = "";
            try {str = br.readLine();}
            catch (IOException e){e.printStackTrace();}
            return str;
        }
    }
	public static void main(String[] args) throws IOException {
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		FastScanner scan = new FastScanner();
		
		int cost[] = new int[31];
		int dp[] = new int[31];
		
		int n = scan.nextInt();
		long L = scan.nextLong();
		long result = 0, re_temp = Long.MAX_VALUE;
		TreeMap<Integer, Integer> tm = new TreeMap<Integer, Integer>();
		
		final int ma = Integer.MAX_VALUE;
		int val = 1;
		int temp = scan.nextInt();
		dp[0] = 0;			//  초기화값
		cost[1] = temp;
		dp[1] = temp;
		tm.put(1, 1);
		tm.put(-1, 0);
		tm.put(ma, 0);
		
		for(int i = 2; i <= n; i++){
			val *= 2;
			tm.put(val, i);
			cost[i] = scan.nextInt();
			if(cost[i] > dp[i-1] * 2){
				dp[i] = dp[i-1]*2;
			}
			else{
				dp[i] = cost[i];
			}
		}
		for(int i = n; i > 1 ; i--){
			if(dp[i-1] > dp[i]){
				dp[i-1] = dp[i];
			}
		}
		while(L > 0){		// key pow value, value == index
			int val1 = tm.floorKey((int)L);
			int val2 = tm.ceilingKey((int)L);
			
			int index1 = tm.get(val1);
			int index2 = tm.get(val2);
			
			if(val2 == ma){
				long qu = L / val1;
				L -= (val1 * qu);
				result += (qu *dp[index1]);
				continue;
			}
			
			L -= val1;
			result += dp[index1];
			re_temp = Math.min(re_temp, result + dp[index2] - dp[index1]);
		}
		bw.write(Math.min(result, re_temp) + "\n");
		bw.close();
	}
}
