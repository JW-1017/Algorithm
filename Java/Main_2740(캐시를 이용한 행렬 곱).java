import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.io.IOException;

/*
input
3 2
1 2
3 4
5 6
2 3
-1 -2 0
0 0 3

output
-1 -2 6
-3 -6 12
-5 -10 18

https://www.acmicpc.net/problem/2740
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String str = in.readLine();
		StringTokenizer tokens = new StringTokenizer(str, " ");
		
		int row = Integer.parseInt(tokens.nextToken());
		int col = Integer.parseInt(tokens.nextToken());
		
		int arr1[][] = new int[row][col];
		
		for(int i = 0; i < row; i++){
			str = in.readLine();
			tokens = new StringTokenizer(str, " ");
			for(int j = 0; j < col; j++){
				arr1[i][j] = Integer.parseInt(tokens.nextToken());
			}
		}
		str = in.readLine();		
		tokens = new StringTokenizer(str, " ");
		int row2 = Integer.parseInt(tokens.nextToken());
		int col2 = Integer.parseInt(tokens.nextToken());
		int arr2[][] = new int[col2][row2];		// ����� (ĳ�� Ȱ��)
		for(int i = 0; i < row2; i++){
			str = in.readLine();
			tokens = new StringTokenizer(str, " ");
			for(int j = 0; j < col2; j++){
				// �Է� ������ �� ���� �ຯ��Ǹ鼭 ����
				arr2[j][i] = Integer.parseInt(tokens.nextToken());
			}
		}
		// arr2���� col2�� �� row2�� ��     col == row2 ��
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col2; j++){
				int result = 0;
				for(int k = 0; k < col; k++){
					// �տ� �� ��������  �ݴ��� �� ���ϰ� ���ؼ� ������µ� ����� ����� �ೢ�� ����
					result += arr1[i][k]*arr2[j][k];		
				}
				//arr3[i][j] = result;	���ο� ����� ����ٰ� �����ϸ�
				if(j != col2-1){
					bw.write(result + " ");
				}
				else{
					bw.write(result + "\n");
				}
			}
		}
		in.close();
		bw.close();
	}
}