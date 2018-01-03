import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.io.IOException;

/*
input
4 3
2 3 5 9
1 4 7

output
1 2 3 4 5 7 9

https://www.acmicpc.net/problem/11728
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String str = in.readLine();
		StringTokenizer tokens = new StringTokenizer(str, " ");
		int num1 = Integer.parseInt(tokens.nextToken());
		int num2 = Integer.parseInt(tokens.nextToken());
		
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
		
		str = in.readLine();
		tokens = new StringTokenizer(str, " ");
		for(int i = 0; i < num1; i++){
			pq.add(Integer.parseInt(tokens.nextToken()));
		}
		str = in.readLine();
		tokens = new StringTokenizer(str, " ");
		for(int i = 0; i < num2; i++){
			pq.add(Integer.parseInt(tokens.nextToken()));
		}
		num1 += num2;
		for(int i = 0; i < num1 - 1; i++){
			bw.write(pq.poll() + " ");
		}
		bw.write(pq.poll() + "\n");
		
		in.close();
		bw.close();
	}
}