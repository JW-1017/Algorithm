import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.Vector;
import java.io.IOException;

/*
input
4 2
4 2
3 1

output
3 1 4 2

https://www.acmicpc.net/problem/1766
/* Copyright (C) 2017 by Son */

// 정점 개수를 통한 위상정렬 (http://jason9319.tistory.com/93)
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String str = in.readLine();
		StringTokenizer tokens = new StringTokenizer(str, " ");
		
		int p_num = Integer.parseInt(tokens.nextToken());
		int i_num = Integer.parseInt(tokens.nextToken());
		
		Vector<Vector<Integer>> adj = new Vector<Vector<Integer>>();
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
		
		for(int i = 0; i <=p_num; i++){
			adj.add(new Vector<Integer>());
		}
		
		int indegree[] = new int[p_num+1];
		
		for(int i = 0; i < i_num; i++){
			str = in.readLine();
			tokens = new StringTokenizer(str, " ");
			
			int num1 = Integer.parseInt(tokens.nextToken());
			int num2 = Integer.parseInt(tokens.nextToken());
			
			indegree[num2]++;			// 연결을 받는 정점의 차수 증가
			adj.get(num1).add(num2);	// 시작위치에서 끝위치로 간선을 추가
		}
		for(int i = 1; i <= p_num; i++){
			if(indegree[i] == 0){		// 차수가 0인 노드부터 시작
				pq.add(i);		
			}
		}
		while(!pq.isEmpty()){
			int temp = pq.poll();
			bw.write(temp + " ");
			Vector<Integer> v_temp = adj.get(temp);		// 0인 애들에서 나아가는 정점 확인
			for(int val : v_temp){
				indegree[val]--;				// 간선 끊기 (차수 감소로)
				if(indegree[val] == 0){			// 감소하고 0되면 pq에 추가
					pq.add(val);		
				}
			}
		}
		in.close();
		bw.close();
	}
}