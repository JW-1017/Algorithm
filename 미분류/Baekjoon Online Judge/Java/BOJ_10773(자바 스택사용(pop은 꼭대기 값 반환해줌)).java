import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.io.IOException;

/*
input
10
1
3
5
4
0
0
7
0
0
6

output
7

https://www.acmicpc.net/problem/10773
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String str = in.readLine();
		int num = Integer.parseInt(str);
		
		Stack<Integer> sta = new Stack<Integer>();
		
		for(int i = 0; i < num; i++){
			str = in.readLine();
			int temp = Integer.parseInt(str);
			if(temp == 0){
				sta.pop();
			}
			else{
				sta.push(temp);
			}
		}
		num = 0;
		while(!sta.empty()){
			num += sta.pop();
		}
		bw.write(num + "\n");
		in.close();
		bw.close();
	}
}