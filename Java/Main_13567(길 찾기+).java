import java.util.Scanner;

/*
input
11 14
MOVE 10
TURN 0
MOVE 2
TURN 0
MOVE 5
TURN 1
MOVE 5
TURN 1
MOVE 2
TURN 1
MOVE 3
TURN 0
TURN 0
MOVE 6

output
7 10
 
https://www.acmicpc.net/problem/13567
*/

public class Main {
	public static void main(String[] args) {
		int n, m;
		int x = 0, y = 0;
		int[] dp = {1, 0, 0, 0};			// R U L D
		String str;
		String num;
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		m = scan.nextInt();
		
		for(int i = 0; i < m; i++){
			str = scan.next();
			num = scan.next();
			scan.nextLine();
			if(str.charAt(0) == 'M'){
				for(int j = 0; j < 4; j++){
					if(dp[j] != 0){
						if(j % 2 == 0){
							x += Integer.parseInt(num) * dp[j];
							break;
						}
						else {
							y += Integer.parseInt(num) * dp[j];
							break;
						}
					}
				}
			}
			else {
				for(int j = 0; j < 4; j++){
					if(dp[j] != 0){
						if(num.equals("0")){
							dp[j] = 0;
							dp[(j + 1) % 4] = 1;
							if((j + 1) % 4 > 1){
								dp[(j + 1) % 4] = -1;
							}
							break;
						}
						else {
							dp[j] = 0;
							if(j - 1 == -1){
								dp[3] = -1;
							}
							else{
								dp[j - 1] = 1;
							}
							if(j-1 == 2){
								dp[2] = -1;
							}
							break;
						}
					}
				}
			}
			if(x >= n || x < 0 || y >= n || y < 0){
				System.out.println(-1);
				return;
			}
		}
		System.out.println(x + " " + y);
	}
}