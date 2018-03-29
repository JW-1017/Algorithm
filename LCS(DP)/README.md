# Algorithm
BaekJoon Online Judge, Codeforces Problem Solving (by C++, Java)

BOJ ID : wldndsla8

- LCS (Longest Common Subsequence)

연속되지 않은 공통 부분 문자열 ACAYKP와 CAPCAK의 LCS는 ACAK

* 문자열 두개를 놓고 각 위치마다 최대길이에 대한 표를 만듬
한 문자열에 대해 다른 문자열로 비교하며 해당 위치 문자가 같다면 대각선 위치 + 1로 값 갱신
문자가 다르다면 위와 왼쪽 max값을 취함


* 문자열 확인을 위해서는 앞에 문자의 위치를 저장하는 배열과 현재 같은 문자열임을 나타내는 flag 배열을 선언


 - 문자열이 같을 때 앞에 문자열의 이전 좌표가 0을 포함하면 자기자신을 넣는다.

   앞에 문자열의 이전 좌표가 0을 포함하지 않으면 flag에 따라 같은 문자임을 나타내는    flag 가 1이면 앞에 좌표를 즉시 이전 좌표로 설정

   flag가 0이면 대각선 부분 이전좌표를 그대로 가져옴


 - 문자열이 다르면 길이가 더 긴쪽의 이전좌표를 가져오는데 이때도 flag에 따라 처리 