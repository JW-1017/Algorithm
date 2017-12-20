package base;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.io.IOException;

/*
input
2 1 5

output
4

https://www.acmicpc.net/problem/2869
*/

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String str = in.readLine();
		StringTokenizer tokens = new StringTokenizer(str, " ");
		int a = Integer.parseInt(tokens.nextToken());
		int b = Integer.parseInt(tokens.nextToken());
		int c = Integer.parseInt(tokens.nextToken());
		if(c == a){					// 같으면 하루 걸리니까
			bw.write(1 + "\n");
		}
		else{
			bw.write(((c-a-1) / (a-b) + 2) + "\n");		// (c-a) / (a-b) + 1를 올림하는 것
		}
		in.close();
		bw.close();
	}
}