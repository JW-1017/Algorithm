package base;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.HashMap;
import java.io.IOException;

/*
input
8
0
1
2
3
4
5
30
67

output
1
1
2
4
8
15
201061985
7057305768232953720

https://www.acmicpc.net/problem/9507
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String str = in.readLine();
		int num = Integer.parseInt(str);
		HashMap<Integer, BigInteger> map = new HashMap<Integer, BigInteger>();
		
		map.put(0, BigInteger.valueOf(1)); map.put(1, BigInteger.valueOf(1));
		map.put(2, BigInteger.valueOf(2)); map.put(3, BigInteger.valueOf(4));
		
		BigInteger a = BigInteger.valueOf(1);
		BigInteger b = BigInteger.valueOf(1);
		BigInteger c = BigInteger.valueOf(2);
		BigInteger d = BigInteger.valueOf(4);
		
		for(int i = 0; i < num; i++){
			str = in.readLine();
			int temp = Integer.parseInt(str);
			
			if(map.containsKey(temp)){			// 있으면 바로 리턴
				bw.write(map.get(temp) + "\n");
			}
			else {								// 없으면 계산
				a = BigInteger.valueOf(1);
				b = BigInteger.valueOf(1);
				c = BigInteger.valueOf(2);
				d = BigInteger.valueOf(4);
				
				for(int j = 4; j <= temp; j++){
					if(map.containsKey(j)){		// 중간에 있으면 바로 넘어가줌
						a = b; b = c; c = d; d = map.get(j);
						continue;
					}
					BigInteger result = a.add(b.add(c).add(d));
					a = b; b = c; c = d; d = result;
					map.put(j, result);
				}
				bw.write(d + "\n");
			}
		}
		
		in.close();
		bw.close();
	}
}