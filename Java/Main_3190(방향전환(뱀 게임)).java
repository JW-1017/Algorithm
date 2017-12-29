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
		
		int dp[] = {1,0,0,0}; // x+ y+ x- y- 방향
		
		String str = in.readLine();
		int i, j, k;
		int time_start, time_end = 0;   // 시간의 시작, 끝
		int row = 0, col = 0;			// 머리
		int col_add = 0, row_add = 0;			// 방향전환에 따른 이동(방향 전환 전까지는 이동이 고정임)
		int row_end = 0, col_end = 0; 	// 꼬리의 끝
		int result = 0;
		int N = Integer.parseInt(str);
		int arr[][] = new int[N][N];	// 위치정보 뱀자리는 2 빈자리 0 사과 1
		int dir[][] = new int[N][N];	// 방향정보 (꼬리 삭제를 위해)
		dir[0][0] = 0;			// dp 인덱스 따라감
		
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
			// 방향을 통한 이동 알아내기
			col_add = 0; row_add = 0;
			for(k = 0; k < 4; k++){
				if(dp[k] != 0){
					if(k % 2 == 0){				// 2로 나눠떨어지는 곳은 x방향
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
			// 시간까지 이동
			for(j = time_start; j <= time_end; j++){
				result++;
				col += col_add;
				row += row_add;
				if(col == N || row == N || col == -1 || row == -1){		// 끝에 닿으면 끝
					bw.write(result + "\n");
					in.close();
					bw.close();
					return;
				}
				if(arr[row][col] == 2){		// 내몸 닿으면 끝
					bw.write(result + "\n");
					in.close();
					bw.close();
					return;
				}
				dir[row][col] = k;
				if(arr[row][col] == 1){		// 사과있으면 차지
					arr[row][col] = 2;
				}
				else{			// 사과 없으면 꼬리 잘라내기
					arr[row][col] = 2;
					arr[row_end][col_end] = 0;
					// 방향에 따라 꼬리 잘라내기
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
			// 여기부터 방향담당
			String direction = tokens.nextToken();
			if(direction.equals("L")){
				dp[k] = 0;		// 위에서 k 구해짐
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
				dp[k] = 0;		// 위에서 k 구해짐
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
		
		// 방향전환 명려어 다 끝나고 마지막 방향으로 계속 진행
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
			if(col == N || row == N || col == -1 || row == -1){		// 끝에 닿으면 끝
				bw.write(result + "\n");
				in.close();
				bw.close();
				return;
			}
			if(arr[row][col] == 2){		// 내몸 닿으면 끝
				bw.write(result + "\n");
				in.close();
				bw.close();
				return;
			}
			dir[row][col] = k;
			if(arr[row][col] == 1){		// 사과있으면 차지
				arr[row][col] = 2;
			}
			else{			// 사과 없으면 꼬리 잘라내기
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