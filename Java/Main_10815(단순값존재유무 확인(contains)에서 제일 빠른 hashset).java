import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.io.IOException;

/*
input
5
6 3 2 10 -10
8
10 9 -5 2 3 4 5 -10

output
1 0 0 1 1 0 0 1

https://www.acmicpc.net/problem/10815
*/

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		HashSet<Integer> set = new HashSet<Integer>();
		int temp;
		String str = in.readLine();
		int num1 = Integer.parseInt(str);
		str = in.readLine();
		StringTokenizer tokens = new StringTokenizer(str, " ");
		for(int i = 0; i < num1; i++){
			temp = Integer.parseInt(tokens.nextToken());
			set.add(temp);
		}
		str = in.readLine();
		num1 = Integer.parseInt(str);
		str = in.readLine();
		tokens = new StringTokenizer(str, " ");
		for(int i = 0; i < num1 - 1; i++){
			temp = Integer.parseInt(tokens.nextToken());
			if(set.contains(temp)){
				bw.write(1 + " ");
			}
			else{
				bw.write(0 + " ");
			}
		}
		temp = Integer.parseInt(tokens.nextToken());
		if(set.contains(temp)){
			bw.write(1 + "\n");
		}
		else{
			bw.write(0 + "\n");
		}
		in.close();
		bw.close();
	}
}