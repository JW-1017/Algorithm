package base;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.io.IOException;

/*
input
7
0 0 0 1 0 0 0
0 0 0 0 0 0 1
0 0 0 0 0 0 0
0 0 0 0 1 1 0
1 0 0 0 0 0 0
0 0 0 0 0 0 1
0 0 1 0 0 0 0

output
1 0 1 1 1 1 1
0 0 1 0 0 0 1
0 0 0 0 0 0 0
1 0 1 1 1 1 1
1 0 1 1 1 1 1
0 0 1 0 0 0 1
0 0 1 0 0 0 0

https://www.acmicpc.net/problem/11403
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		final int MAX_VAL = Integer.MAX_VALUE;		
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int i, j, k, w;
		
		String str = in.readLine();
		int num1 = Integer.parseInt(str);
		StringTokenizer tokens;
		
		long arr[][] = new long[num1][num1];
		
		for(i = 0; i < num1; i++){
			str = in.readLine();
			tokens = new StringTokenizer(str, " ");
			for(j = 0; j < num1; j++){
				w = Integer.parseInt(tokens.nextToken());
				if(i == j) {
					arr[i][j] = 0;
				}
				else if(w == 0){
					arr[i][j] = MAX_VAL;
				}
				else {
					arr[i][j] = 1;
				}
			}
		}
		// ��������� ������� �ǵ��� �ü� �ִ�. �ܼ� ���������
		for(i = 0; i < num1; i++){				// ���İ�����
			for(j = 0; j < num1; j++){			// ��� ��
				for(k = 0; k < num1; k++){		// ������
					if(arr[j][i] != MAX_VAL && arr[i][k] != MAX_VAL){			// ���İ��� ��ΰ� ������ ������
						arr[j][k] = arr[j][i] + arr[i][k];
					}
				}
			}
		}
		for(i = 0; i < num1; i++){				
			for(j = 0; j < num1; j++){		
				long temp = arr[i][j];
				
				if(temp == MAX_VAL || temp == 0){
					temp = 0;
				}
				else {
					temp = 1;
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