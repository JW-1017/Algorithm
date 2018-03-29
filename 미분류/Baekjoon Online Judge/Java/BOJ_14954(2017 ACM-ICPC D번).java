import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Vector;
import java.io.IOException;

/*
input
5

output
UNHAPPY

https://www.acmicpc.net/problem/14954

/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		Vector<Integer> dp = new Vector<Integer>(); 
		
		String str1 = in.readLine();
		dp.add(Integer.parseInt(str1));
		
		while(true) {
			int result = 0;
			int len = str1.length();
			for(int i = 0; i < len; i++){
				int a = str1.charAt(i) - '0';
				result += (a*a);
			}
			if(result == 1){
				bw.write("HAPPY\n");
				in.close();
				bw.close();
				return;
			}
			if(dp.contains(result)){
				bw.write("UNHAPPY\n");
				in.close();
				bw.close();
				return;
			}
			dp.add(result);
			str1 = String.valueOf(result);
		}
	}
}