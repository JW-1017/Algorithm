import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

/*
input
Baekjoon

output
4261656B6A6F6F6E

https://www.acmicpc.net/problem/10940
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String str = in.readLine();
		String str2 = "";
		int len = str.length();
		char[] temp = str.toCharArray();
		
		for(int i = 0; i < len; i++){
			int a = temp[i] / 16;
			int b = temp[i] % 16;
			str2 += String.valueOf(a);
			if(b >= 10){
				str2 += (char)('A' + (b - 10));
			}
			else{
				str2 += String.valueOf(b);
			}
		}
		bw.write(str2 + "\n");
		in.close();
		bw.close();
	}
}