import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.io.IOException;

/*
input
3
15 21
33 22
9 10

output
105
66
90

https://www.acmicpc.net/problem/5347
/* Copyright (C) 2017 by Son */
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String str1 = in.readLine();
		int end = Integer.parseInt(str1);
		
		for(int i = 0; i < end; i++){
			str1 = in.readLine();
			StringTokenizer tokens = new StringTokenizer(str1, " ");
			String aa = tokens.nextToken();
			String bb = tokens.nextToken();
			
			long a1 = Long.parseLong(aa);
			long a2 = Long.parseLong(bb);
			long temp;
			long b = a1 * a2;
		
			while(a2 != 0){
				temp = a1 % a2;
				a1 = a2;
				a2 = temp;
			}
		
			bw.write(b / a1 + "\n");
		}
		in.close();
		bw.close();
	}
}