import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.IOException;

/*
input
7

output
6

https://www.acmicpc.net/problem/3190
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int index;
		String str = in.readLine();
		int num = Integer.parseInt(str);
		
		int temp = 1;
		int dp[] = new int[num+1];
		Arrays.fill(dp, 0);
		int st[] = new int[20];
		// index에 끝번호 저장(자신 포함)
		for(index = 0; index < 20; index++){
			st[index] = temp;
			temp *= 2;
			if(temp > num){
				break;
			}
		}
		for(int i = 0; i <= index; i++){
			for(int j = 1; j <= num; j++){
				if(j == st[i]){
					dp[j] = (dp[j] + 1) % 1000000000;
				}
				else if(j > st[i]){
					dp[j] = (dp[j] + dp[j - st[i]]) % 1000000000;
				}
			}
		}
		bw.write(dp[num] + "\n");
		in.close();
		bw.close();
	}
}