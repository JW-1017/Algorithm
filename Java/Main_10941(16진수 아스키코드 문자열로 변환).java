import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

/*
input
4261656B6A6F6F6E

output
Baekjoon

https://www.acmicpc.net/problem/10941
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String str = in.readLine();
		char[] temp = str.toCharArray();
		int len = str.length();
		str = "";
		
		for(int i = 0; i < len; i++){
			char val = 0;
			if(temp[i] >= 'A' && temp[i] <= 'F'){
				val += (16 * (10 + temp[i] - 'A'));
			}
			else{
				val += (16*(temp[i] - '0'));
			}
			if(temp[i+1] >= 'A' && temp[i+1] <= 'F'){
				val += (10 + temp[i+1] - 'A');
			}
			else{
				val += (temp[i+1] - '0');
			}
			str += val; i++;
		}
		bw.write(str + "\n");
		in.close();
		bw.close();
	}
}