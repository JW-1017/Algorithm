import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;

/*
input
6
3
3 4
2 5
5 3
3
3 D
15 L
17 D

output
9

https://www.acmicpc.net/problem/3190
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int dp[] = {1,0,0,0}; // x+ y+ x- y- ����
		
		String str = in.readLine();
		int i, j, k;
		int time_start, time_end = 0;   // �ð��� ����, ��
		int row = 0, col = 0;			// �Ӹ�
		int col_add = 0, row_add = 0;			// ������ȯ�� ���� �̵�(���� ��ȯ �������� �̵��� ������)
		int row_end = 0, col_end = 0; 	// ������ ��
		int result = 0;
		int N = Integer.parseInt(str);
		int arr[][] = new int[N][N];	// ��ġ���� ���ڸ��� 2 ���ڸ� 0 ��� 1
		int dir[][] = new int[N][N];	// �������� (���� ������ ����)
		dir[0][0] = 0;			// dp �ε��� ����
		
		for(i = 0; i < N; i++){
			Arrays.fill(arr[i], 0);
		}
		str = in.readLine();
		int count = Integer.parseInt(str);
		for(i = 0; i < count; i++){
			str = in.readLine();
			StringTokenizer tokens = new StringTokenizer(str, " ");
			arr[Integer.parseInt(tokens.nextToken()) - 1][Integer.parseInt(tokens.nextToken()) - 1] = 1;
		}
		str = in.readLine();
		count = Integer.parseInt(str);
		for(i = 0; i < count; i++){
			time_start = time_end+1;
			str = in.readLine();
			StringTokenizer tokens = new StringTokenizer(str, " ");
			time_end = Integer.parseInt(tokens.nextToken());
			// ������ ���� �̵� �˾Ƴ���
			col_add = 0; row_add = 0;
			for(k = 0; k < 4; k++){
				if(dp[k] != 0){
					if(k % 2 == 0){				// 2�� ������������ ���� x����
						if(k < 2) col_add = 1;
						else col_add = -1;
					}
					else{
						if(k < 2) row_add = 1;
						else row_add = -1;
					}
					break;
				}
			}
			// �ð����� �̵�
			for(j = time_start; j <= time_end; j++){
				result++;
				col += col_add;
				row += row_add;
				if(col == N || row == N || col == -1 || row == -1){		// ���� ������ ��
					bw.write(result + "\n");
					in.close();
					bw.close();
					return;
				}
				if(arr[row][col] == 2){		// ���� ������ ��
					bw.write(result + "\n");
					in.close();
					bw.close();
					return;
				}
				dir[row][col] = k;
				if(arr[row][col] == 1){		// ��������� ����
					arr[row][col] = 2;
				}
				else{			// ��� ������ ���� �߶󳻱�
					arr[row][col] = 2;
					arr[row_end][col_end] = 0;
					// ���⿡ ���� ���� �߶󳻱�
					if(dir[row_end][col_end] % 2 == 0){				
						if(dir[row_end][col_end] < 2) col_end++;
						else col_end--;
					}
					else{
						if(dir[row_end][col_end] < 2) row_end++;
						else row_end--;
					}
				}
			}
			// ������� ������
			String direction = tokens.nextToken();
			if(direction.equals("L")){
				dp[k] = 0;		// ������ k ������
				if(k == 0){
					dp[3] = 1;
					dir[row][col] = 3;
				}
				else {
					dp[k-1] = 1;
					dir[row][col] = k-1;
				}
			}
			else{
				dp[k] = 0;		// ������ k ������
				if(k == 3){
					dp[0] = 1;
					dir[row][col] = 0;
				}
				else {
					dp[k+1] = 1;
					dir[row][col] = k+1;
				}
			}
		}
		
		// ������ȯ ����� �� ������ ������ �������� ��� ����
		col_add = 0; row_add = 0;
		for(k = 0; k < 4; k++){
			if(dp[k] != 0){
				if(k % 2 == 0){
					if(k < 2) col_add = 1;
					else col_add = -1;
				}
				else{
					if(k < 2) row_add = 1;
					else row_add = -1;
				}
				break;
			}
		}
		while(true){
			result++;
			col += col_add;
			row += row_add;
			if(col == N || row == N || col == -1 || row == -1){		// ���� ������ ��
				bw.write(result + "\n");
				in.close();
				bw.close();
				return;
			}
			if(arr[row][col] == 2){		// ���� ������ ��
				bw.write(result + "\n");
				in.close();
				bw.close();
				return;
			}
			dir[row][col] = k;
			if(arr[row][col] == 1){		// ��������� ����
				arr[row][col] = 2;
			}
			else{			// ��� ������ ���� �߶󳻱�
				arr[row][col] = 2;
				arr[row_end][col_end] = 0;
				if(dir[row_end][col_end] % 2 == 0){
					if(dir[row_end][col_end] < 2) col_end++;
					else col_end--;
				}
				else{
					if(dir[row_end][col_end] < 2) row_end++;
					else row_end--;
				}
			}
		}
	}
}