struct RMQ 
{
	int n;
	vector<int> rangeMin;
	RMQ(const vector<int>& array) 
	{
		n = array.size();
		rangeMin.resize(n * 4);
		init(array, 0, n - 1, 1);
	}

	int init(const vector<int>& array, int left, int right, int node)
	{
		if (left == right)
			return rangeMin[node] = array[left];

		int mid = (left + right) / 2;
		int leftMin = init(array, left, mid, 2 * node);
		int rightMin = init(array, mid + 1, right, 2 * node + 1);
		return rangeMin[node] = min(leftMin, rightMin);
	}

	int query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		if (right < nodeLeft || nodeRight < left)
			return INT_MAX_VAL;

		if (left <= nodeLeft && nodeRight <= right)
			return rangeMin[node];

		int mid = (nodeLeft + nodeRight) / 2;
		return min(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}

	int query(int left, int right)
	{
		return query(left, right, 1, 0, n - 1);
	}
	//array[index] = newValue로 바뀌었을 때 node를 루트로 하는 
	//구간 트리를 갱신하고 노드가 표현하는 구간의 최소치를 반환한다.
	int update(int index, int newValue, int node, int nodeLeft, int nodeRight)
	{
		if (index < nodeLeft || nodeRight < index)
			return rangeMin[node];

		if (nodeLeft == nodeRight)
			return rangeMin[node] = newValue;

		int mid = (nodeLeft + nodeRight) / 2;
		return rangeMin[node] = min(update(index, newValue, 2 * node, nodeLeft, mid), update(index, newValue, 2 * node + 1, mid + 1, nodeRight));
	}

	int update(int index, int newValue)
	{
		return update(index, newValue, 1, 0, n - 1);
	}
};
