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
		
		int i = 2, sum = 0, a, b;		// a 분모 b 분자
		int arr[] = new int[5000];

		String str = in.readLine();
		int num = Integer.parseInt(str);
		
		// 1일때는 바로
		if(num == 1){
			bw.write(1 + "/" + 1 + "\n");
			in.close();
			bw.close();
			return;
		}
		
		// index를 저장 (분모 분자의 합이 i(배열 인덱스))
		while(true){
			sum = (i*(i-1))/2;
			arr[i] = sum;		// 자신의 종료 index를 지님
			if(arr[i] >= num){		// 바로 비교
				break;
			}
			i++;
		}
		int temp = num - arr[i-1];
		// 합이 짝수(i)는  아래에서 위로 올라옴 홀수는 그 반대
		
		// 짝수일때 아래에서 위로 오는데 분자값이 차이 값 나머지는 분모
		if(i % 2 == 0) {
			b = temp;		
			a = i - temp;
		}
		// 짝수일때 위에서 아래로 오는데 분모값이 차이 값 나머지는 분자
		else {
			a = temp;
			b = i - temp;
		}
		bw.write(a + "/" + b + "\n");
		in.close();
		bw.close();
	}
}