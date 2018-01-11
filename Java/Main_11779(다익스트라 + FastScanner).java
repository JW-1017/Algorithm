import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.Vector;
import java.io.IOException;
import java.io.InputStreamReader;

/*
input
5
8
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
1 5

output
4
3
1 3 5

https://www.acmicpc.net/problem/11779
/* Copyright (C) 2018 by Son */

class Vertex implements Comparable<Vertex>{
	public int index;
	public int dist;

	@Override
	public int compareTo(Vertex temp) {
		// TODO Auto-generated method stub
		int t_dist = temp.dist;
		return this.dist - t_dist;
	}
	public Vertex(int index, int dist){
		this.index = index;
		this.dist = dist;
	}
}
class Pair{
	public int des;
	public int dist;
	
	public Pair(int des, int dist){
		this.des = des;
		this.dist = dist;
	}
}
public class Main {
	static class FastScanner
    {
        BufferedReader br;
        StringTokenizer st;
 
        public FastScanner() {br = new BufferedReader(new InputStreamReader(System.in));}
        String next() // ��ū������ ����
        {
            while (st == null || !st.hasMoreElements()){
                try { st = new StringTokenizer(br.readLine()); }
                // ����ó��
                catch (IOException  e){e.printStackTrace();}
            }
            return st.nextToken();
        }
        
        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
        double nextDouble() { return Double.parseDouble(next()); }
        
        String nextLine()
        {
            String str = "";
            try {str = br.readLine();}
            // ����ó��
            catch (IOException e){e.printStackTrace();}
            return str;
        }
    }
	public static void main(String[] args) throws IOException {
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		FastScanner scan = new FastScanner();
		
		int i, len, a, b, c, n, d;
		int index, t_dist, cost;
		Pair p;
		
		final int MAX_VAL = 999999999;
		int v_num = scan.nextInt();
		
		int bus_num = scan.nextInt();
		
		int dist[] = new int[v_num + 1];
		Arrays.fill(dist, MAX_VAL);
		Stack<Integer> route = new Stack<Integer>();
		Vector<Vector<Pair>> adj = new Vector<Vector<Pair>>();
		for(i = 0; i <= v_num; i++){
			adj.add(new Vector<Pair>());
		}
		PriorityQueue<Vertex> pq = new PriorityQueue<Vertex>();
		int map[] = new int[v_num+1];
		
		for(i = 0; i < bus_num; i++){
			a = scan.nextInt();
			b = scan.nextInt();
			c = scan.nextInt();
			adj.get(a).add(new Pair(b,c));		// ������ , �Ÿ��� Pair�� ����
		}
		int start = scan.nextInt();
		int end = scan.nextInt();
		
		dist[start] = 0;
		map[start] = -1;				// ������ ���� ���� (-1�� ���� ��ġ)
		pq.add(new Vertex(start, 0));
		
		while(!pq.isEmpty()){
			Vertex temp = pq.poll();
			index = temp.index;
			t_dist = dist[index];
			cost = temp.dist;
			// ���� ��쵵 �����ؾߵ� �ֳĸ� Vertex�� ����Ǿ ť�� �� Vertex���� �� ���� �����ؾ� �ϹǷ� (���� ������ ����Ǽ� �ִܰŸ��� �ٽ� ã�� ��)
			if(t_dist < cost){			
				continue;
			}
			len = adj.get(index).size();
			
			for(i = 0; i < len; i++){
				p = adj.get(index).get(i);
				n = p.des;
				d = t_dist + p.dist;		// index�� ���� n���� ���� ���
				if(dist[n] > d){
					dist[n] = d;
					pq.add(new Vertex(n, d));
					map[n] = index;
				}
			}
		}
		int v_index = end;
		while(v_index!=-1) {
			route.push(v_index);
			v_index = map[v_index];
		}
		len = route.size();
		bw.write(dist[end] + "\n");
		bw.write(len + "\n");
		for(i = 0; i < len; i++){
			bw.write(route.pop() + " ");
		}
		bw.close();
	}
}