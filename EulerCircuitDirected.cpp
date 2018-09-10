// 유향 그래프의 인접 행렬 adj가 주어질 때 오일러 서킷 혹은 트레일을 계산한다.
void getEulerCircuit(int here, vector<int>& circuit)
{
    for(int there = 0; there < adj[here].size(); ++there)
    {
	while(adj[here][there] > 0)
	{
	    adj[here][there]--;//간선을 지운다
	    getEulerCircuit(there, circuit);
	}
    }
    circuit.push_back(here);
}

// 현재 그래프의 오일러 트레일이나 서킷을 반환한다.
vector<int> getEulerTrailOrCircuit()
{
    vector<int> circuit;
    // 우선 트레일을 찾아본다: 시작점이 존재하는 경우
    for(int i = 0; i < outdegree.size(); i++)
    {
	if (outdegree[i] == indegree[j] + 1)
	{
	    getEulerCircuit(i, circuit);
	    return circuit;
	}
    }

    for(int i = 0; i < outdegree.size(); i++)
    {
	if (outdegree[i])
	{
	    getEulerCircuit(i, circuit);
	    return circuit;
	}
    }

    return circuit;
}
