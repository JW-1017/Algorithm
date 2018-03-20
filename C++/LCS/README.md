# Algorithm
BaekJoon Online Judge, Codeforces Problem Solving (by C++, Java)

BOJ ID : wldndsla8

- LCS (Longest Common Subsequence)

연속되지 않은 공통 부분 문자열 ACAYKP와 CAPCAK의 LCS는 ACAK

문자열 두개를 놓고 각 위치마다 최대길이에 대한 표를 만듬
한 문자열에 대해 다른 문자열로 비교하며 해당 위치 문자가 같다면 대각선 위치 + 1로 값 갱신
문자가 다르다면 위와 왼쪽 max값을 취함