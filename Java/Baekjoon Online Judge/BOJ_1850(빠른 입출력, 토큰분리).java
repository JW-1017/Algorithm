import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.io.IOException;

/*
input
3 6

output
111

https://www.acmicpc.net/problem/1850
/* Copyright (C) 2017 by Son */
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String str1 = in.readLine();
		
		String str2[] = str1.split(" ");
		
		BigInteger a = new BigInteger(str2[0]);
		BigInteger b = new BigInteger(str2[1]);
		
		while(!b.equals(BigInteger.ZERO))
		{
			BigInteger temp = a.mod(b);
			a = b;
			b = temp;
		}
		int k = a.intValue();
		for(int i = 0; i < k; i++){
			bw.write("1");
		}
		bw.write("\n");
		
		in.close();
		bw.close();
	}
}