//Trie를 이용한 다중 문자열 검색 알고리즘

const int ALPHABETS = 26;
int toNumber(char ch) { return ch - 'A'; }

struct TrieNode
{
    TrieNode* children[ALPHABETS];
    // 현 위치에서 끝나는 문자열 번호
    int terminal;
    // 실패연결: 이 노드에서 매칭이 실패했을 때 이곳으로 가서 계속한다.
    // 이 노드에 대응되는 문자열의 접미사이면서 트라이에 포함된 최대 문자열
    TrieNode* fail;
    // 출력 문자열 목록: 이 노드가 방문되었을 때 등장하는 바늘 문자열 번호
    vector<int> output;

    TrieNode(): terminal(-1)
    {
	memset(children, 0, sizeof(children));
    }

    ~TrieNode()
    {
	for(int i = 0; i < ALPHABETS; i++)
	{
	    if (children[i])
		delete children[i];
	}
    }

    //이 노도를 루트로 하는 트라이에 문자열 key를 추가
    void insert(const char* key, int idx)
    {
	if (*key == 0)
	    terminal = idx;
	else
	{
	    int next = toNumber(*key);
	    if (children[next] == NULL)
		children[next] = new TrieNode();

	    children[next]->insert(key + 1);
	}
    }

    TrieNode* find(const char* key)
    {
	if (*key == 0)
	    return this;

	int next = toNumber(*key);

	if (children[next] == NULL)
	    return NULL;

	return children[next]->find(key + 1);
    }
}

// 트라이가 주어질 때 각 노드에 대해 실패 연결과 출력 문자열 목록을 계산한다
void computeFailFunc(TrieNode* root)
{
    // 루트에서부터 시작해 한 단계씩 아래로 내려가며 각 노드의 실패 연결을 계산한다.
    // BFS
    queue<TrieNode*> q;
    // 루트의 실패 연결은 자기 자신
    root->fail = root;
    q.push(root);

    while(!q.empty())
    {
	TrieNode* here = q.front();
	q.pop();
	// here의 모든 자손에 대해 실패 연결을 계산한고 이들을 큐에 넣는다.
	for(int edge = 0; edge < ALPHABETS; ++edge)
	{
	    TrieNode* child = here->children[edge];
	    if (!child)
		continue;

	    if (here == root)
		child->fail = root;
	    else
	    {
		// 아닌 경우 부모의 실패 연결을 따라가면서 실패 연결을 찾는다.
		TrieNode* t = here->fail;
		while(t != root && t->children[edge] == NULL)
		    t = t->fail;
		if (t->children[edge])
		    t = t->children[edge];
		child->fail = t;
	    }i
	    // 출력 문자열 목록: 실패 연결을 따라간 노드에서 복사해온 뒤, 
	    // 이 위치에서 끝나는 바늘 문자열이 있으면 추가한다.
	    child->output = child->fail->output;
	    if (child->termial != -1)
		child->output.push_back(child->terminal);

	    q.push(child);
	}
    }
}

// trie에 포함된 패턴들을 s에서 찾는다.
// s내에서 패턴일 출현할 때마다 (마지막 글자, 패턴 번호)의 쌍을 저장한다.
vector<pair<int, int>> ahoCorasick(const string& s, TrieNode* root)
{
    vector<pair<int, int>> ret;
    TrieNode* state = root;
    for(int i = 0; i < s.size(); i++)
    {
	int chr = toNumber(s[i]);
	while(state != root && state->children[chr] == NULL)
	    state = state->fail;

	if (state->children[chr])
	    state = state->children[chr];

	for(int j = 0; j < state->output.size(); ++j)
	    ret.push_back(make_pair(i, state->output[j]));
    }

    return ret;
}
