import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.StringTokenizer;
import java.io.IOException;

/*
input
12 11
1 2
2 3
3 4
4 5
5 0
6 3
7 4
8 5
9 4
10 5
11 5

output
5
 
https://www.acmicpc.net/problem/14953
*/

public class Main {

	static int count[];
	static long edge[];
	static HashMap<Integer, HashSet<Integer>> map;
	public static void main(String[] args) throws IOException {
		long MAX_VAL = 0;		
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int i, u, v;
		
		String str = in.readLine();
		StringTokenizer tokens = new StringTokenizer(str, " ");
		int num1 = Integer.parseInt(tokens.nextToken());
		int num2 = Integer.parseInt(tokens.nextToken());
		
		map = new HashMap<Integer, HashSet<Integer>>();
		count = new int[num1];
		edge = new long[num1];
		Arrays.fill(count, 0);
		Arrays.fill(edge, -1);
		
		if(num1 == 1 || num2 == 0){
			bw.write(1 + "\n");
			bw.close();
			in.close();
			return;
		}
		
		for(i = 0; i < num2; i++){
			str = in.readLine();
			tokens = new StringTokenizer(str, " ");
			u = Integer.parseInt(tokens.nextToken());
			v = Integer.parseInt(tokens.nextToken());
			if(!map.containsKey(u)){
				map.put(u, new  HashSet<Integer>());
			}
			if(!map.containsKey(v)){
				map.put(v, new  HashSet<Integer>());
			}
			map.get(u).add(v);
			map.get(v).add(u);
			count[u]++;
			count[v]++;
		}
		for(i = 0; i < num1; i++){
			Iterator<Integer> iter = map.get(i).iterator();
			while(iter.hasNext()){
				int temp = iter.next();
				edge[i] = Reculsolve(i, temp);
			}
			MAX_VAL = Math.max(edge[i], MAX_VAL);
		}
		bw.write((MAX_VAL+1) + "\n");
		bw.close();
		in.close();
	}
	public static long Reculsolve(int prd, int aft){
		if(count[prd] <= count[aft]){				// count 값이 작으면
			if(edge[prd] == -1){
				return 0;
			}
			return edge[prd];						
		}
		if(edge[aft] != -1){						// 이미 존재하는 aft 일 때 prd 혹은 +1로 갱신
			return edge[prd] = Math.max(edge[prd], edge[aft]+1);
		}
		long value;
		Iterator<Integer> iter = map.get(aft).iterator();
		while(iter.hasNext()){
			int temp = iter.next();
			if(temp == aft || temp == prd){
				continue;
			}
			value = 0;
			value += (1 + Reculsolve(aft, temp));
			
			edge[prd] = Math.max(edge[prd], value);
		}
		if(edge[prd] == -1 || edge[prd] == 0){		// 마지막에 도달 했을 때 2개가 이어져있으므로
			edge[prd] = 1;
		}
		return edge[prd];
	}
}