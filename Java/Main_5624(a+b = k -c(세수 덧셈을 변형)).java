import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.io.IOException;

/*
input
6
1 2 3 5 7 10

output
4

https://www.acmicpc.net/problem/5624
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int result = 0, size = 0;
		String str = in.readLine();
		int num = Integer.parseInt(str);
		int arr[] = new int[num];
		HashSet<Integer> two_sum = new HashSet<Integer>();
		
		str = in.readLine();
		StringTokenizer tokens = new StringTokenizer(str, " ");
		
		// �ΰ� �� ���Ѱ��� �����ϰ� �������� �����鼭 �����ϴ��� Ȯ�� a+b+c == k -> a+b == k-c
		int temp = Integer.parseInt(tokens.nextToken());
		arr[size] = temp; size++;
		two_sum.add(temp + temp);
		
		for(int i = 1; i < num-1; i++){
			temp = Integer.parseInt(tokens.nextToken());
			// ������� ����� ���¿��� ������������ �����鼭 �����ϸ� ���� (k-c == a+b ���� Ȯ��)
			for(int j = 0; j < i; j++){
				if(two_sum.contains(temp - arr[j])){
					result++;
					break;
				}
			}
			// ���� ���� ���� ���� a+b���� ����
			for(int j = 0; j < size; j++){
				two_sum.add(temp + arr[j]);
			}
			// a+a �� ���� ����
			two_sum.add(temp + temp);
			arr[size] = temp; size++;
		}
		// ������ ���� ������ �ʿ䰡 ����
		temp = Integer.parseInt(tokens.nextToken());
		for(int j = 0; j < size; j++){
			if(two_sum.contains(temp - arr[j])){
				result++;
				break;
			}
		}
		bw.write(result + "\n");
		in.close();
		bw.close();
	}
}