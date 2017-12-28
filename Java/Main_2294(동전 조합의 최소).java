package base;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;

/*
input
3 15
1
5
12

output
3

https://www.acmicpc.net/problem/2294
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int i, j;
		
		String str = in.readLine();
		StringTokenizer tokens = new StringTokenizer(str, " ");
		
		int num = Integer.parseInt(tokens.nextToken());
		int target = Integer.parseInt(tokens.nextToken());
		
		int count[] = new int[target+1];
		int st[] = new int[num];
		
		int k = 10001;		// 최대값 지정 (최소를 구하기 위함, 넘어갈수 있으므로 조심)
		
		Arrays.fill(count, k);
		
		for(i = 0; i < num; i++){
			str = in.readLine();
			st[i] = Integer.parseInt(str);
		}
		
		for(i = 0; i < num; i++){
			for(j = 1; j <= target; j++){
				if(j == st[i]){
					count[j] = 1;		// 속하면 그냥 1개
				}
				else if(j > st[i]){
					count[j] = Math.min(count[j], count[j - st[i]] + 1);		// 현재와 해당 간격 이전값 + 1(st[i]만큼 더해서) 비교 
				}
			}
		}
		if(count[target] >= k){				// 같거나 넘어가 버리면
			count[target] = -1;
		}
		bw.write(count[target] + "\n");
		in.close();
		bw.close();
	}
}