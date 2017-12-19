import java.util.Scanner;

/*
input
5
7
3 8
8 1 0 
2 7 4 4
4 5 2 6 5

output
30
https://www.acmicpc.net/problem/1932
*/

public class Main_1932 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int i, j, num;
		Scanner scan = new Scanner(System.in);
		
		num = scan.nextInt();
		Integer arr[][] = new Integer[num][];
		Integer temp[] = new Integer[num];		// �ش� ����� ���� ��
		Integer before[] = new Integer[num];	// ���� ����� ���� ��
		
		for(i = 0; i < num; i++){
			arr[i] = new Integer[i+1];
			for(j = 0; j < i+1; j++){
				arr[i][j] = scan.nextInt();
			}
			temp[i] = 0;				
			before[i] = 0;
		}
		
		for(i = 0; i < num; i++){
			for(j = 0; j < i+1; j++){
				if(j == 0){							
					temp[j] = (before[0] + arr[i][j]);		// �� �� ��
				}
				else if(j == i){
					temp[j] = (before[i-1] + arr[i][j]);	// �� ���� ��
				}
				else {
					temp[j] = (Math.max(before[j-1], before[j]) + arr[i][j]);		// ���� �࿡�� �ѿ��� ���̴� ��
				}
			}
			for(j = 0; j< i+1; j++){
				before[j] = temp[j];						// ����������� �� -> �� ����߿� �迭���� �ٲٱ� ������ ���ο� �迭����
			}
		}
		System.out.println(find_max(temp, num));
	}
	
	public static int find_max(Integer temp[], int length){
		int max = temp[0];

		for(int i = 1; i < length; i++){
			if(temp[i] > max){
				max = temp[i];
			}
		}
		return max;
	}
}