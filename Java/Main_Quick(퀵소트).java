package base;

import java.util.Scanner;

public class Main_Quick  {	

	public static void main(String[] args) {
		int num;
		Scanner scan = new Scanner(System.in);
		
		num = scan.nextInt();
		
		int arr[] = new int[num];
		
		for(int i = 0; i < num; i++){
			arr[i] = scan.nextInt();
		}
		quickSort(arr, 0, num-1);
		
		for(int i = 0; i < num; i++){
			System.out.println(arr[i]);
		}
	}
	
	public static void swap(int arr[], int i, int j){
		int temp;
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	
	public static void quickSort(int arr[], int firstarr, int lastarr){
		int leftward, rightward;
		int pivot;
		
		if (lastarr > firstarr){
			pivot = arr[lastarr];
			leftward = firstarr - 1;
			rightward = lastarr;
			
			while(leftward < rightward){
				do{
					if(leftward == lastarr){
						break;
					}
					leftward++;
				} while(arr[leftward] < pivot);
				do{
					if(rightward == firstarr){
						break;
					}
					rightward--;
				} while(arr[rightward] > pivot);
				if(leftward < rightward){
					swap(arr, leftward, rightward);
				}
			}
			swap(arr, leftward, lastarr);
			quickSort(arr, firstarr, leftward-1);
			quickSort(arr, leftward + 1, lastarr);
		}
	}
}
