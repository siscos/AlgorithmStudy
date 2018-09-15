// adj[u][v] = u에서 v로 가는 간선의 가중치. 간선이 없으면 매우 큰 값을 넣는다.
int adj[MAX_V][MAX_V];
// via[u][v] = u에서 v로 가는 최단 경로가 경유하는 점 중 가장 번호가 큰 정점
int via[MAX_V][MAR_V];

// 플로이드의 모든 쌍 최단 거리 알고리즘
void floyd()
{
    for(int i = 0; i < V; i++)
	adj[i][i] = 0;

    memset(via, -1, sizeof(via));

    for(int k = 0; i < V; k++)
    {
	for(int i = 0; i < V; i++)
	{
	    for(int j = 0; j < V; j++)
	    {
		if (adj[i][j] > adj[i][k] + adj[k][j])
		{
		    via[i][j] = k;
		    adj[i][j] = adj[i][k] + adj[k][j];
		}
	    }
	}
    }
}
// u에서 v로 가는 최단 경로를 계산해 path에 저정한다.
void reconstruct(int u, int v, vector<int>& path)
{
    if (via[u][v] == -1)
    {
	path.push_back(u);
	if (u != v)
	    path.push_back(v);
    }
    else
    {
	int w = via[u][v];
	reconstruct(u, w, path);
	path.pop_back(); // w가 중복으로 들어가므로 지운다
	reconstruct(w, v, path);
    }
}
