import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.io.IOException;

/*
input
6 9
4 5

output
22 15

https://www.acmicpc.net/problem/1735
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int ja1, mo1, ja2, mo2, ja3, mo3;
		String temp;
		
		temp = in.readLine();
		
		StringTokenizer tokens = new StringTokenizer(temp, " ");
		
		ja1 = Integer.parseInt(tokens.nextToken()); 
		mo1 = Integer.parseInt(tokens.nextToken());
		
		temp = in.readLine();
		
		tokens = new StringTokenizer(temp, " ");
		
		ja2 = Integer.parseInt(tokens.nextToken()); 
		mo2 = Integer.parseInt(tokens.nextToken());
		
		mo3 = mo1*mo2;
		ja3 = ja1*mo2 + ja2*mo1;
		
		ja1 = ja3;			// 다시 결과전용으로
		mo1 = mo3;
		
		while(ja3 != 0){
			int value = mo3 % ja3;
			mo3 = ja3;
			ja3 = value;
		}
		
		bw.write(ja1 / mo3 + " " + mo1 / mo3);
		
		in.close();
		bw.close();
	}
}