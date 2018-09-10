// 주어진 그래프를 깊이 우선 탐색하여 생긴 트리를 깊이 우선 탐색 스패닝 트리 혹은 DFS 스패닝 트리라고 한다.
// 트리 간선: 스패닝 트리에 포함된 간선
// 순방향 간선: 스패닝 트리의 선조에서 자손으로 연결되지만 트리 간선은 아닌 간선
// 역방향 간선: 스패팅 트리의 자손에서 선조로 연결되는 간선
// 교차 간선: 나머지 간선
// 역방향 간선이 존재하면 그래프에 사이클이 존재함을 의미한다.



// 그래프의 인접 리스트 표현
vector<vector<int>> adj;
// discovered[i] = i번 정점의 발견 순서
// finished[i] = dfs(i)가 종료되었으면 1, 아니면 0
vector<int> discovered, finished;
// 지금까지 발견한 정점의 수
int counter = 0;
void dfs2(int here)
{
    discovered[here] = counter++;
    // 모든 인접 정점을 순회하면서
    for(int i = 0; i < adj[here].size(); i++)
    {
	int there = adj[here][i];
	cout << "(" << here << ", " << there << ") is a ";
	// 아직 방문한 적이 없다면 방문힌다
	if (discovered[there] = -1)
	{
	    cout << "tree edge" << endl;
	    dfs2(there);
	}
	// 만약 there가 here보다 늦게 발견됐으면 there은 here의 후손이다.
	else if (discovered[here] < discovered[there])
	    cout << "forward edge" << endl;
	// 만약 dfs2(there)이 종료되지 않았다면 there은 here의 선조다.
	else if (finished[there] == 0)
	    cout << "back edge" << endl;
	// 이외의 경우는 모두 교차 간선
	else
	    cout << "cross edge" << endl;
    }
    finished[here] = 1;
}
