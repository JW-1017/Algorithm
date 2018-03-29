import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.Vector;
import java.io.IOException;

/*
input
2
4 4
10 1 100 10
1 2
1 3
2 4
3 4
4
8 8
10 20 1 5 8 7 1 43
1 2
1 3
2 4
2 5
3 6
5 7
6 7
7 8
7

output
120
39

https://www.acmicpc.net/problem/1005
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String str = in.readLine();
		int num = Integer.parseInt(str);
		
		for(int i = 0; i < num; i++){
			str = in.readLine();
			StringTokenizer tokens = new StringTokenizer(str, " ");
			int c_num = Integer.parseInt(tokens.nextToken());
			int m_num = Integer.parseInt(tokens.nextToken());
			
			Queue<Integer> que = new LinkedList<Integer>();
			
			int indegree[] = new int[c_num+1];
			int t_arr[] = new int[c_num+1];				// 자신의 값 저장
			int f_arr[] = new int[c_num+1]; 			// 현재까지 최대값 저장	
			
			Vector<Vector<Integer>> adj = new Vector<Vector<Integer>>();
			
			for(int j = 0; j <= c_num; j++){
				adj.add(new Vector<Integer>());
			}
			
			str = in.readLine();
			tokens = new StringTokenizer(str, " ");
			for(int j = 1; j <= c_num; j++){
				t_arr[j] = Integer.parseInt(tokens.nextToken());
			}
			for(int j = 0; j < m_num; j++){
				str = in.readLine();
				tokens = new StringTokenizer(str, " ");
				int num1 = Integer.parseInt(tokens.nextToken());
				int num2 = Integer.parseInt(tokens.nextToken());
				
				adj.get(num1).add(num2);
				indegree[num2]++;
			}
			str = in.readLine();
			int target = Integer.parseInt(str);

			for(int j = 1; j <= c_num; j++){
				if(indegree[j] == 0){
					que.add(j);
				}
			}
			for(int j = 1; j <= c_num; j++){
				int temp = que.poll();
				f_arr[temp] += t_arr[temp];				// 이어진게 없을 때 자신의 값 더하기
				
				if(temp == target){
					bw.write(f_arr[temp] + "\n");
					break;
				}
				Vector<Integer> v = adj.get(temp);
				for(int val : v){
					indegree[val]--;
					f_arr[val] = Math.max(f_arr[val], f_arr[temp]);		// 이어진쪽에서 오는 거랑 자신의 저장된거의 최대값
					if(indegree[val] == 0){
						que.add(val);
					}
				}
			}
		}
		in.close();
		bw.close();
	}
}