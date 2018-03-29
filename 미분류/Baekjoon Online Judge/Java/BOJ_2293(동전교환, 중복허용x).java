package base;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;

/*
중복을 허용하지 않는 조합
따라서 순차적으로 경우의 수 계산
간격(동전 값)이 우선으로 반복문을 돌면서
목표 값까지 반복문을 돌면서 차이가 나는 곳(간격의 차이)의 값을 더하며 갱신
(1부터 경우의 수 목표치까지 계산해나감)

1
1 + 1, 2 (dp[1] 에서 1더한값)
1 + 1 + 1, 1 + 2 (dp[2] 에서 1더한값 (1 + 1 + 1), dp[1] 에서 2더한 값 (1+2))

input
3 10
1
2
5

output
10

https://www.acmicpc.net/problem/2293
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String str = in.readLine();
		StringTokenizer tokens = new StringTokenizer(str, " ");
		
		int num = Integer.parseInt(tokens.nextToken());
		int target = Integer.parseInt(tokens.nextToken());
		int dp[] = new int[10001];
		int store[] = new int[num];
		Arrays.fill(dp, 0);
		
		for(int i = 0; i < num; i++){
			str = in.readLine();
			store[i] = Integer.parseInt(str);
		}
		for(int i = 0; i < num; i++){
			for(int j = 1; j <= target; j++){
				if(j == store[i]){
					dp[j] += 1;
				}
				else if(j > store[i]){
					dp[j] += dp[j - store[i]];
				}
			}
		}
		bw.write(dp[target] + "\n");
		in.close();
		bw.close();
	}
}