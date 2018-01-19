import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.InputStreamReader;

/*
input
7

output
6

https://www.acmicpc.net/problem/3190
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
		
		int num = scan.nextInt();
		
		int temp = 1;
		int dp[] = new int[num+1];
		Arrays.fill(dp, 1);			// 기본 적으로 1씩 더한것 존재
		while(true){
			temp *= 2;
			if(temp > num){
				break;
			}
			for(int j = 1; j <= num; j++){
				if(j == temp){
					dp[j] = (dp[j] + 1) % 1000000000;	// 있던거에 끝에 temp만 추가
				}
				else if(j > temp){
					// 차이 만큼 거슬러 올라간 곳에서 끝에 + temp 가 된게 나에게 추가됨
					dp[j] = (dp[j] + dp[j - temp]) % 1000000000;
				}
			}
		}
		bw.write(dp[num] + "\n");
		bw.close();
	}
}