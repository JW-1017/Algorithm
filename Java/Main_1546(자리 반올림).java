import java.util.Scanner;

/*
input
3
40 80 60

output
75.00
 
https://www.acmicpc.net/problem/1546
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) {
		int i, num;
		double result = 0d;
		double max_num = 0;
		double[] arr;
		Scanner scan = new Scanner(System.in);
		num = scan.nextInt();
		
		arr = new double[num];
		
		for(i = 0; i < num; i++){
			arr[i] = scan.nextInt();
			max_num = Math.max(arr[i], max_num);
		}
		for(i = 0; i < num; i++){
			//arr[i] = Math.round(((arr[i] / max_num) * 100d)*100d) / 100d;		// 소수 셋째자리에서 반올림
			arr[i] = (arr[i] / max_num) * 100d;
			result += arr[i];
		}
		System.out.printf("%.2f\n", result/num);		// 출력 서식으로 반올림
	}
}