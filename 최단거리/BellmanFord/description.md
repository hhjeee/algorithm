dist[시작점] = 0; 으로 설정하고 시작

매 간선 순회할때, dist[간선.from]이 LONG_MAX이면 continue; 

함수가 반환하는 negativeCycle값이 true -> 음의 사이클 존재
dist[i]가 LONG_MAX -> 도달불가
