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
4 2
4 2
3 1

output
3 4 1 2

https://www.acmicpc.net/problem/2252
/* Copyright (C) 2017 by Son */

// 정점 개수를 통한 위상정렬 (http://jason9319.tistory.com/93) 앞에서야 된다 자체가 cycle x
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		Queue<Integer> que = new LinkedList<Integer>();
		Vector<Vector<Integer>> adj = new Vector<Vector<Integer>>();
		
		String str = in.readLine();
		StringTokenizer tokens = new StringTokenizer(str, " ");
		
		int p_num = Integer.parseInt(tokens.nextToken());
		int i_num = Integer.parseInt(tokens.nextToken());
		int indegree[] = new int[p_num+1];
		
		for(int i = 0; i <=p_num; i++){
			adj.add(new Vector<Integer>());
		}
		for(int i = 0; i < i_num; i++){
			str = in.readLine();
			tokens = new StringTokenizer(str, " ");
			
			int num1 = Integer.parseInt(tokens.nextToken());
			int num2 = Integer.parseInt(tokens.nextToken());
			
			indegree[num2]++;
			adj.get(num1).add(num2);
		}
		for(int i = 1; i <=p_num; i++){
			if(indegree[i] == 0){
				que.add(i);
			}
		}
		for(int i = 0; i < p_num; i++){		// 결국 노드 개수만큼 반복 (cycle이 없다면)
			int temp = que.poll();
			bw.write(temp + " ");
			Vector<Integer> v_temp = adj.get(temp);
			
			for(int val : v_temp){
				indegree[val]--;
				if(indegree[val] == 0){
					que.add(val);
				}
			}
		}
		in.close();
		bw.close();
	}
}