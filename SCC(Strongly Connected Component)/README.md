# Algorithm
BaekJoon Online Judge, Codeforces Problem Solving (by C++, Java)

BOJ ID : wldndsla8

- SCC(Strongly Connected Component)

SCC가 되는 그룹은 항상 최대로 정의되기 때문에 다음과 같은 조건을 만족해야 한다.


1. 같은 SCC 내의 임의의 두 정점 A,B사이의 경로가 항상 존재한다.

2. 서로 다른 SCC에서 뽑은 임의의 두 점 A,B 사이의 경로 A->B로 가는 경로와 B->A로 가는 경로는 동시에 존재할 수 없다. (SCC 끼리는 사이클이 존재하지 않는다.)

SCC를 직역하면 "강한 연결 요소" 라는 뜻이된다. 즉 SCC는 집합 내에서 정점들이 서로 왕복 가능한 최대 크기의 집합이다.

  - 코사라주 알고리즘
    (정방향 인접행렬, 역방향 인접행렬, 스택, visit 배열 필요)	
    방향 그래프를 DFS를 수행하며 끝나는 순서대로 스택에 삽입해준다. 이때 DFS는 모든 정점에 대해서 수행되어야 한다. 
    스택에서 pop하는 순서대로 역방향 DFS를 수행하여 한번 수행에 탐색되는 모든 정점들을 같은 SCC로 묶는다.

    스택이 빌 때 까지 이 작업을 반복하고 나면 SCC를 구할 수 있다.



출처: http://jason9319.tistory.com/98 [ACM-ICPC 상 탈 사람]