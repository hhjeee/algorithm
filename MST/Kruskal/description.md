### **크루스칼 알고리즘(Kruskal’s Algorithm)**

**구현**
- union-find 이용
- 이미 연결된 노드 → 연결 x
- 연결하려는 두 정점이 같은 집합인지 검사(find), 연결(union)
- 간선의 수 == 노드의 수-1 일때까지 반복

**기억할점**
- kruskal 하기전 edgeList는 cost의 오름차순으로 정렬하기
- union 할 때 edgeCount를 증가시키고, edgeCount가 노드수-1이 되면 sum 리턴
- 반복문이 끝났는데 리턴이 안된경우 -> 연결불가한 정점 존재 -> -1 리턴
