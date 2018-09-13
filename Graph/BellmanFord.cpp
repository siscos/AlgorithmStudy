// 벨만-포드 알고리즘은 다익스트라 알고리즘과 똑같은 단일 시작점 최단 경로
// 알고리즘이지만, 음수 간선이 있는 경우에도 그래프에 대해서 최단 경로는 찾을 수
// 있으며 그래프에 음수 사이클이 있어서 최단 거리가 제대로 정의되지 않을 경우도
// 알려준다.

// 정점의 개수
int V;
// 그래프의 인접 리스트(연결된 정점 번호, 간선 가중치) 쌍을 담는다.
vector<pair<int, int>> adj[MAX_V];
// 음수 사이클이 있을 경우 텅빈 배열을 반환
vector<int> bellmanFord(int src)
{
    vector<int> upper(V, INF);
    upper[src] = 0;
    bool update;
    
    // V번 순회한다.
    for(int iter = 0; iter < V; iter++)
    {
	update = false;
	for(int here = 0; here < V; here++)
	{
	    for(int i = 0; i < adj[here].size(); i++)
	    {
		int there = adj[here][i].first;
		int cost = adj[here][i].second;
		// (here, there) 간선을 따라 완화를 시도한다.
		if (upper[there] > upper[here]  + cost)
		{
		    upper[there] = upper[here] + cost;
		    update = true;
		}
	    }
	}

	// 모든 간선에 대한 완화가 실패했을 경우 V - 1번도 돌 필요없이 바로 종료한다.
	if (!update)
	    break;
    }

    // V번 순회에서도 완화가 성공했다면 음수 사이클이 있다. 
    if (update)
	upper.clear();

    return upper;
}
