import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.InputStreamReader;

/*
input
6
10 20 10 30 20 50

output
4

https://www.acmicpc.net/problem/11053
/* Copyright (C) 2018 by Son */

public class Main {
	static class FastScanner
    {
        BufferedReader br;
        StringTokenizer st;
 
        public FastScanner() {br = new BufferedReader(new InputStreamReader(System.in));}
        String next() // 토큰단위로 읽음
        {
            while (st == null || !st.hasMoreElements()){
                try { st = new StringTokenizer(br.readLine()); }
                // 예외처리
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
            // 예외처리
            catch (IOException e){e.printStackTrace();}
            return str;
        }
    }
	public static void main(String[] args) throws IOException {
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		FastScanner scan = new FastScanner();
		
		int dist[][] = new int[2][1000];
		int result = 1;
		Arrays.fill(dist[1], 1);
		int num = scan.nextInt();
		
		dist[0][0] = scan.nextInt();
		
		for(int i = 1; i < num; i++){
			dist[0][i] = scan.nextInt();
			
			for(int j = 0; j < i; j++){
				if(dist[0][j] < dist[0][i] && dist[1][i] < dist[1][j] + 1){
					dist[1][i] = dist[1][j] + 1;
				}
			}
			result = Math.max(dist[1][i], result);
		}
		
		bw.write(result + "\n");
		bw.close();
	}
}