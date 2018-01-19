import java.util.Arrays;
import java.util.Scanner;

/*
input
4 5
50 45 37 32 30
35 50 40 20 25
30 30 25 17 28
27 24 22 15 10

output
3
 
https://www.acmicpc.net/problem/1520
/* Copyright (C) 2017 by Son */

public class Main {
	static int M, N;
	static int[][] map;
	static int[][] memo;
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	
	public static int ReculSolve(int y, int x){
		if(y == M-1 && x == N-1){
			return 1;
		}
		if(memo[y][x] != -1){
			return memo[y][x];
		}
		memo[y][x] = 0;
		
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 0 && nx < N && ny >= 0 && ny < M && map[ny][nx] < map[y][x]){
				memo[y][x] += ReculSolve(ny, nx);
			}
		}
		return memo[y][x];
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		M = scan.nextInt();
		N = scan.nextInt();
		
		map = new int[M][];
		memo = new int[M][];
		
		for(int i = 0; i < M; i++){
			map[i] = new int[N];
			memo[i] = new int[N];
			Arrays.fill(memo[i], -1);
			for(int j = 0; j < N; j++){
				map[i][j] = scan.nextInt();
			}
		}
		System.out.println(ReculSolve(0,0));
	}
}