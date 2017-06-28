package base;

import java.util.Scanner;

/*
input
3 5 9

output
3
https://www.acmicpc.net/problem/2965
*/

public class Main_2965 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int count = 0, dis1, dis2;
		Scanner scan = new Scanner(System.in);
		
		Integer arr[] = new Integer[3];
		
		for(int i = 0; i < 3; i++){
			arr[i] = scan.nextInt();
		}
		while(true){
			dis1 = arr[1] - arr[0];
			dis2 = arr[2] - arr[1];
			if((dis1 == 1) && (dis2 == 1)){
				break;
			}
			if(dis1 > dis2){
				arr[2] = arr[1];
				arr[1] = arr[1] - 1;
				count++;
			}
			else{
				arr[0] = arr[1];
				arr[1] = arr[1] + 1;
				count++;
			}
		}
		System.out.println(count);
	}
}
