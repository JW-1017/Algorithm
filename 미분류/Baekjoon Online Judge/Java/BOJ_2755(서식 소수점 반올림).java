package base;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.io.IOException;

/*
input
7
General_Physics_1 3 A+
Introduction_to_Computer_Science_and_Eng 3 B0
Reading_And_Writing 2 C0
English_1 3 C+
Analytic_Geometry_and_Calculus_1 3 B+
Fortran_Programming 3 B+
C_Language_Programming 3 A+

output
3.28

https://www.acmicpc.net/problem/2755
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		HashMap<String, Double> map = new HashMap<String, Double>();
		
		map.put("A+", 4.3);
		map.put("A0", 4.0);
		map.put("A-", 3.7);
		map.put("B+", 3.3);
		map.put("B0", 3.0);
		map.put("B-", 2.7);
		map.put("C+", 2.3);
		map.put("C0", 2.0);
		map.put("C-", 1.7);
		map.put("D+", 1.3);
		map.put("D0", 1.0);
		map.put("D-", 0.7);
		map.put("F", 0.0);
		
		double sum_h = 0;
		double ave_g = 0;
		double temp_h;
		
		String str = in.readLine();
		StringTokenizer tokens;
		int num = Integer.parseInt(str);
		
		for(int i = 0; i < num; i++){
			str = in.readLine();
			tokens = new StringTokenizer(str, " ");
			tokens.nextToken();
			temp_h = Double.parseDouble(tokens.nextToken());
			sum_h += temp_h;
			ave_g += temp_h * map.get(tokens.nextToken());
		}
		System.out.printf("%.2f\n",ave_g / sum_h);
		in.close();
		bw.close();
	}
}