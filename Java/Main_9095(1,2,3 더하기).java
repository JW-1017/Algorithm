import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.IOException;

/*
input
3
4
7
10

output
7
44
274

https://www.acmicpc.net/problem/9095
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String str = in.readLine();
		
		int num = Integer.parseInt(str);
		int dp[] = new int[11];
		Arrays.fill(dp, 0);
		dp[0] = 1;
		dp[1] = 2;
		dp[2] = 4;
		
		for(int i = 0; i < num; i++){
			str = in.readLine();
			int temp = Integer.parseInt(str);
			for(int j = 3; j < temp; j++){
				if(dp[j] != 0){
					continue;
				}
				dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
			}
			bw.write(dp[temp-1] + "\n");
		}
		in.close();
		bw.close();
	}
}