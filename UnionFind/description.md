### **서로소 집합 (Disjoint Set, Union-Find)**

교집합이 공집합인 집합들의 정보를 확인(Find)하고, 조작(Union) 할 수 있는 자료구조

- Union : 어떤 두 원소 a, b에 대해 union(a,b)는 각 원소가 속한 집합을 하나로 합침
- Find : 어떤 원소 a에 대해 find(a)는 a가 속한 집합의 대표번호를 반환

**구현**

1. 초기화

```cpp
vector<int> parent;

void initialize() {
	for(i : nums) {
		parent[i] = i;
	}
}
```


2. Union 연산

```cpp
void union(int a, int b){
	aRoot = find(a);
	bRoot = find(b);
	
	if(aRoot != bRoot)
		parent[aRoot] = bRoot;
		// parent[bRoot] = aRoot;
}
```


3. Find 연산
```cpp
int find(int a) {
	if(parent[a] == a) return a;
	else return parent[a] = find(parent[a]);
}
```
