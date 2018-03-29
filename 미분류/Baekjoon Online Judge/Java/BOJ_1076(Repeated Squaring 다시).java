import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.io.IOException;

/*
input
yellow
violet
red

output
4700

https://www.acmicpc.net/problem/1076
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		
		map.put("black", 0);
		map.put("brown", 1);
		map.put("red", 2);
		map.put("orange", 3);
		map.put("yellow", 4);
		map.put("green", 5);
		map.put("blue", 6);
		map.put("violet", 7);
		map.put("grey", 8);
		map.put("white", 9);
		
		String str1 = in.readLine();
		String str2 = in.readLine();
		String str3 = in.readLine();
	
		String temp = String.valueOf(map.get(str1)) + String.valueOf(map.get(str2));
		long result = Long.parseLong(temp);
		result *= RepeatedSquaring(10, map.get(str3));
		
		bw.write(result + "\n");
		in.close();
		bw.close();
	}
	public static long RepeatedSquaring(long base, long exp)
	{
		long result = 1;
		
		while(exp != 0){
			if(exp % 2 == 1){
				result *= base; 
			}
			base *= base;
			exp /= 2;
		}
		return result;
	}
}