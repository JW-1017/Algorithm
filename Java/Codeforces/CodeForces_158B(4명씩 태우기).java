import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.Vector;
import java.io.IOException;
import java.io.InputStreamReader;

/*
input
8
2 3 4 4 2 1 3 1

output
5

http://codeforces.com/problemset/problem/158/B
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
	static class Comp implements Comparator<Integer>{

		@Override
		public int compare(Integer o1, Integer o2) {
			// TODO Auto-generated method stub
			return o2 - o1;
		}
		/*
		@Override
		public int compare(Pair a, Pair b) {
			// TODO Auto-generated method stub
			/*
			if(a.first < b.first){		// second�� �������� (���������� �ݴ� 1)
				return -1;
			}
			else if(a.first > b.first){	// second�� �������� (���������� �ݴ� -1)
				return 1;
			}
			else {
				return 0;
			}
			return a.first - b.first;
		}*/
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
        BigInteger nextBigInteger(){ return new BigInteger(next());}
        
        String nextLine()
        {
            String str = "";
            try {str = br.readLine();}
            catch (IOException e){e.printStackTrace();}
            return str;
        }
    }
	public static long RepeatedSquaring(long base, long exp)
	{
		long result = 1;
		
		while(exp != 0){
			if(exp % 2 == 1){
				result *= base; 
			}
			base *= base;
			exp /= 2;
		}
		return result;
	}
	public static void main(String[] args) throws IOException {
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		FastScanner scan = new FastScanner();
		
		int num = scan.nextInt();
		int arr[] = new int[5];				// �ε��� �� ����
		int count = 0;
		Queue<Integer> q = new LinkedList<Integer>();
		
		for(int i = 0; i < num; i++){
			int temp = scan.nextInt();
			arr[temp]++;
			q.add(temp);
		}
		for(int i = 0; i < num; i++){
			int temp = q.poll();
			if(temp == 4){			// 4�� �¿�� ��
				count++;
				continue;
			}
			else if(temp == 3){		// 3���� �� 1�� �� ���� ������ 4������ ������ 3������
				if(arr[3] == 0){	// 3�� �� �̹� ���� ������ �Ѿ
					continue;
				}
				arr[3]--;
				if(arr[1] != 0){
					count++;
					arr[1]--;
				}
				else {
					count++;
				}
			}
			else if(temp == 2){		// 2���� �� 2�� �� ���� ������ 4������ ������ 1������ 4�� , 3�� or 2��
				if(arr[2] == 0){
					continue;
				}
				arr[2]--;
				int mem = 2;
				if(arr[2] != 0){
					arr[2]--;
					count++;
				}
				else if(arr[1] != 0){
					while(arr[1] != 0){
						arr[1]--;
						mem--;
						if(mem == 0){
							break;
						}
					}
					count++;
				}
				else {
					count++;
				}
			}
			else{
				// 1���� �� 3�� �� ���� ������ 4������ ������ 2������ 3�� + 1������ 4��, 1������ 4�� or 1������ 3�� or 1������ 2��, 1������ 1��
				if(arr[1] == 0){
					continue;
				}
				arr[1]--;
				if(arr[3] != 0){
					arr[3]--;
					count++;
				}
				else if(arr[2] != 0){ 
					arr[2]--;
					if(arr[1] != 0){
						arr[1]--;
					}
					count++;
				}
				else if(arr[1] != 0){
					int mem = 3;
					while(arr[1] != 0){
						arr[1]--;
						mem--;
						if(mem == 0){
							break;
						}
					}
					count++;
				}
				else {
					count++;
				}
			}
		}
		bw.write(count + "\n");
		bw.close();
	}
}