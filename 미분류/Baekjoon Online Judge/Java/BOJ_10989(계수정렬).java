import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
/*
input
10
5
2
3
1
4
2
3
5
1
7

output
1
1
2
2
3
3
4
5
5
7
https://www.acmicpc.net/problem/10989
/* Copyright (C) 2017 by Son */
public class Main_10989 {	

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int i, num, max = 0, temp;
		String str;
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter( new OutputStreamWriter( System.out ) );
		
		str = in.readLine();
		num = Integer.parseInt(str);
		
		int numbers[] = new int[num];
		
		for(i = 0; i < num; i++){
			str = in.readLine();
			temp = Integer.parseInt(str);
            numbers[i] = temp;
            if (max < temp) {
                max = temp;
            }
		}
		int countArr[] = new int[max + 1];
		int result[] = new int[num];
		
		for(i = 0; i < num; i++){
			countArr[numbers[i]]++;
		}
		for(i = 1; i <= max; i++){
			countArr[i] += countArr[i-1];
		}
		for(i = num-1; i >= 0; i--){
			result[--countArr[numbers[i]]] = numbers[i];
		}
		for(i = 0; i < num; i++){
			bw.write(result[i] + "\n");
		}
		in.close();
		bw.close();
	}
}