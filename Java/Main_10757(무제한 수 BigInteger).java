package base;

import java.util.Scanner;
import java.math.BigInteger;

/*
 input
9223372036854775807 9223372036854775808
 
 output
 18446744073709551615
 
 https://www.acmicpc.net/problem/10757
 */

public class Main {
	
	public static void main(String[] args) {
		BigInteger a;
		BigInteger b;
		
		Scanner scan = new Scanner(System.in);
		
		a = scan.nextBigInteger();
		b = scan.nextBigInteger();
		
		System.out.println(a.add(b));
	}
	
}