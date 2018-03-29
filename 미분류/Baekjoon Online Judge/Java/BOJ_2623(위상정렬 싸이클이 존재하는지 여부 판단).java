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
6 3
3 1 4 3
4 6 2 5 4
2 2 3

output
6
2
1
5
4
3

https://www.acmicpc.net/problem/2623
/* Copyright (C) 2017 by Son */

// 정점 개수를 통한 위상정렬 (http://jason9319.tistory.com/93) 앞에서야 된다 자체가 cycle x
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		Queue<Integer> que = new LinkedList<Integer>();
		Vector<Vector<Integer>> adj = new Vector<Vector<Integer>>();
		
		String str = in.readLine();
		String result = "";
		StringTokenizer tokens = new StringTokenizer(str, " ");
		
		int p_num = Integer.parseInt(tokens.nextToken());
		int i_num = Integer.parseInt(tokens.nextToken());
		int indegree[] = new int[p_num+1];
		
		for(int i = 0; i <=p_num; i++){
			adj.add(new Vector<Integer>());
		}
		for(int i = 0; i < i_num; i++){
			int num1;
			str = in.readLine();
			tokens = new StringTokenizer(str, " ");
			
			int count = Integer.parseInt(tokens.nextToken());
			num1 = Integer.parseInt(tokens.nextToken());
			
			for(int j = 1; j < count; j++){
				int num2 = Integer.parseInt(tokens.nextToken());
				indegree[num2]++;
				adj.get(num1).add(num2);
				num1 = num2;
			}
		}
		for(int i = 1; i <=p_num; i++){
			if(indegree[i] == 0){
				que.add(i);
			}
		}
		for(int i = 0; i < p_num; i++){		// 결국 노드 개수만큼 반복 (cycle이 없다면)
			if(que.isEmpty()){				// 싸이클이 존재하면 indegree가 0인 노드가 없어서 que에 들어갈 값이 없움
				result = "0\n";
				break;
			}
			int temp = que.poll();
			result += String.valueOf(temp) + "\n";
			Vector<Integer> v_temp = adj.get(temp);
			for(int val : v_temp){
				indegree[val]--;
				if(indegree[val] == 0){
					que.add(val);
				}
			}
		}
		bw.write(result);
		in.close();
		bw.close();
	}
}