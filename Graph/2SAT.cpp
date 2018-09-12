// adj에 함의 그래프의 인접 리스트 표현이 주어질 때, 2SAT 문제의 답을 반환한다.
vector<int> solve2SAT()
{
    int n = adj.size() / 2; // 변수의 수
    // 함의 그래프의 정점들을 강결합 요소별로 묶는다. 
    vector<int> label = tarjanSCC();
    // 이 SAT 문제를 푸는 것이 불가능한지 확인한다. 한 변수를 나타내는 두 정점이
    // 같은 강결합 요소에 속해 있을 경우 답이 없다.
    for(int i = 0; i < 2 * n; i += 2)
    {
	if (lable[i] == label[i + 1])
	    return vector<int>();
    }

    // 2SAT 문제를 푸는 것이 가능하다. 답을 생성하자.
    vector<int> value(2 * n, -1);
    // Tarjan 알고리즘에서 SCC 번호는 위상정렬의 역순으로 배정된다.
    // SCC 번호의 역순으로 각 정점을 정렬하면 위상 정렬의 순서가 된다.
    vector<pair<int, int>> order;
    for(int i = 0; i < 2 * n; i++)
	order.push_back(-label[i], i);

    sort(order.begin(), order.end());

    for(int i = 0; i < 2 * n; i++)
    {
	int vertex = order[i].second;
	int variable = vertex / 2, isTrue = (vertex % 2 == 0);

	if (value[variable] != -1)
	    continue;

	// not A가 A보다 먼저 나왔으면 A는 참
	// A가 not A보다 먼저 나왔으면 A는 거짓
	value[variable] = !isTrue;
    }
    return value;
}
