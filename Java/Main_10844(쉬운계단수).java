import java.util.Arrays;
import java.util.Scanner;

/*
 input
 1
 2
 
 output
 9
 17
 
 https://www.acmicpc.net/problem/10844
 */

public class Main {
	static long arr[][];
	static final long Max = 1000000000;
	
	public static void main(String[] args) {
		int i, num;
		long result = 0;
		Scanner scan = new Scanner(System.in);
		
		num = scan.nextInt();
		
		arr = new long[10][num];
		
		for(i = 0; i < 10; i++){
			Arrays.fill(arr[i], -1);
		}
		for (i = 1; i <= 9; i++) {
			result += recursive_solve(i, num);
			result %= Max;
		}
		System.out.println(result);
	}
	public static long recursive_solve(int value, int num) {
		if (num == 1) {
			return 1;
		}
		if (arr[value][num - 1] >= 0) {
			return arr[value][num - 1];
		}
		if (value == 0) {
			return (arr[0][num - 1] = recursive_solve(1, num - 1) % Max);
		}
		else if (value == 9) {
			return (arr[9][num - 1] = recursive_solve(8, num - 1) % Max);
		}
		else {
			return (arr[value][num - 1] = (recursive_solve(value - 1, num - 1) % Max) + (recursive_solve(value + 1, num - 1) % Max));
		}
	}
}