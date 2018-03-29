import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.io.IOException;
/*
직사각형 n, m 크기를 axa크기 몇개로 덮을 수 있는가
input
6 6 4

output
4
http://codeforces.com/problemset/problem/1/A
/* Copyright (C) 2018 by Son */
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String str = in.readLine();
		StringTokenizer tokens = new StringTokenizer(str, " ");
		
		long n = Integer.parseInt(tokens.nextToken());
		long m = Integer.parseInt(tokens.nextToken());
		long a = Integer.parseInt(tokens.nextToken());
		
		long x = n / a;
		if(n % a != 0){
			x += 1;
		}
		long y = m / a;
		if(m % a != 0){
			y += 1;
		}
		bw.write(x*y + "\n");
		in.close();
		bw.close();
	}
}