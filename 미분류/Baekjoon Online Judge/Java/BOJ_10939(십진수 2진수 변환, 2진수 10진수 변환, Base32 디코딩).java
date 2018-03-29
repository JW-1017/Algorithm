import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.io.IOException;

/*
input
IJQWK23KN5XW4===

output
Baekjoon

https://www.acmicpc.net/problem/10939
/* Copyright (C) 2017 by Son */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		// symbol�� ���� ���� ���̺��� ����
		HashMap<Character, String> map = new HashMap<Character, String>();
		map.put('A', "00000"); map.put('B', "00001");
		map.put('C', "00010"); map.put('D', "00011");
		
		for(char i = 'E'; i <= 'H'; i++){
			String t = "00";
			t += Integer.toBinaryString(i - 'A');		// 2������ ��ȯ
			map.put(i, t);
		}
		for(char i = 'I'; i <= 'P'; i++){
			String t = "0";
			t += Integer.toBinaryString(i - 'A');
			map.put(i, t);
		}
		for(char i = 'Q'; i <= 'Z'; i++){
			String t = Integer.toBinaryString(i - 'A');
			map.put(i, t);
		}
		for(char i = '2'; i <= '7'; i++){
			String t = Integer.toBinaryString(i - '0' + 24);
			map.put(i, t);
		}
		String str = in.readLine();
		String str2;
		String str3 = "";
		char[] temp = str.toCharArray();
		int len = str.length();
		str = "";
		
		for(int i = 0; i < len; i++){
			if(temp[i] == '='){			// decoding�� �� '='�� ���õǴ� ��
				continue;
			}
			str += map.get(temp[i]);
		}
		len = str.length();
		// 8��Ʈ�� �߶� �ƽ�Ű�ڵ� ��ȯ
		for(int i = 0; i < len; i+=8){
			str2 = "";
			int end = i+8;
			if(end > len){		// 8��Ʈ���� ���� ��Ʈ�� ������ ����
				break;
			}
			for(int j = i; j < end; j++){
				str2 += str.charAt(j);
			}
			char val = (char) Integer.parseInt(str2, 2);	// 2���� ���ڿ��� ���� ������ ��ȯ
 			str3 += val;
		}
		bw.write(str3 + "\n");
		in.close();
		bw.close();
	}
}