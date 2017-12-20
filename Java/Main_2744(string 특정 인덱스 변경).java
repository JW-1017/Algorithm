package base;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

/*
input
WrongAnswer

output
wRONGaNSWER

https://www.acmicpc.net/problem/2744
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String str = in.readLine();
		int len = str.length();
		int gap = 'a' - 'A';
		char[] cha = str.toCharArray();	
		
		for(int i = 0; i < len; i++){
			if(cha[i] >= 'a'){
				cha[i] -= gap;
			}
			else{
				cha[i] += gap;
			}
		}
		bw.write(String.valueOf(cha) + "\n");
		
		in.close();
		bw.close();
	}
}