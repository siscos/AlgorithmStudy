// 모든 정점의 차수가 짝수이고 모든 간선이 하나의 컴포넌트에 포함되어 있을 경우
// 그래프의 인접 행렬 표현. adj[i][j]=i와 j사이의 간선 수
vector<vector<int>> adj;
// 무향 그래프의 인접 행렬 adj가 주어질 때 오일러 서킷을 계산한다.
// 결과로 얻어지는 circuit을 뒤집으면 오일러 서킷이 된다.
void getEulerCircuit(int here, vector<int>& circuit)
{
    for(int there = 0; there < adj[here].size(); there++)
    {
        while(adj[here][there] > 0)
        {
            adj[here][there]--;
            adj[there][here]--;
            getEulerCircuit(there, circuit);
        }
    }
    circuit.push_back(here);
}
