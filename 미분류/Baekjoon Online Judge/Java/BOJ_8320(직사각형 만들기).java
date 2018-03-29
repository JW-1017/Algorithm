import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.InputStreamReader;

/*
input
10000

output
46884

https://www.acmicpc.net/problem/8320
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
		int num = scan.nextInt();
		int result = num;
		
		for(int i = 2; i < num; i++){
			int add = num / i;			// 일단 만들수 있는 총 사각형
			add -= (i-1);				// 겹치는건 이전에서 만든 길이 변만큼 빼야됨
			if(add < 0){				// 0보다 작아질수 있음 그땐 그냥 못만드는거
				add = 0;
			}
			result += add;	
		}
		bw.write(result + "\n");
		bw.close();
	}
}