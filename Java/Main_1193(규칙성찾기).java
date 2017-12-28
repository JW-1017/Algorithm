package base;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

/*
input
15

output
1/5

https://www.acmicpc.net/problem/1193
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int i = 2, sum = 0, a, b;		// a �и� b ����
		int arr[] = new int[5000];

		String str = in.readLine();
		int num = Integer.parseInt(str);
		
		// 1�϶��� �ٷ�
		if(num == 1){
			bw.write(1 + "/" + 1 + "\n");
			in.close();
			bw.close();
			return;
		}
		
		// index�� ���� (�и� ������ ���� i(�迭 �ε���))
		while(true){
			sum = (i*(i-1))/2;
			arr[i] = sum;		// �ڽ��� ���� index�� ����
			if(arr[i] >= num){		// �ٷ� ��
				break;
			}
			i++;
		}
		int temp = num - arr[i-1];
		// ���� ¦��(i)��  �Ʒ����� ���� �ö�� Ȧ���� �� �ݴ�
		
		// ¦���϶� �Ʒ����� ���� ���µ� ���ڰ��� ���� �� �������� �и�
		if(i % 2 == 0) {
			b = temp;		
			a = i - temp;
		}
		// ¦���϶� ������ �Ʒ��� ���µ� �и��� ���� �� �������� ����
		else {
			a = temp;
			b = i - temp;
		}
		bw.write(a + "/" + b + "\n");
		in.close();
		bw.close();
	}
}