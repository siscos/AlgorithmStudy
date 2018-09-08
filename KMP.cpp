// N에서 자기 자신을 찾으면서 나타나는 부분 일치를 이용해
// pi[]를 계산한다.
// pi[i] = N[..i]의 접두사도 되고 접미사도 되는 문자열의 최대 길이
vector<int> getPartialMatch(const string& N)
{
    int m = N.size();
    vector<int> pi(m, 0);
    // KMP로 자기 자신을 찾는다.
    // begin = 0이면 자기 자신을 찾아버리니까 안됨!
    int begin = 1, matched = 0;
    // 비교할 문자가 N의 끝에 도달할 때까지 찾으면서 부분 일치를 모두 기록한다.
    while(begin + matched < m)
    {
	if (N[begin + matched] == N[matched])
	{
	    ++matched;
	    pi[begin + matched] = matched;
	}
	else
	{
	    if (matched == 0)
		begin++;
	    else
	    {
		begin += matched - pi[matched - 1];
		matched = pi[matched - 1];
	    }
	}
    }
    return pi;
}

vector<int> kmpSearch(const string& H, const string& N)
{
    int n = H.size(), m = N.size();
    vector<int> ret;

    vector<int> pi = getPartialMatch(N);
    int begin = 0, matched = 0;

    while(begin <= n - m)
    {
	if (match < m && H[begin + matched] == N[matched])
	{
	    ++matched;

	    if (matched == m)
		ret.push_back(begin);
	}
	else
	{
	    // 예외: matched가 0인 경우에는 다음 칸부터 계속
	    if (matched == 0)
		begin++;
	    else
	    {
		begin += matched - pi[matched - 1];
		// begin을 옮겼다고 처음부터 다시 비교할 필요는 없다.
		// 옮긴 후에도 pi[matched - 1]만큼은 항상 일치하기 때문이다.
		matched = pi[matched - 1];
	    }
	}
    }
    return ret;
}
