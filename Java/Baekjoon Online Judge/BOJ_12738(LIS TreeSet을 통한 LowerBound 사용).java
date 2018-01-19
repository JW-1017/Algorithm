import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.util.TreeSet;
import java.io.IOException;
import java.io.InputStreamReader;

/*
input
6
10 20 10 30 20 50

output
4

https://www.acmicpc.net/problem/12738
/* Copyright (C) 2018 by Son */

public class Main {
	static class FastScanner
    {
        BufferedReader br;
        StringTokenizer st;
 
        public FastScanner() {br = new BufferedReader(new InputStreamReader(System.in));}
        String next() // ��ū������ ����
        {
            while (st == null || !st.hasMoreElements()){
                try { st = new StringTokenizer(br.readLine()); }
                // ����ó��
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
            // ����ó��
            catch (IOException e){e.printStackTrace();}
            return str;
        }
    }
	public static void main(String[] args) throws IOException {
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		FastScanner scan = new FastScanner();
		TreeSet<Integer> set = new TreeSet<Integer>();
		int num = scan.nextInt();
		int result = 1;
		
		set.add(scan.nextInt());
		
		for(int i = 1; i < num; i++){
			int temp = scan.nextInt();
			if(set.last() < temp){		// last�� ���� ū ���
				set.add(temp);
				result++;
				continue;
			}
			// ceiling �� �ڽź��� ū�� �߿� ���� ������ Ȥ�� ���� ���� �̾� ���°�
			int val = set.ceiling(temp);
			if(val == temp){
				continue;
			}
			set.remove(val);
			set.add(temp);
		}
		bw.write(result + "\n");
		bw.close();
	}
}