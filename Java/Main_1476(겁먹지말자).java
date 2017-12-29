package base;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.io.IOException;

/*
input
15 28 19

output
7980

https://www.acmicpc.net/problem/1476
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		long result = 1;
		String str = in.readLine();
		StringTokenizer tokens = new StringTokenizer(str, " ");
		
		int E = 1;
		int S = 1;
		int M = 1;
		
		int EE = Integer.parseInt(tokens.nextToken());
		int SS = Integer.parseInt(tokens.nextToken());
		int MM = Integer.parseInt(tokens.nextToken());
		
		while(true){
			if(E == EE && S == SS && M == MM){
				break;
			}
			if(++E > 15){
				E = 1;
			}
			if(++S > 28){
				S = 1;
			}
			if(++M > 19){
				M = 1;
			}
			result++;
		}
		bw.write(result + "\n");
		in.close();
		bw.close();
	}
}