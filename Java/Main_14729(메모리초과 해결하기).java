import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.io.IOException;

/*
input
8
20.000
70.000
50.000
30.000
70.000
30.000
60.000
70.000

output
20.000
30.000
30.000
50.000
60.000
70.000
70.000

https://www.acmicpc.net/problem/14729
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String str = in.readLine();
		int num = Integer.parseInt(str);
		
		// ��ǻ� �Ҽ����� 1�� �ٲٰ� ���ڸ� ��ġ�� ������ 7�ڸ���
		// �Է�Ƚ������ ���ڹ����� �� ���� ������ �ߺ��Ǵ� ���ڰ� ������ count�ϰ� Ƚ����ŭ ���(�޸� ���� ����)
		int arr[] = new int[1002000];
		
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>();		// �ּ� �̾Ƴ���
		
		for(int i = 0; i < num; i++){
			str = in.readLine();
			StringTokenizer tokens = new StringTokenizer(str, ".");		// '.'�� ����
			int temp = Integer.parseInt(tokens.nextToken() + "1" + tokens.nextToken());	// .�� 1�� �ٲ㼭 0.xxx�� �ϴ��� 4�ڸ��� �����
			if(arr[temp] != 0){
				arr[temp]++;
			}
			else{				// �����ϸ� ī���� ����
				arr[temp]++;
				pq.add(temp);
			}
		}
		for(int i = 0; i < 7; i++){
			int temp = pq.poll();					
			String str_temp = String.valueOf(temp);	
			int len = str_temp.length();
			char[] c_temp = str_temp.toCharArray();
			c_temp[len - 1 - 3] = '.';					// 1�� �־��� �ڸ� �Ҽ������� �ٽ� ��ȯ
			str_temp = String.valueOf(c_temp);			
			if(len == 4) {								// 0.xxx�� .xxx�� ����� ����Ƿ� ���̰� 4�̸� �տ� 0�� �ٿ���
				str_temp = "0" + str_temp;
			}
			len = arr[temp];		
			bw.write(str_temp + "\n");					// �ϴ� �켱���� ť���� ������ ���
			for(int j = 1; j < len; j++){				// �ѹ� ��������� �ѹ� �����Ͽ� j�� 1����
				i++;									// i �����ϰ� �������־�ߵ� (7�� ����� �����������Ƿ�)
				if(i == 7){			
					break;
				}
				bw.write(str_temp + "\n");
			}
		}
		
		in.close();
		bw.close();
	}
}