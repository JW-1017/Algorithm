import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.io.IOException;

/*
input
adaabc aababbc

output
2

https://www.acmicpc.net/problem/1120
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int end;
		int min = 51;
		
		String str1 = in.readLine();
		StringTokenizer tokens = new StringTokenizer(str1, " ");
		String str2 = tokens.nextToken();
		String str3 = tokens.nextToken();
		
		int len2 = str2.length();		// 짤은거
		int len3 = str3.length();		// 긴거
		
		int i = 0;
		
		while(true){
			int count = 0;
			// 비교당하는 애는 시작요소 밑 끝요소 증가(+1)
			end = len2 + i;
			if(end > len3){
				break;
			}
			// 비교하는 애는 요소 0 부터 비교
			int s = 0;
			for(int j = i; j < end; j++){
				if(str2.charAt(s) != str3.charAt(j)){
					count++;
				}
				s++;
			}
			i++;
			min = Math.min(min, count);
		}
		bw.write(min + "\n");
		in.close();
		bw.close();
	}
}