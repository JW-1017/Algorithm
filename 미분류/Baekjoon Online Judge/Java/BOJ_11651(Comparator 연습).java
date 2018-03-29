import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.InputStreamReader;

/*
input
5
0 4
1 2
1 -1
2 2
3 3

output
1 -1
1 2
2 2
3 3
0 4

https://www.acmicpc.net/problem/11651
/* Copyright (C) 2018 by Son */

public class Main {
	static class Pair{
		public int first;
		public int second;
		public Pair(int first, int second){
			this.first = first;
			this.second = second;
		}
	}
	static class Comp implements Comparator<Pair>{
		@Override
		public int compare(Pair a, Pair b) {
			// TODO Auto-generated method stub
			if(a.second < b.second){		// second의 오름차순 (내림차순은 반대 1)
				return -1;
			}
			else if(a.second > b.second){	// second의 오름차순 (내림차순은 반대 -1)
				return 1;
			}
			else {
				if(a.first > b.first){		// firest의 오름차순
					return 1;
				}
				else{
					return -1;
				}
			}
		}
	}
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
		
		PriorityQueue<Pair> p = new PriorityQueue<Pair>(new Comp());
		
		int n = scan.nextInt();
		for(int i = 0; i < n; i++){
			int a = scan.nextInt();
			int b = scan.nextInt();
			
			p.add(new Pair(a,b));
		}
		for(int i = 0; i < n; i++){
			Pair temp = p.poll();
			bw.write(temp.first + " " + temp.second + "\n");
		}
		bw.close();
	}
}