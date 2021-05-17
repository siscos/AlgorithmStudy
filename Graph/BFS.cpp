vector<vector<int>> adj;

vector<int> bfs(int start)
{
    vector<bool> discovered(adj.size(), false);
    queue<int> q;
    // 정점의 방문 순서
	vector<int> orders;
    discovered[start] = true;
    q.push(start);
    while(!q.empty())
    {
	int here = q.front();
	q.pop();
	// here를 방문한다.
	order.push_back(here);
	for(int i = 0; i < adj[here].size(); i++)
	{
	    int there = adj[here][i];
	    if (!discovered[there])
	    {
		q.push(there);
		discovered[there] = true;
	    }
	}
    }
    return order;
}

// distance[i] = start부터 i까지의 최단 거리
// parent[i] = 너비 우선 탐색 스패닝 트리에서 i의 부모 번호, 루트인 경우 자기 자신
void bfs2(int start, vector<int>& distance, vector<int>& parent)
{
    distance = vector<int>(adj.size(), -1);
    parent = vector<int>(adj.size(), -1);

    queue<int> q;
    distance[start] = 0;
    parent[start] = start;

    q.push(start);

    while(!q.empty())
    {
	int here = q.front();
	q.pop();

	for(int i = 0; i < adj[here].size(); i++)
	{
	    int there = adj[here][i];
	    if (distance[there] == -1)
	    {
		q.push(there);
		distance[there] = distance[here] + 1;
		parent[there] = here;
	    }
	}
    }
}

// v로부터 시작점까지의 최단 경로를 계산한다.
vector<int> shortestPath(int v, const vector<int>& parent)
{
    vector<int> path(1, v);
    while(parent[v] != v)
    {
	v = parent[v];
	path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}
