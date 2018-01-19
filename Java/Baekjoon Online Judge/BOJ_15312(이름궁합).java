package base;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
/*
input
CJM
HER

output
99

https://www.acmicpc.net/problem/15312
/* Copyright (C) 2017 by Son */
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int arr[] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
		
		String str1 = in.readLine();
		String str2 = in.readLine();
	
		int len = str1.length();
		
		len = 2*len;
		int end = len;
		
		int result[] = new int[len];
		int j = 0;
		for(int i = 0; i < len; i+=2){
			result[i] = arr[str1.charAt(j) - 'A'];
			result[i+1] = arr[str2.charAt(j) - 'A'];
			j++;
		}
		for(int i = 0; i < len-2; i++){
			for(j = 0; j < end-1; j++){
				result[j] = (result[j] + result[j+1]) % 10;
			}
			end--;
		}
		bw.write(result[0]+""+result[1]+"\n");
		in.close();
		bw.close();
	}
}