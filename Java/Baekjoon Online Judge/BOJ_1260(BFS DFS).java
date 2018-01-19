import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.InputStreamReader;

/*
input
4 5 1
1 2
1 3
1 4
2 4
3 4

output
1 2 4 3
1 2 3 4

https://www.acmicpc.net/problem/1260
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
			return a.second - b.second;
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
	static int N;
	static boolean d_visit[] = new boolean[1001];
	static boolean b_visit[] = new boolean[1001];
	static String result1 = "";
	static String result2;
	static int[][] adj = new int[1001][1001]; 
	static Queue<Integer> que = new LinkedList<Integer>();
	
	public static void main(String[] args) throws IOException {
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		FastScanner scan = new FastScanner();
		N = scan.nextInt();
		int M = scan.nextInt();
		int start = scan.nextInt();

		for(int i = 0; i < M; i++){
			int f = scan.nextInt();
			int t = scan.nextInt();
			adj[f][t] = 1;
			adj[t][f] = 1;
		}
		d_visit[start] = true;
		b_visit[start] = true;
		result1 = String.valueOf(start) + " ";
		result2 = result1;
		DFS(start);
		BFS(start);
		bw.write(result1);
		bw.write("\n");
		bw.write(result2);
		bw.close();
	}
	public static void DFS(int index){
		for(int i = 1; i <= N; i++){
			if(d_visit[i] || adj[index][i] != 1){
				continue;
			}
			d_visit[i] = true;
			result1 += String.valueOf(i) + " ";
			DFS(i);
		}
	}
	public static void BFS(int index){
		que.add(index);
		while(!que.isEmpty()){
			int temp = que.poll();
			for(int i = 1; i <= N; i++){
				if(b_visit[i] || adj[temp][i] != 1){
					continue;
				}
				b_visit[i] = true;
				que.add(i);
				result2 += String.valueOf(i) + " ";
			}
		}
	}
}