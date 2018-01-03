import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.io.IOException;

/*
input
4
3 1
2 3
3 1
3 2

output
3

https://www.acmicpc.net/problem/1547
/* Copyright (C) 2017 by Son */

// ���� ������ ���� �������� (http://jason9319.tistory.com/93) �տ����� �ȴ� ��ü�� cycle x
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		// �ε����� �Ź�ȣ ���� �ε��� ��ȣ���� ��ġ
		int arr[] = {0, 1, 2, 3};
		
		String str = in.readLine();
		int num = Integer.parseInt(str);
		
		for(int i = 0; i < num; i++){
			str = in.readLine();
			StringTokenizer tokens = new StringTokenizer(str, " ");
			int num1 = Integer.parseInt(tokens.nextToken());
			int num2 = Integer.parseInt(tokens.nextToken());
			if(num1 == num2){
				continue;
			}
			int temp = arr[num1];
			arr[num1] = arr[num2];
			arr[num2] = temp;
		}
		for(int i = 1; i <= 3; i++){
			if(arr[i] == 1){
				bw.write(i + "\n");
				break;
			}
		}
		in.close();
		bw.close();
	}
}