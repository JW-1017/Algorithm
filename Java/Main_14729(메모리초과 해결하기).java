import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.io.IOException;

/*
input
8
20.000
70.000
50.000
30.000
70.000
30.000
60.000
70.000

output
20.000
30.000
30.000
50.000
60.000
70.000
70.000

https://www.acmicpc.net/problem/14729
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String str = in.readLine();
		int num = Integer.parseInt(str);
		
		// 사실상 소수점을 1로 바꾸고 숫자를 합치기 때문에 7자리수
		// 입력횟수보다 숫자범위가 더 좁기 때문에 중복되는 숫자가 있으면 count하고 횟수만큼 출력(메모리 제한 때문)
		int arr[] = new int[1002000];
		
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>();		// 최소 뽑아내기
		
		for(int i = 0; i < num; i++){
			str = in.readLine();
			StringTokenizer tokens = new StringTokenizer(str, ".");		// '.'을 기준
			int temp = Integer.parseInt(tokens.nextToken() + "1" + tokens.nextToken());	// .을 1로 바꿔서 0.xxx도 일단은 4자리로 저장됨
			if(arr[temp] != 0){
				arr[temp]++;
			}
			else{				// 존재하면 카운팅 증가
				arr[temp]++;
				pq.add(temp);
			}
		}
		for(int i = 0; i < 7; i++){
			int temp = pq.poll();					
			String str_temp = String.valueOf(temp);	
			int len = str_temp.length();
			char[] c_temp = str_temp.toCharArray();
			c_temp[len - 1 - 3] = '.';					// 1이 있었던 자리 소수점으로 다시 변환
			str_temp = String.valueOf(c_temp);			
			if(len == 4) {								// 0.xxx는 .xxx로 결과가 생기므로 길이가 4이면 앞에 0만 붙여줌
				str_temp = "0" + str_temp;
			}
			len = arr[temp];		
			bw.write(str_temp + "\n");					// 일단 우선순위 큐에서 뽑은거 출력
			for(int j = 1; j < len; j++){				// 한번 출력했으니 한번 감소하여 j는 1부터
				i++;									// i 동일하게 증가해주어야됨 (7번 출력이 정해져있으므로)
				if(i == 7){			
					break;
				}
				bw.write(str_temp + "\n");
			}
		}
		
		in.close();
		bw.close();
	}
}