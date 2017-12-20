import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.io.IOException;
/*
input
3

output
12

https://www.acmicpc.net/problem/1834
/* Copyright (C) 2017 by Son */
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String str1 = in.readLine();
		long num = Long.parseLong(str1);
		// n*1 + 1, n*2 + 2 ... n*(n-1) + n-1  = (1+2+...+n-1)*n + (1+2+...+n-1) <-SUM = SUM*(n+1) 
		// SUM = n(n-1)/2     따라서 (n-1)n(n+1)/2 가 정답
		BigInteger add_all = BigInteger.valueOf(num-1).multiply(BigInteger.valueOf(num)).divide(BigInteger.valueOf(2)).multiply(BigInteger.valueOf(num+1)); 
		
		bw.write(add_all.toString() + "\n");
		in.close();
		bw.close();
	}
}