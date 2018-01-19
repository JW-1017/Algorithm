import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.Stack;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.InputStreamReader;

/*
input
5
14
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
3 5 10
3 1 8
1 4 2
5 1 7
3 4 2
5 2 4

output
0 2 3 1 4 
12 0 15 2 5 
8 5 0 1 1 
10 7 13 0 3 
7 4 10 6 0 
0
2 1 2 
2 1 3 
2 1 4 
3 1 3 5 
4 2 4 5 1 
0
5 2 4 5 1 3 
2 2 4 
3 2 4 5 
2 3 1 
3 3 5 2 
0
2 3 4 
2 3 5 
3 4 5 1 
3 4 5 2 
4 4 5 1 3 
0
2 4 5 
2 5 1 
2 5 2 
3 5 1 3 
3 5 2 4 
0

https://www.acmicpc.net/problem/11780
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
	
	public static void main(String[] args) throws IOException {
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		FastScanner scan = new FastScanner();
		// div 0 은 거리 1은 row - col 거리에서 col 바로 앞 노드
		int adj[][][] = new int[2][101][101];
		
		int N = scan.nextInt();
		int M = scan.nextInt();
		
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if(i == j) {
					adj[0][i][j] = 0;
				}
				else{
					adj[0][i][j] = 100001;
				}
			}
		}
		for(int i = 0; i < M; i++){
			int a = scan.nextInt();
			int b = scan.nextInt();
			int c = scan.nextInt();
			adj[0][a][b] = Math.min(adj[0][a][b], c);
			adj[1][a][b] = a;
		}
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				for(int k = 1; k <= N; k++){
					if(adj[0][j][k] > adj[0][j][i] + adj[0][i][k]){
						adj[0][j][k] = adj[0][j][i] + adj[0][i][k];
						adj[1][j][k] = adj[1][i][k];		
					}
				}
			}
		}
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				bw.write(adj[0][i][j] + " ");
			}
			bw.write("\n");
		}
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				Stack<Integer> st = new Stack<Integer>();
				int index = adj[1][i][j];
				if(index == 0){
					bw.write(0 + "\n");
					continue;
				}
				while(index != 0){
					st.push(index);
					index = adj[1][i][index];
				}
				bw.write(st.size()+1 + " ");
				while(!st.isEmpty()){
					bw.write(st.pop() + " ");
				}
				bw.write(j + "\n");		// 끝나는 위치가 포함이 안됨
			}
		}
		bw.close();
	}
}