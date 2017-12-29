import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.io.IOException;

/*
input
Baekjoon

output
IJQWK23KN5XW4===

https://www.acmicpc.net/problem/10938
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		// symbol에 대한 맵핑 테이블을 만듬
		HashMap<String, Character> map = new HashMap<String, Character>();
		map.put("00000", 'A'); map.put("00001", 'B');
		map.put("00010", 'C'); map.put("00011", 'D');
		
		for(char i = 'E'; i <= 'H'; i++){
			String t = "00";
			t += Integer.toBinaryString(i - 'A');		// 2진수로 변환
			map.put(t, i);
		}
		for(char i = 'I'; i <= 'P'; i++){
			String t = "0";
			t += Integer.toBinaryString(i - 'A');
			map.put(t, i);
		}
		for(char i = 'Q'; i <= 'Z'; i++){
			String t = Integer.toBinaryString(i - 'A');
			map.put(t, i);
		}
		for(char i = '2'; i <= '7'; i++){
			String t = Integer.toBinaryString(i - '0' + 24);
			map.put(t, i);
		}
		String str = in.readLine();
		String str2;
		String str3 = "";
		char[] temp = str.toCharArray();
		int len = str.length();
		str = "";
		
		for(int i = 0; i < len; i++){
			// 8자리 모자라면 0 패딩
			str += String.format("%8s", Integer.toBinaryString(temp[i])).replace(' ','0');
		}
		len = str.length();
		int remain;				
		if((remain = len % 5) != 0){	// 5의 배수가 못되서
			remain = 5 - remain;		// 5의 배수 채워주기 (0으로)
			for(int i = 0; i < remain; i++){
				str += "0";
			}
		}
		len += remain;					// 길이도 그만큼 증가
		// 5비트씩 잘라서 맵에 key로
		for(int i = 0; i < len; i+=5){
			str2 = "";
			int end = i+5;
			for(int j = i; j < end; j++){
				str2 += str.charAt(j);
			}
			str3 += map.get(str2);
		}
		len = str3.length();
		if((remain = len % 8) != 0){ 	// 8의 배수가 못되서
			remain = 8 - remain;		// 8의 배수 채워주기 ('='으로)
			for(int i = 0; i < remain; i++){
				str3 += "=";
			}
		}
		bw.write(str3 + "\n");
		in.close();
		bw.close();
	}
}