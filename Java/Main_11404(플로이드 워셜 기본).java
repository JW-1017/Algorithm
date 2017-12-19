import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.io.IOException;

/*
input
5
14
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
3 5 10
3 1 8
1 4 2
5 1 7
3 4 2
5 2 4

output
0 2 3 1 4
12 0 15 2 5
8 5 0 1 1
10 7 13 0 3
7 4 10 6 0

https://www.acmicpc.net/problem/11404
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		final int MAX_VAL = Integer.MAX_VALUE;		
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int i, j, k, u, v, w;
		
		String str = in.readLine();
		int num1 = Integer.parseInt(str);
		str = in.readLine();
		int num2 = Integer.parseInt(str);
		StringTokenizer tokens;
		
		long arr[][] = new long[num1][num1];
		
		for(i = 0; i < num1; i++){
			for(j = 0; j < num1; j++){
				if(i == j) {
					arr[i][j] = 0;
				}
				else{
					arr[i][j] = MAX_VAL;
				}
			}
		}
		for(i = 0; i<num2; i++){
			str = in.readLine();
			tokens = new StringTokenizer(str, " ");
			u = Integer.parseInt(tokens.nextToken());
			v = Integer.parseInt(tokens.nextToken());
			w = Integer.parseInt(tokens.nextToken());
			
			if(w < arr[u-1][v-1]){
				arr[u-1][v-1] = w;				// 중복되지만 긴 경로는 무시
			}
		}
		
		for(i = 0; i < num1; i++){				// 거쳐가는점
			for(j = 0; j < num1; j++){			// 출발 점
				if(i == j){
					continue;
				}
				for(k = 0; k < num1; k++){		// 도착점
					if(i == k){
						continue;
					}
					if(j != k){
						if(arr[j][k] > arr[j][i] + arr[i][k]){
							arr[j][k] = arr[j][i] + arr[i][k];
						}
					}
				}
			}
		}
		for(i = 0; i < num1; i++){				
			for(j = 0; j < num1; j++){		
				long temp = arr[i][j];
				
				if(temp == MAX_VAL){
					temp = 0;
				}
				if(j == num1){
					bw.write(temp + "");
				}
				else{
					bw.write(temp + " ");
				}
			}
			bw.write("\n");
		}
		in.close();
		bw.close();
	}
}