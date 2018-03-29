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
		// key 가 값 , value 가 인덱스
		TreeMap<Integer, Integer> set = new TreeMap<Integer, Integer>();
		int max;
		int num = scan.nextInt();
		int arr[] = new int[num];
		int index[] = new int[num];		// 이전 값의 인덱스를 저장 arr로 접근해보기 
		int change[] = new int[num];	// lower_bound로(ceiling) 이전 값의 인덱스가 변했을 때 변한 index 저장
		Arrays.fill(change, -1);		// change -1로 초기화 해서 -1이면 변한값 x 
		int t_index;
		int result = 1;
		
		index[0] = -1;
		arr[0] = scan.nextInt();
		max = arr[0];
		set.put(arr[0], 0);
		set.put(Integer.MAX_VALUE, -1);		// NULL 방지
		
		for(int i = 1; i < num; i++){
			arr[i] = scan.nextInt();
			if(max < arr[i]){		// max set안에서 가장큰요소
				t_index = set.get(max);
				max = arr[i];
				set.put(arr[i], i);
				index[i] = t_index;			// 내가 갖게될 이전 인덱스는 마지막 키의 인덱스
				result++;
				continue;
			}
			// ceiling 이 자신보다 큰값 중에 가장 작은값 혹은 같은 값을 뽑아 내는것
			int val = set.ceilingKey(arr[i]);
			if(val == arr[i]){
				continue;
			}
			if(val == max){
				max = arr[i];
			}
			// 바꾸는 위치의 키값보다 큰 키값 확인 (변한 인덱스에 대응)
			int val2 = set.higherKey(val);
			t_index = set.get(val);
			set.remove(val);
			set.put(arr[i], i);
			// 앞에 인덱스가 변한 인덱스가 아니면 그대로 저장
			if(change[t_index] == -1){
				index[i] = index[t_index];		// 내가 갖게될 이전 인덱스는 지워지는 키의 인덱스
			}
			// 변한인덱스면 변환
			else {
				index[i] = change[t_index];
			}
			// higher키가 경계값 보다 크면
			if(val2 > 1000000000){
				continue;
			}
			// 아니면 현재 arr[i] 다음 위치에서 변한인덱스에 대해 i를 저장
			else {
				change[set.get(val2)] = i;
			}
		}
		t_index = set.get(max);
		Stack<Integer> st = new Stack<Integer>();		// 스택에 넣고
		while(t_index != -1){
			st.push(arr[t_index]);		// index에 담긴게 결국 arr상의 인덱스값
			t_index = index[t_index];
		}
		bw.write(result + "\n");
		for(int i = 0; i < result; i++){
			bw.write(st.pop() + " ");
		}
		bw.close();
	}
}