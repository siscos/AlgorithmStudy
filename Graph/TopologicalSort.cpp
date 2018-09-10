vector<int> seen, order;
void dfs(int here)
{
    seen[here] = 1;
    for(int there = 0; there < adj.size(); there++)
    {
	if (adj[here][there] && !seen[there])
	    dfs(there);
    }
    order.push_back(here);
}

// adj가 주어진 그래프를 위상정렬한 결과를 반환한다.
// 그래프가 DAG가 아니라면 빈 벡터를 반환한다.
vector<int> topologicalSort()
{
    int n = adj.size();
    seen = vector<int>(n, 0);
    order.clear();
    for(int i = 0; i < n; i++)
    {
	if (!seen[i])
	    dfs(i);
    }

    reverse(order.begin(), order.end());
    // 만약 그래프가 DAG가 아니라면 정렬 결과에 역방향 간선이 있다.
    for(int i = 0; i < n; i++)
    {
	for(int j = i + 1; j < n; j++)
	{
	    if (adj[order[j]][order[i]])
		return vector<int>();
	}
    }
    return order;
}
