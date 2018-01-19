import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.io.IOException;
import java.io.InputStreamReader;

/*
input
7
1 6 4 7 2 3 5

output
4
1 2 3 5

https://www.acmicpc.net/problem/14003
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
		// key �� �� , value �� �ε���
		TreeMap<Integer, Integer> set = new TreeMap<Integer, Integer>();
		int max;
		int num = scan.nextInt();
		int arr[] = new int[num];
		int index[] = new int[num];		// ���� ���� �ε����� ���� arr�� �����غ��� 
		int change[] = new int[num];	// lower_bound��(ceiling) ���� ���� �ε����� ������ �� ���� index ����
		Arrays.fill(change, -1);		// change -1�� �ʱ�ȭ �ؼ� -1�̸� ���Ѱ� x 
		int t_index;
		int result = 1;
		
		index[0] = -1;
		arr[0] = scan.nextInt();
		max = arr[0];
		set.put(arr[0], 0);
		set.put(Integer.MAX_VALUE, -1);		// NULL ����
		
		for(int i = 1; i < num; i++){
			arr[i] = scan.nextInt();
			if(max < arr[i]){		// max set�ȿ��� ����ū���
				t_index = set.get(max);
				max = arr[i];
				set.put(arr[i], i);
				index[i] = t_index;			// ���� ���Ե� ���� �ε����� ������ Ű�� �ε���
				result++;
				continue;
			}
			// ceiling �� �ڽź��� ū�� �߿� ���� ������ Ȥ�� ���� ���� �̾� ���°�
			int val = set.ceilingKey(arr[i]);
			if(val == arr[i]){
				continue;
			}
			if(val == max){
				max = arr[i];
			}
			// �ٲٴ� ��ġ�� Ű������ ū Ű�� Ȯ�� (���� �ε����� ����)
			int val2 = set.higherKey(val);
			t_index = set.get(val);
			set.remove(val);
			set.put(arr[i], i);
			// �տ� �ε����� ���� �ε����� �ƴϸ� �״�� ����
			if(change[t_index] == -1){
				index[i] = index[t_index];		// ���� ���Ե� ���� �ε����� �������� Ű�� �ε���
			}
			// �����ε����� ��ȯ
			else {
				index[i] = change[t_index];
			}
			// higherŰ�� ��谪 ���� ũ��
			if(val2 > 1000000000){
				continue;
			}
			// �ƴϸ� ���� arr[i] ���� ��ġ���� �����ε����� ���� i�� ����
			else {
				change[set.get(val2)] = i;
			}
		}
		t_index = set.get(max);
		Stack<Integer> st = new Stack<Integer>();		// ���ÿ� �ְ�
		while(t_index != -1){
			st.push(arr[t_index]);		// index�� ���� �ᱹ arr���� �ε�����
			t_index = index[t_index];
		}
		bw.write(result + "\n");
		for(int i = 0; i < result; i++){
			bw.write(st.pop() + " ");
		}
		bw.close();
	}
}