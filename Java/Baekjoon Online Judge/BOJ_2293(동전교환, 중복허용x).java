package base;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;

/*
�ߺ��� ������� �ʴ� ����
���� ���������� ����� �� ���
����(���� ��)�� �켱���� �ݺ����� ���鼭
��ǥ ������ �ݺ����� ���鼭 ���̰� ���� ��(������ ����)�� ���� ���ϸ� ����
(1���� ����� �� ��ǥġ���� ����س���)

1
1 + 1, 2 (dp[1] ���� 1���Ѱ�)
1 + 1 + 1, 1 + 2 (dp[2] ���� 1���Ѱ� (1 + 1 + 1), dp[1] ���� 2���� �� (1+2))

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