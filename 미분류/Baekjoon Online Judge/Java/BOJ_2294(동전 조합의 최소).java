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
		
		int k = 10001;		// �ִ밪 ���� (�ּҸ� ���ϱ� ����, �Ѿ�� �����Ƿ� ����)
		
		Arrays.fill(count, k);
		
		for(i = 0; i < num; i++){
			str = in.readLine();
			st[i] = Integer.parseInt(str);
		}
		
		for(i = 0; i < num; i++){
			for(j = 1; j <= target; j++){
				if(j == st[i]){
					count[j] = 1;		// ���ϸ� �׳� 1��
				}
				else if(j > st[i]){
					count[j] = Math.min(count[j], count[j - st[i]] + 1);		// ����� �ش� ���� ������ + 1(st[i]��ŭ ���ؼ�) �� 
				}
			}
		}
		if(count[target] >= k){				// ���ų� �Ѿ ������
			count[target] = -1;
		}
		bw.write(count[target] + "\n");
		in.close();
		bw.close();
	}
}