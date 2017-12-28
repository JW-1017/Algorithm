import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;
import java.io.IOException;

/*
input
5
1 1 1 6 0
2 7 8 3 1

output
18

https://www.acmicpc.net/problem/1026
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String str = in.readLine();
		int num = Integer.parseInt(str);
		int result = 0;
		
		int A[] = new int[num];
		Integer B[] = new Integer[num];		// Comparator를 위해 Integer 써야됨

		str = in.readLine();
		StringTokenizer tokens = new StringTokenizer(str, " ");
		for(int i = 0; i < num; i++){
			A[i] = Integer.parseInt(tokens.nextToken());
		}
		str = in.readLine();
		tokens = new StringTokenizer(str, " ");
		for(int i = 0; i < num; i++){
			B[i] = Integer.parseInt(tokens.nextToken());
		}
		Arrays.sort(A);
		Arrays.sort(B, new DesOrder());
		for(int i = 0; i < num; i++){
			result += A[i] * B[i];
		}
		bw.write(result + "\n");
		in.close();
		bw.close();
	}
}
class DesOrder implements Comparator<Integer>{
	@Override
	public int compare(Integer o1, Integer o2) {
		// TODO Auto-generated method stub
		// 원래는 o1.compareTo(o2)인데 정렬기준을 뒤집기 위해 *-1
		return o1.compareTo(o2) * -1; 			
	}
	
}