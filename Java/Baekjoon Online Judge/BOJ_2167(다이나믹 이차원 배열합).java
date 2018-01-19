import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.io.IOException;

/*
input
2 3
1 2 4
8 16 32
3
1 1 2 3
1 2 1 2
1 3 2 3

output
63
2
36

https://www.acmicpc.net/problem/2167
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String str = in.readLine();
		StringTokenizer tokens = new StringTokenizer(str, " ");
		int row = Integer.parseInt(tokens.nextToken());
		int col = Integer.parseInt(tokens.nextToken());
		
		int arr[][] = new int[row][col];
		// 해당 행에서 열까지의 합
		int dp[][] = new int[row][col];
		
		for(int i = 0; i < row; i++){
			str = in.readLine();
			tokens = new StringTokenizer(str, " ");
			for(int j = 0; j < col; j++){
				arr[i][j] = Integer.parseInt(tokens.nextToken());
				if(j == 0){
					dp[i][0] = arr[i][0];
				}
				else {
					dp[i][j] = dp[i][j-1] + arr[i][j];
				}
			}
		}
		str = in.readLine();
		int num = Integer.parseInt(str);
		for(int i = 0; i < num; i++){
			str = in.readLine();
			tokens = new StringTokenizer(str, " ");
			int a = Integer.parseInt(tokens.nextToken()) - 1;
			int b = Integer.parseInt(tokens.nextToken()) - 1;
			int x = Integer.parseInt(tokens.nextToken()) - 1;
			int y = Integer.parseInt(tokens.nextToken()) - 1;
			int result = 0;
			for(int k = a; k <=x; k++){
				if(b == 0){			
					result += dp[k][y];
				}
				else{
					// 열까지의 합에서 시작지점 이전까지 합을 빼면됨
					result += dp[k][y] - dp[k][b-1];
				}
			}
			bw.write(result + "\n");
		}
		in.close();
		bw.close();
	}
}