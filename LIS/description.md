1. 첫 input -> LIS 배열에 넣기
2. LIS 배열의 마지막 값보다 input이 더 큰 경우 -> LIS 배열의 맨 뒤에 넣기
3. LIS 배열의 마지막 값보다 input이 작거나 같은 경우 -> lowerbound(input)을 인덱스로 LIS배열에 넣기

input을 처리할때마다 input이 들어가게 되는 LIS 배열의 인덱스를 trace 배열에 기록하기

trace 배열의 끝부터 차례로 순회하면서 LIS 배열 값 찾기
LIS 배열의 크기가 n일때, trace 배열의 끝에서부터 값이 n-1, n-2, ... 0 까지 찾으면 됨
찾아서 스택에 넣기

스택 top 부터 차례로 pop하면서 처음부터 출력하기
