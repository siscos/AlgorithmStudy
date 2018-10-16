#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <utility>
#include <stack>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)

bool IsPrime(int n)
{
    bool val = true;
    if (n <=0){
        return false;
    }
    if (n == 1) {
        return false;
    }
    else if (n<4){
        return true;
    }
    else if (n % 2 == 0) {
        return false;
    }
    else if (n<9){
        return true;
    }
    else if (n%3==0){
        return false;
    }
 
    for(long i=5;i*i<=n;i=i+6){
        if (n % i == 0){
            return false;
        }
        if (n%(i+2) == 0){
            return false;
        }
    }
    return val;
}

bool isPalindrome(int n)
{
	int rev = 0;
	int t = n;
	while(t != 0)
	{
		rev *= 10;
		rev += t % 10;
		t /= 10;
	}
	return n == rev;
}

ll Gcd(ll m, ll n){
	return n == 0 ? m : Gcd(n, m % n);
	//if (n>m)
	//{
	//	ll tmp = n;
	//	n = m;
	//	m = tmp;
	//}

	//ll gcd = 1;
	//while(true)
	//{
	//	if (m%n==0)
	//	{
	//		gcd = n;
	//		break;
	//	}
	//	else
	//	{
	//		ll tmp = m;
	//		m = n;
	//		n = tmp %n;
	//	}
	//}
	//return gcd;
}

ll Lcm(ll m, ll n)
{
	ll gcd = Gcd(m, n);
	return m*(n/gcd);
}

//소인수 분해
map<ll, ll> primeFactors(ll x)
{
    map<ll, ll> res;
    // Trial division. 
    for (ll p = 2; p*p <= x; p++) {
        if (x % p == 0) {
            ll r = 0;
            while (x % p == 0) {
                x /= p;
                r++;
            }
            res[p] = r;
        }
    }
    if (x != 1) {
        res[x] = 1;
    }
    return res;
}
// 최소공배수가 매우 클 때
//From 1 to n 모든 수들의 최소공배수
const int MOD = 1000000007;
map<ll, ll> LcmVeryLarge(ll m, ll n)
{
	map<ll, ll> lcm;
	map<ll, ll> p1 = primeFactors(m);
	for(map<ll, ll>::iterator it = p1.begin(); it != p1.end(); ++it)
	{
		if (lcm[it->first] < it->second)
			lcm[it->first] = it->second;
	}

	map<ll, ll> p2 = primeFactors(m);
	for(map<ll, ll>::iterator it = p2.begin(); it != p2.end(); ++it)
	{
		if (lcm[it->first] < it->second)
			lcm[it->first] = it->second;
	}
	return lcm;
}


#define GENNCR_MAX 	60
int ncr[GENNCR_MAX][GENNCR_MAX];
void genncr()
{
	FOR(i,0,GENNCR_MAX)
	{
		ncr[i][0]=1;
		ncr[i][i]=1;
	}
	FOR(i,1,GENNCR_MAX)
	{
		FOR(j,1,i)
		{
			ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
		}
	}
}

#define COMBINATION_MAX 40
//nCr = (n-1)C(r-1)+(n-1)Cr C0=1

template <typename T>
T C(T n, T k)//nCk
{
	T b[COMBINATION_MAX][COMBINATION_MAX];

	k = MIN(k, n-k);

	for(T i=0;i<=n;i++)
	{
		for(T j=0;j<=MIN(i,k);j++)
		{
			if (j==0||j==i)
				b[i][j]=1;
			else
				b[i][j] = b[i-1][j-1]+b[i-1][j];
		}
	}
	return b[n][k];
}

//nHr=nH(r-1)+(n-1)H(r-1)
//nHr=(n+r-1)Cr
template <typename T>
T H(T n, T k)
{
	return C(n+k-1,k);
}
//nPr=n*(n-1)P(r-1)
template <typename T>
T P(T n, T k)
{
	T r=1;
	for(T i=0; i<k; i++)
	{
		T*=(n-i);
	}
}

int num=0;
int a[10]={0,1,2,3,4,5,6,7,8,9};
int b[5];


void PrintArray(int q)
{
	printf("\n%04d : ",++num);
	while(q)
	{
		printf("%d", b[--q]);
	}
}

void C(int n, int r, int q)
{
	if (r==0) PrintArray(q);
	else if (n<r) return;
	else
	{
		b[r-1]=a[n-1];//사전역순ㄴ
//		b[r-1]=a[9-(n-1)]; //사전순서
		C(n-1,r-1,q);
		C(n-1,r,q);
	}
}

//행렬 연산
#define MATRIX_MAX 40
void AddMatrix(double pm1[][MATRIX_MAX], double pm2[][MATRIX_MAX], double result[][MATRIX_MAX], int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			result[i][j]=pm1[i][j]+pm2[i][j];
	}
}

void SubMatrix(double pm1[][MATRIX_MAX], double pm2[][MATRIX_MAX], double result[][MATRIX_MAX], int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			result[i][j]=pm1[i][j]-pm2[i][j];
	}
}

void MultMatrix(double pm1[][MATRIX_MAX], double pm2[][MATRIX_MAX], double result[][MATRIX_MAX], int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			result[i][j]=0;
			for(int k=0;k<n;k++)
				result[i][j]+=pm1[i][k]*pm2[k][j];
		}
	}
}

//정방행렬 곱셈
vector<vector<double> > MultiMatrix(const vector<vector<double> > &a, const vector<vector<double> > &b)
{
	int n = a.size();
	vector<vector<double> > result(n, vector<double>(n, 0));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			result[i][j]=0;
			for(int k=0;k<n;k++)
			{
				result[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

//행렬 A^m을 리턴한다
vector<vector<double> > pow(const vector<vector<double> >& a, int m)
{
	if (m == 1)
		return a;
	if (m % 2 == 1)
		return MultiMatrix(pow(a, m - 1), a);

	vector<vector<double> > half = pow(a, m / 2);
	return MultiMatrix(half, half);
}
//int x1, int y1 : 첫번째 사각형의 left-bottom
//int x2, int y2 : 첫번째 사각형의 right-top 
//int x3, int y3 : 두번째 사각형의 left-bottom
//int x4, int y4 : 두번째 사각형의 right-top 
void RectOverlap(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	string s;
	if (max(x1, x3)>min(x2, x4)||max(y1, y3)>min(y2, y4))
		s="none";
	else if (max(x1, x3)==min(x2, x4)&&max(y1, y3)==min(y2, y4))
		s="point";
	else if (max(x1, x3)==min(x2, x4)||max(y1, y3)==min(y2, y4))
		s="line";
	else 
		s="rectangle";
}

string DecimalToNBase(int num, int s)
{
   	int d=s;
   	int n=num;
   	string strN;
   	char c[]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 
   			'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    	
   	while(true){
   		if (n==0) break;
   		strN += c[n%d];
   		n/=d;
   	}
	reverse(strN.begin(), strN.end());
   	return strN;
}

int NBaseToDecimal(string s, int n)
{
    int p=1;
    for(int i=0;i<s.length()-1;i++){
    	p*=n;
    }
    int val=0;
    for(int i=0;i<s.length();i++){
    	val+=((s[i]-0x30)*p);
    	p/=n;
    }
    return val;
}
//약수 개수
template <typename T>
T getFactorNumber(T n)
{
	T cnt =0;
	T i;
	for(i = 1; i * i <n;i++){
		if (n%i == 0){
			cnt++;
		}
	}
	if (i*i == n){
		return 2*cnt + 1;
	}
	else{
		return 2*cnt;
	}
}

template <typename T>
T ReverseNum(T n)
{
	T cnt=1;
	T d=10;
	while(true){
		if (n/d==0) break;
		d*=10;
		cnt++;
	}
	T ret=0;
	d/=10;
	T d1=10;
	T tmp=n;
	for(int i=0;i<cnt;i++){
		ret+=d*(tmp%d1);
		d/=10;
		tmp=tmp/10;
	}
	return ret;
}

bool IsLeapYear(int n)
{
	if ((n%4==0 && n%100 !=0) || (n%400 == 0)){
        return true;
    }
    else{
        return false;
    }
}
//분수 곱셈 1/2 * 3/4 (a[0] = 1, a[1] = 2, b[0] = 3, b[1] = 4)
int* multiplyFractions(int* a, int* b)
{
   int c[2]={a[0]*b[0], a[1]*b[1]};
   return c;
}
//분수 덧셈
int* addFractions(int* a, int* b)
{
   ll denom = Lcm(a[1],b[1]);
   int c[2] = {denom/a[1]*a[0] + denom/b[1]*b[0], denom};
   return c;
}
//분수 약분
void reduceFraction(int* a)
{
   ll b = Gcd(a[0],a[1]);
   a[0]/=b;
   a[1]/=b;
}
//복소수 곱하기
int* multiplyComplex(int* m, int* n)
{
   int prod[2] = {m[0]*n[0] - m[1]*n[1], m[0]*n[1] + m[1]*n[0]};
   return prod;
}
#define MAX_N	10000000
bool isPrime[MAX_N+1];
void eratosthenes(int n)
{
	memset(isPrime,1,sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	int sqrtn = int(sqrt((double)n));
    for(int i = 2; i <= sqrtn; i++)
	{
		if (isPrime[i])
		{
			for(int j = i*i; j<=n; j+=i)
				isPrime[j] = false;
		}
	}
}

//minFactor[i] : i의 가장 작은 소인수(i가 소수인 경우 자기 자신)
int minFactor[MAX_N];
void eratosthenes2(int n)
{
	minFactor[0] = minFactor[1] = -1;
	for(int i = 2;i <= n; i++)
		minFactor[i] = i;
	int sqrtn = (int)sqrt((double)n);
	for(int i = 2; i <= sqrtn; i++)
	{
		if (minFactor[i] == i)
		{
			for(int j = i*i; j <= n; j+=i)
			{
				if (minFactor[j] == j)
					minFactor[j] = i;
			}
		}
	}
}
#include <vector>
//2이상의 자연수 n을 소인수 분해한 결과를 반환한다.
std::vector<int> factor(int n)
{
	std::vector<int> ret;
	while(n>1)
	{
		ret.push_back(minFactor[n]);
		n /= minFactor[n];
	}
	return ret;
}
//참고 : http://bbolmin.tistory.com/45

struct ExtEuclidRet
{
    int r;
    int s;
    int t;
};

ExtEuclidRet Extended_Euclid(int r1, int r2)
{
    if (r1 < r2)
        std::swap(r1,r2);

	int r, q, s, s1=1, s2=0, t, t1=0, t2=1, tmp = r1;

	while(r2)
	{
		q = r1/r2;
		r = r1%r2;
		s = s1 - q*s2;
		t = t1 - q*t2;

//   printf("%4d %4d %4d %4d %4d %4d %4d %4d %4d %4d\n", q, r1, r2, r, s1, s2, s, t1, t2, t);

		r1 = r2;
		r2 = r;
		s1 = s2; 
		s2 = s;
		t1 = t2;
		t2 = t;
	}
	printf("%4d %4d %4d      %4d %4d      %4d          \n\n", q, r1, r2, s1, s2, t1);
	printf("s : %d , t : %d \n", s1, t1);

    ExtEuclidRet ret;

    ret.r = r1; // 최대공약수(gcd)
    ret.s = s1; // 큰수에 곱하는 값
    ret.t = t1; // 작은 수에 곱하는 값

    if(r1 == 1) //역원이 있음
    {
        if(t1 < 0)
            ret.t += tmp;
        return ret;
    }


    return ret;
} 

typedef unsigned long long uint64;

int get(uint64 mask, int index)
{
    return (mask >> (index << 2)) & 15;
}

int set(uint64 mask, int index, uint64 value)
{
    return mask & ~(15LL << (index << 2)) | (value <<(index << 2));
}
std::string p("abcdefghi");
int c=0;

void str_permutation(int x, int l)
{
	if (x==l) {
		printf("%d : %s\n", c++, p.substr(0,l).c_str());
    } else {
        for (int i = x; i < 9; i++) {
            // swap p[x] and p[i]
            char o = p[x];
            p[x] = p[i];
            p[i] = o;
             
            str_permutation(x+1,l);
             
            // restore them to continue the search:
            p[i] = p[x];
            p[x] = o;
        }
    }
}

void str_permutation(int x)
{
	if (x==p.size()) {
		printf("%d : %s\n", c++, p.c_str());
    } else {
        for (int i = x; i < 9; i++) {
            // swap p[x] and p[i]
            char o = p[x];
            p[x] = p[i];
            p[i] = o;
             
            str_permutation(x+1);
             
            // restore them to continue the search:
            p[i] = p[x];
            p[x] = o;
        }
    }
}

//sub가 st의 subsequence인지 리턴
bool isSubsequence(string sub, string st)
{
	int i = 0, j = 0;
	while(i < sub.length() && j < st.length())
	{
		char p1 = sub[i];
		char p2 = st[j];
		if (sub[i] == st[j])
		{
			i++;
			j++;
		}
		else
			j++;
	}
	if (i == sub.length())
		return true;
	else
		return false;
}
//ax^2 + bx + c = 0의 근을 크기 순서대로 반환
const double EPSILON = 1e-9;
const double INFTY = 1e200;
vector<double> solve2(double a, double b, double c)
{
    double d = b*b - 4*a*c;
    //실근이 없는 경우
    if (d < -EPSILON) 
        return vector<double>();
    //중근
    if (d < EPSILON)
        return vector<double>(1, -b / (2*a));
    vector<double> ret;
    ret.push_back((-b - sqrt(d)) / (2*a));
    ret.push_back((-b + sqrt(d)) / (2*a));
    return ret;


}
//N에서 자기 자신을 찾으면서 나타나는 부분 일치를 이용해 pi[]를 계산한다
//pi[i]=N[..i]의 접두사도 되고 접미사도 되는 문자열의 최대 길이
vector<int> getPartialMatch(const string& n)
{
    int m = n.size();
    vector<int> pi(m, 0);
    //kmp로 자신을 찾는다.
    //n에서 n을 찾는다. begin=0이면 자기 자신을 찾으니까 안됨!!
    int begin = 1, matched = 0;
    while(begin + matched < m)
    {
        if (n[begin + matched] == n[matched])
        {
            matched++;
            pi[begin + matched - 1] = matched;
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
//'짚더미'H의 부분 문자열로 '바늘'N이 출현하는 시작 위치들을 모두 반환한다
vector<int> kmpSearch(const string& H, const string& N){
    int n = H.size(), m = N.size();
    vector<int> ret;
    //pi[i]=N[..i]의 접두사도 되고 접미사도 되는 문자열의 최대 길이
    vector<int> pi = getPartialMatch(N);
    // begin = match = 0에서부터 시작한다
    int begin = 0, matched = 0;
    while(begin <= n - m)
    {
        //만약 짚더미의 해당 글자가 바늘의 해당 글자와 같다면
        if (matched < m && H[begin + matched] == N[matched])
        {
            matched++;
            if (matched == m)
                ret.push_back(begin);
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
    return ret;
}
//각 접미사들의 첫t글자를 기준으로 한 그룹 번호가 주어질 때,
//주어진 두 접미사를 첫 2*t글자를 기준으로 비교한다.
//group[]은 길이가 0인 접미사도 포함한다.
struct Comparator
{
    vector<int> group;
    int t;
    Comparator(const vector<int>& _group, int _t)
    {
        group = _group;
        t = _t;
    }
    bool operator () (int a, int b)
    {
        //첫 t글자가 다르면 이들을 이용해 비교한다.
        if (group[a] != group[b]) 
            return group[a] < group[b];
        return group[a+t] < group[b+t];
    }
};
//s의 접미사 배열을 계산한다.
vector<int> getSuffixArray(const string& s)
{
    int n = s.size();
    //group[i] = 접미사들을 첫 t글자 기준으로 정렬했을 때 s[i..]가 들어가는 그룹번호
    //t=1일 때는 정렬할 것 없이 s[i..]의 첫 글자로 그룹번호를 정해줘도 같은 효과가 있다.
    int t = 1;
    vector<int> group(n + 1);
    FOR(i,0,n)
        group[i] = s[i];
    group[n] = -1;
    //결과적으로는 접미사 배열이 반환될 값. 이 배열을 log(n)번 정렬한다.
    vector<int> perm(n);
    FOR(i,0,n)
        perm[n] = i;
    while(t < n)
    {
        //group[]은 첫 t글자를 기준으로 계산해뒀다.
        //첫 2t글자를 기준으로 perm을 다시 정렬한다.
        Comparator compareUsing2T(group, t);
        sort(perm.begin(), perm.end(), compareUsing2T);
        //2t글자가 넘는다면 이제 접미사 배열 완성!
        t *= 2;
        if(t >= n)
            break;
        //2t글자를 기준으로 한 그룹 정보를 만든다.
        vector<int> newGroup(n+1);
        newGroup[n] = -1;
        newGroup[perm[0]] = 0;
        FOR(i, 1, n)
        {
            if (compareUsing2T(perm[i - 1], perm[i]))
                newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
            else
                newGroup[perm[i]] = newGroup[perm[i - 1]];
        }
        group = newGroup;
    }
    return perm;
}

vector<int> heap;

void push_heap(vector<int>& heap, int newValue)
{
    //heap의 맨 끝에 newValue를 삽입
    heap.push_back(newValue);
    //현재 newValue의 위치
    int idx = heap.size() - 1;
    while(idx > 0 && heap[(idx - 1) / 2] < heap[idx])
    {
        swap(heap[idx], heap[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}
//정수를 담는 최대 힙에서 heap[0]을 제거한다
void pop_heap(vector<int>& heap)
{
    heap[0] = heap.back();
    heap.pop_back();
    int here = 0;
    while(true)
    {
        int left = 2 * here + 1, right = 2 * here + 2;
        //leaf에 도달한 경우
        if (left >= heap.size())
            break;
        int next = here;
        if (heap[next] < heap[left])
            next = left;
        if (right < heap.size() && heap[next] < heap[right])
            next = right;
        if (next == here)
            break;
        swap(heap[here], heap[next]);
        here = next;
    }
}


//팬윅 트리의 구현. 가상의 배열 A[]의 부분합을 빠르게 계산할 수 있도록 한다.
//초기화시에는 A[]의 원소가 전부 0이라고 생각한다.
struct FenwickTree
{
    vector<int> tree;
    FenwickTree(int n):tree(n + 1) {}
    //A[0..pos]의 부분합을 구한다.
    int sum(int pos)
    {
        ++pos;
        int ret = 0;
        while(pos > 0)
        {
            ret += tree[pos];
            //다음 구간을 찾기 위해 최종 비트를 지운다.
            pos &= (pos - 1);
        }
        return ret;
    }
    //A[pos]에 val을 더한다.
    void add(int pos, int val)
    {
        ++pos;
        while(pos < tree.size())
        {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }
};
//트리를 이용해 상호 배제적 집합을 구현한다
struct OptimizedDisjointSet
{
    vector<int> parent, rank;
    OptimizedDisjointSet(int n) : parent(n), rank(n, 1)
    {
        FOR(i, 0, n)
            parent[i] = i;
    }
    //u가 속한 트리의 루트의 번호를 반환한다
    int find(int u)
    {
        if (u == parent[u])
            return u;
        return parent[u] = find(parent[u]);
    }
    //u가 속한 트리와 v가 속한 트리를 합친다
    void merge(int u, int v)
    {
        u = find(u);
        v = find(v);
        //u와 v가 이미 같은 집합에 속하는 경우는 걸러낸다
        if (u == v)
            return;
        if (rank[u] > rank[v])
            swap(u, v);
        //이제 rank[v]가 항상 rank[u] 이상이므로 u를 v의 자식으로 넣는다.
        parent[u] = v;
        if(rank[u] == rank[v])
            rank[v]++;
    }
};

//트라이의 노드를 표헌하는 객체의 선언
//알파벳 대문자를 저장하는 경우 각 노드는 26개의 자손을 가질 수 있다.
const int ALPHABETS = 26;
int toNumber(char ch) {return ch-'A';}
//트라이의 한 노드를 나타내는 객체
struct TrieNode
{
	TrieNode* children[ALPHABETS];
	//현 위치에서 끝나느 문자열의 번호
	int terminal;
	TrieNode() : terminal(-1)
	{
		memset(children, 0, sizeof(children));
	}
	~TrieNode()
	{
		FOR(i, 0, ALPHABETS)
		{
			if (children[i])
				delete children[i];
		}
	}
	//이 노드를 루트로 하는 트라이에 번호 id인 문자열 key를 추가한다.
	void insert(const char* key, int id)
	{
		if (*key == 0)
			terminal = id;
		else
		{
			int next = toNumber(*key);
			//해당 자식 노드가 없다면 생성한다.
			if (children[next] == NULL)
				children[next] = new TrieNode();
			//해당 자직 노드로 재귀 호출
			children[next]->insert(key + 1, id);
		}
	}
	//이 노드를 루트로 하는 트라이에 문자열 key에 대응되는 노드를 찾는다.
	//없으면 NULL을 반환한다.
	TrieNode* find(const char* key)
	{
		if (*key == 0)
			return this;
		int next = toNumber(*key);
		if (children[next] == NULL)
			return NULL;
		return children[next]->find(key + 1);
	}

	//아호-코라식 알고리즘을 위해 트라이의 각 노드에 추자적으로 계산해야할 정보
	//실패 연결 : 이 노드에서 매칭이 실패했을 때 이곳으로 가서 계속한다.
	//이 노드에 대응되는 문자열의 접미사이면서 트라이에 포함된 최대 문자열
	TrieNode* fail;
	//출력 문자열 목록 : 이 노드가 방문되었을 때 등장하는 바늘 문자열들의 번호
	vector<int> output;
};
//아호-코라식 알고리즘에서 실패 함수의 계산
//트라이가 주어질 때 각 노드에 대해 실패 연결과 출력 문자열 목록을 계산한다.
void computeFailFunc(TrieNode* root)
{
	//루트에서 시작해 한 단계씩 아래로 내려가면 각 노드의 실패 연결을 계산한다.
	queue<TrieNode*> q;
	//루트의 실패 연결은 자기 자신
	root->fail = root;
	q.push(root);
	while(!q.empty())
	{
		TrieNode* here = q.front();
		q.pop();
		//here의 모든 자손에 대해 실패 연결을 계산하고 이들을 큐에 넣는다.
		FOR(edge, 0, ALPHABETS)
		{
			TrieNode* child = here->children[edge];
			if (!child)
				continue;
			//1레벨 노드의 실패 연결은 항상 루트
			if (here == root)
				child->fail = root;
			else
			{
				//아닌 경우 부모의 실패 연결을 따라가면서 실패 연결을 찾는다
				TrieNode* t = here->fail;
				while(t != root && t->children[edge] == NULL)
					t = t->fail;
				if (t->children[edge])
					t = t->children[edge];
				child->fail = t;
			}
			//이 위치에서 끝나는 바늘 문자열이 있으면 추가한다.
			child->output = child->fail->output;
			if (child->terminal != -1)
				child->output.push_back(child->terminal);
			q.push(child);
		}
	}
}
//아호-코라식 알고리즘의 실제 탐색 과정
//trie에 포함된 패턴들을 s에서 찾는다.
//s내에서 패턴이 출현할 때마다 (마지막 글자 위치, 패턴 번호)의 쌍을 저장한다.
vector<pair<int, int> > ahoCorasick(const string& s, TrieNode* root)
{
	vector<pair<int, int> > ret;
	TrieNode* state = root;
	FOR(i,0, s.size())
	{
		int chr = toNumber(s[i]);
		while(state != root && state->children[chr] == NULL)
			state = state->fail;
		if (state->children[chr])
			state = state->children[chr];
		FOR(j, 0 ,state->output.size())
			ret.push_back(make_pair(i,state->output[j]));
	}
	return ret;
}

//그래프의 인접 리스트 표현
vector<vector<int> > adj;
//각 정점을 방문했는지 여부
vector<bool> visited;
//깊이 우선 탐색을 구현한다
void dfs(int here)
{
    cout<<"DFS visits " << here << endl;
    visited[here] = true;
    FOR(i,0,adj[here].size())
    {
        int there = adj[here][i];
        if (!visited[there])
            dfs(there);
    }
}
//간선을 구분하는 깊이 우선 탐색의 구현
//discovered[i] = i번째 정점의 발견 순서
//finished[i] = dfs(i)가 종료되었으면 1, 아니면 0
vector<int> discovered, finished;
//지금까지 발견한 정점의 수
int counter = 0;
void dfs2(int here)
{
    discovered[here] = counter++;
    //모든 인접 접점을 순회하면서
    for(int i = 0; i < adj[here].size(); i++)
    {
        int there = adj[here][i];
        cout << "(" << here << ", " << there << ") is a";
        //아직 방문한 적 없다면 방문한다.
        if (discovered[there] == -1)
        {
            cout << "tree edge" << endl;
            dfs(there);
        }
        //만약 there가 here보다 늦게 발견되었다면 there은 here의 후손이다.(순방향 간선)
        else if(discovered[here] < discovered[there])
            cout << "forward edge" << endl;
        //만약 dfs2(there)이 종료되지 않았다면 there은 here의 선조다(역방향 간선)
        else if (finished[there] == 0)
            cout << "back edge" << endl;
        //이 외의 경우는 모두 교차 간선
        else
            cout << "cross edge" << endl;
    }
    finished[here] = 1;
}
//모든 정점을 방문한다.
void dfsAll()
{
    //visited를 모두 false로 초기화한다.
    visited = vector<bool>(adj.size(), false);
    //모든 정점을 순회하면서 아직 방문한 적이 없으면 방문한다
    FOR(i,0,adj.size())
    {
        if (!visited[i])
            dfs(i);
    }
}

void dfsStack(int start)
{
    stack<int> st;
    visited[start] = true;
    st.push(start);
    while(!st.empty())
    {
        int here = st.top();
        printf("dfs here = %d\n", here);
        visited[here] = true;
        st.pop();
        FOR(i, 0, 26)
        {
            if (!visited[i] && adj[here][i] == 1)
                st.push(i);
        }
    }
}


//깊이 우선 탐색을 이용한 오일러 서킷 찾기
//vector<vector<int> > adj;
//무향 그래프의 인접 행렬(adj)가 주어질 때 오일러 서킷을 계산한다
//결과로 얻어지는 circuit을 뒤집으면 오일러 서킷이 된다
void getEulerCircuit(int here, vector<int>& circuit)
{
    for(int there = 0; there < adj[here].size(); there++)
    {
        while(adj[here][there] > 0)
        {
            adj[here][there]--;//양쪽 간선을 모두 지운다
            adj[there][here]--;
            getEulerCircuit(there, circuit);
        }
    }
    circuit.push_back(here);
}
// 무향 그래프에서 절단점을 찾는 알고리즘
// 각 정점의 발견 순서. -1로 초기화한다.
//vector<int> discovered;
//각 정점이 절단점인지 여부를 저장한다. false로 초기화한다.
vector<bool> isCutVertex;
//int counter = 0;
//here를 루트로 하는 서브트리에 있는 절단점들을 찾는다.
//반환값은 해당 서브트리에서 역방향 간선으로 갈 수 있는 정점 중
//가장 일찍 발견된 정점의 발견 시점. 처음 호출할 때는 isRoot = true로 둔다.
int findCutVertex(int here, bool isRoot)
{
    //발견순서를 기록한다.
    discovered[here] = counter++;
    int ret = discovered[here];
    //루트인 경우의 절단점 판정을 위해 자손 서브트리의 개수를 센다.
    int children = 0;
    for(int i = 0; i< adj[here].size(); ++i)
    {
        int there = adj[here][i];
        if(discovered[there] == -1)
        {
            ++children;
            //이 서브트리에서 갈 수 있는 가장 높은 정점의 번호
            int subtree = findCutVertex(there, false);
            //이 노드가 자기 자신 이하에 있다면 현재 위치는 절단점
            if (!isRoot && subtree >= discovered[here])
                isCutVertex[here] = true;
            ret = min(ret, subtree);
        }
        else
            ret = min(ret, discovered[there]);
    }
    //루트인 경우 절단점 판정은 서브트리의 개수로 한다.
    if (isRoot)
        isCutVertex[here] = (children >= 2);
    return ret;
}
//타잔의 강결합 컴포넌트 분리 알고리즘의 구현
//각 정점의 컴포넌트 번호. 컴포넌트 번호는 0부터 시작하며, 같은 강결합 컴포넌트에 속한 정점들의 컴포넌트 번호가 같다.
vector<int> sccId;

//각 정점의 발견 순서와 scc() 종료 여부
//vector<int> discovered, finished;

//정점의 번호를 담은 스택
stack<int> st;

int sccCounter, vertexCounter;
//here을 루트로 하는 서브트리에서 역방향 간선으로 닿을 수 있는 최소의 발견순서를 반환한다.
int scc(int here)
{
    int ret = discovered[here] = vertexCounter++;
    //스택에 here을 넣는다. here의 후손들은 모두 스택에서 here후에 들어간다.
    st.push(here);
    for(int i = 0; i < adj[here].size(); i++)
    {
        int there = adj[here][i];
        //(here, there)이 트리 간선
        if (discovered[there] == -1)
            ret = min(ret, scc(there));
        //(here, there)이 역방향이나 교차 간선
        else if (discovered[there] < discovered[here] && sccId[there] == -1)
            ret = min(ret, discovered[there]);
    }
    //here가 강결합 컴포넌트의 루트인가 확인한다.
    if (ret == discovered[here])
    {
        //here를 루트로 하는 서브트리에 남아 있는 정점들을 전부 하나의 컴포넌트로 묶는다.
        while(true)
        {
            int t = st.top();
            st.pop();
            sccId[t] = sccCounter;
            if (t == here)
                break;
        }
        ++sccCounter;
    }
    finished[here] = 1;
    return ret;
}

//tarjan의 SCC 알고리즘
vector<int> tarjanSCC()
{
    //배열들을 전부 초기화
    sccId = discovered = vector<int>(adj.size(), -1);
    finished = vector<int>(adj.size(), 0);
    //카운터 초기화
    sccCounter = vertexCounter = 0;
    //모든 정점에 대하여 scc() 호출
    for(int i = 0; i < adj.size(); i++)
    {
        if (discovered[i] == -1)
            scc(i);
    }
    return sccId;
}

const int ALPHABETS = 26;
int toNumber(char ch) {return ch-'A';}

struct TrieNode
{
    TrieNode* children[ALPHABETS];
    ////현 위치에서 끝나는 문자열의 번호
    int terminal;
    TrieNode() : terminal(-1)
    {
        memset(children, 0, sizeof(children));
    }
    ~TrieNode()
    {
        FOR(i,0,ALPHABETS)
        {
            if (children[i])
                delete children[i];
        }
    }
    //이 노드를 루트로 하는 트라이에 문자열 key를 추가한다.
    void insert(const char* key){
        //문자열이 끝나면 terminal만 참으로 바꾸고 종료
        if (*key == 0)
            terminal = true;
        else
        {
            int next = toNumber(*key);
            //해당 자식 노드가 없다면 생성한다
            if (children[next] == NULL)
                children[next] = new TrieNode();
            //해당 자식 노드로 재귀 호출
            children[next]->insert(key + 1);
        }
    }
    TrieNode* find(const char* key)
    {
        if (*key == 0)
            return this;
        int next = toNumber(*key);
        if(children[next] == NULL)
            return NULL;
        return children[next]->find(key + 1);
    }

    ///////////////////////////////////////////////////////////////////////////
    //야호-코라식 알고리즘을 위해 트라이의 각 노드에 추가적으로 계산해야할 정보
    //실패 연결 : 이 노드에서 매칭이 실패했을 때 이곳으로 가서 조사한다.
    //이 노드에 대응되는 문자열의 접미사이면 트라이에 포함된 최대 문자열
    TrieNode *fail;
    //출력 문자열 목록 : 이 노드가 방문되었을 때 등장하는 바늘 문자열의 번호
    vector<int> output;

};

//트라이가 주어질 때 각 노드에 대해 실패 연결과 출력 문자열 목록을 계산한다
void computeFailFunc(TrieNode* root)
{
    //루트에서부터 시작해 한 단계씩 아래로 내려가며 각 노드의 실패 연결을 계산한다.
    queue<TrieNode*> q;
    //루트의 실패 연결은 자기 자신
    root->fail = root;
    q.push(root);
    while(!q.empty())
    {
        TrieNode* here = q.front();
        q.pop();
        //here의 모든 자손에 대해 실패 연결을 계산하고 이들을 큐에 넣는다.
        FOR(edge,0,ALPHABETS)
        {
            TrieNode* child = here->children[edge];
            if (!child)
                continue;
            //1레벨 노드의 실패 연결은 항상 루트
            if (here == root)
                child->fail = root;
            else
            {
                //아닌 경우 부모의 실패 연결을 따라가면서 실패 연결을 찾는다.
                TrieNode* t = here->fail;
                while(t != root && t->children[edge] == NULL)
                    t = t->fail;
                if (t->children[edge])
                    t = t->children[edge];
                child->fail = t;
            }
            //출력 문자열 목록 : 실패 연결을 따라간 노드에서 복사해온 뒤,
            //이 위치에서 끝나는 바늘 문자열이 있으면 추가한다.
            child->output = child->fail->output;
            if (child->terminal != -1)
                child->output.push_back(child->terminal);
            q.push(child);
        }
    }
}
//start에서 시작해 그래프를 너비 우선 탐색하고 각 정점의 방문 순서를 반환한다.
vector<int> bfs(int start)
{
    //각 정점의 방문 여부
    vector<bool> discovered(adj.size(), false);
    //방문할 정점 목록을 유지하는 큐
    queue<int> q;
    //정점의 방문 순서
    vector<int> order;
    discovered[start] = true;
    q.push(start);
    while(!q.empty())
    {
        int here = q.front();
        q.pop();
        //here을 방문한다
        order.push_back(here);
        for(int i = 0; i<adj[here].size(); i++)
        {
            int there = adj[here][i];
            //처음 보는 정점이면 방문 목록에 집어넣는다
            if(!discovered[there])
            {
                q.push(there);
                discovered[there] = true;
            }
        }
    }
    return order;
}

struct node
{
    int key;
    node* left, *right;
    node(int k):key(k), left(NULL), right(NULL) {}
};

void preorderTraverse(node* t)
{
    printf("%d\n", t->key);
    if (t->left)
        preorderTraverse(t->left);
    if (t->right)
    preorderTraverse(t->right);
}

void preorderTraverseStack(node* t)
{
    stack<node*> st;
    st.push(t);
    while(!st.empty())
    {
        node* tmp = st.top();
        st.pop();
        printf("%d\n", tmp->key);
        if (tmp->right)
            st.push(tmp->right);
        if(tmp->left)
            st.push(tmp->left);
    }
}

void inorderTraverse(node* t)
{
    if (t->left)
        inorderTraverse(t->left);
    printf("%d\n", t->key);
    if (t->right)
        inorderTraverse(t->right);
}

void inorderTraverseStack(node* t)
{
    int done = 0;
    stack<node*> st;
    while(!done)
    {
        while( t != NULL)
        {
            st.push(t);
            t = t->left;
        }
        if (!st.empty())
        {
            t = st.top();
            st.pop();
            printf("%d\n", t->key);
            t = t->right;
        }
        else
            done = 1;
    }
}

void postorderTraverse(node* t)
{
    if (t->left)
        postorderTraverse (t->left);
    if (t->right)
        postorderTraverse (t->right);
    printf("%d\n", t->key);
}

void postorderTraverseStack(node* t)
{
    int done = 0;
    node* s;
    stack<node*> st;
    while(!done)
    {
        while(t != NULL)
        {
            st.push(t);
            t = t->left;
        }
        while(!st.empty())
        {
            s = t;
            t = st.top();
            st.pop();
            if (t->right != NULL)
            {
                if (t->right == s)
                    printf("%d\n", t->key);
                else
                {
                    st.push(t);
                    t = t->right;
                    break;
                }
            }
            else
                printf("%d\n", t->key);
        }
        if (st.empty())
            done = 1;
    }
}
//다익스트라
//정점의 개수
const int MAX_V = 100;
int V;
//그래프의 인접 리스트. (연결된 정점 번호, 간선 가중치) 쌍을 담는다.
vector<pair<int, int> > adjD[MAX_V];
vector<int> dijkstra(int src)
{
    vector<int> dist(V, numeric_limits<int>::max());
    dist[src] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, src));
    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        //만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸 것은 무의미하다.
        if (dist[here] < cost)
            continue;
        //인접한 정점들을 모두 검사한다.
        FOR(i, 0, adjD[here].size())
        {
            int there = adjD[here][i].first;
            int nextDist = cost + adjD[here][i].second;
            //더 짧은 경로가 발견되면, dist[]를 갱신하고 우선순위 큐에 넣는다.
            if (dist[there] > nextDist)
            {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    return dist;
}
//우선순위 큐를 사용하지 않은 다익스트라 알고리즘
vector<int> dijkstra2(int src)
{
    vector<int> dist(V, numeric_limits<int>::max());
    //각 정점을 방문했는지 여부를 저장한다
    vector<bool> visited(V,false);
    dist[src] = 0;
    visited[src] = true;
    while(true)
    {
        //아직 방문하지 않은 정점 중 가장 가까운 정점을 찾는다.
        int closest = INT_MAX, here;
        FOR(i,0,V)
        {
            if (dist[i] < closest && !visited[i])
            {
                here = i;
                closest = dist[i];
            }
        }
        if (closest == INT_MAX)
            break;
        //가장 가까운 정점을 방문한다.
        visited[here] = true;
        FOR(i,0,adjD[here].size())
        {
            int there = adjD[here][i].first;
            if (visited[there])
                continue;
            int nextDist = dist[here] + adjD[here][i].second;
            dist[there] = min(dist[there], nextDist);
        }
    }
    return dist;
}
//벨만-포드 알고리즘의 구현
//정점의 개수
//int V;
//그래프의 인접 리스트(연결된 정점 번호, 간선 가중치) 쌍을 담는다.
//vector<pair<int, int> > adjD[MAX_V];
//음수 사이클이 있을 경우 텅빈 배열을 반한
vector<int> bellmanFord(int src)
{
    //시작점을 제외한 모든 정점까지의 최단 거리 상한을 둔다.
    vector<int> upper(V, numeric_limits<int>::max() - 1000000000);
    upper[src] = 0;
    bool updated;
    //V번 순회한다.
    FOR(iter, 0, V)
    {
        updated = false;
        FOR(here, 0, V)
        {
            FOR(i, 0, adj[here].size())
            {
                int there = adjD[here][i].first;
                int cost = adjD[here][i].second;
                //(here, there) 간선을 따라 완화를 시도한다.
                if (upper[there] > upper[here] + cost)
                {
                    //성공
                    upper[there] = upper[here] + cost;
                    updated = true;
                }
            }
        }
        //모든 간선에 대해 완화가 실패했을 경우 V-1번도 돌 필요없이 곧장 종료한다.
        if (!updated)
            break;
    }
    //V번째 완화가 성공했다면 음수 사이클이 있다. 
    if (updated)
        upper.clear();
    return upper;
}

//플로이드 알고리즘 구현
//정점의 개수
//int V;
//그래프의 인접 행렬 표현
//adj[u][v] = u에서 v로 가는 간선의 가중치. 간선이 없으면 아주 큰 값을 넣는다.
//int adj[MAX_V][MAX_V];
//플로이드의 모든 쌍 최단 거리 알고리즘
void floyd()
{
    FOR(i,0,V)
        adj[i][i] = 0;
    FOR(k, 0, V)
        FOR(i, 0, V)
            FOR(j, 0, V)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}
//플로이드 알고리즘의 실제 최단 경로 계산하기
//via[u][v] = u에서 v까지 가는 최단 경로가 경유하는 점 중 가장 번호가 큰 정점
//-1로 초기화해 둔다.
int via[MAX_V][MAX_V];
//플로이드의 모든 쌍 최단 거리 알고리즘
void floyd2()
{
    FOR(i,0,V)
        adj[i][i] = 0;
    memset(via, -1, sizeof(via));
    FOR(k, 0, V)
        FOR(i, 0, V)
            FOR(j, 0, V)
                if (adj[i][j] > adj[i][k] + adj[k][j])
                {
                    via[i][j] = k;
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
}
//u에서 v로 가는 최단 경로를 계산해 path에 저장한다.
void reconstruct(int u, int v, vector<int>& path)
{
    //기저사례
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
        path.pop_back();//w가 중복으로 들어가므로 지운다.
        reconstruct(w, v, path);
    }
}

//크루스칼의 최소 스패닝 느리 알고리즘
//트리를 이용해 상호 배제적 집합을 구현한다.
//const int MAX_V = 100;
//정점의 개수
//int V;
//그래프의 인접 리스트(연결된 정점번호, 간선 가중치) 쌍을 담는다
//vector<pair<int, int> > adj[MAX_V];

//주어진 그래프에 대한 최소 스패닝 트리에 포함된 간선의 목록을 selected에 
//저장하고 가중치의 합을 반환한다.
int kruskal(vector<pair<int, int> >& selected)
{
	int ret = 0;
	selected.clear();
	//(가중치, (정점1, 정점2))의 목록을 얻는다
	vector<pair<int, pair<int, int> > > edges;
	FOR(u, 0, V)
	{
		FOR(i, 0, adjD[u].size())
		{
			int v = adjD[u][i].first, cost = adjD[u][i].second;
			edges.push_back(make_pair(cost, make_pair(u, v)));
		}
	}
	//가중치 순으로 정렬
	sort(edges.begin(), edges.end());
	//처음에는 모든 정점이 분리되어 있다.
	OptimizedDisjointSet sets(V);
	FOR(i, 0, edges.size())
	{
		//간선(u, v)를 검사한다.
		int cost = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;
		//이미 u와 v가 연결되어 있을 경우 무시한다.
		if (sets.find(u) == sets.find(v))
			continue;
		//이 둘을 합친다.
		sets.merge(u, v);
		selected.push_back(make_pair(u, v));
		ret += cost;
	}
	return ret;
}

//프림 알고리즘의 구현
const int INF = 987654321;
//정점의 개수
//int V;
//그래프의 인접리스트. (연결된 정점 번호, 간선 가중치) 쌍을 담는다.
//vector<pair<int, int> > adjD[MAX_V];
//주어진 그래프에 대해 최소 스패닝 트리에 포함된 간선 목록을 selected에 저장하고, 가중치의 합을 반환한다.
int prim(vector<pair<int, int> >& selected)
{
    selected.clear();
    //해당 정점이 트리에 포함되어 있나?
    vector<bool> added(V, false);
    //트리에 인접한 간선 중 해당 정점에 닿는 최소 간선의 정보를 저장한다.
    vector<int> minWeight(V, INF), parent(V, -1);
    //가중치의 합을 저장할 변수
    int ret = 0;
    //0번 정점을 시작점으로: 항상 트리에 가장 먼저 추가한다.
    minWeight[0] = parent[0] = 0;
    FOR(iter, 0, V)
    {
        //다음에 트리에 추가할 정점 u를 찾는다.
        int u = -1;
        FOR(v, 0, V)
            if (!added[v] && (u == -1 || minWeight[u] > minWeight[v]))
                u = v;
        //(parent[u], u)를 트리에 추가한다.
        if (parent[u] != u)
            selected.push_back(make_pair(parent[u], u));
        ret += minWeight[u];
        added[u] = true;
        //u에 인접한 간선 (u,v)들을 검사한다.
        FOR(i, 0, adj[u].size())
        {
            int v = adjD[u][i].first, weight = adjD[u][i].second;
            if (!added[v] && minWeight[v] > weight)
            {
                parent[v] = u;
                minWeight[v] = weight;
            }
        }
    }
    return ret;
}

//네트워크 유량 문제를 해결하는 포드-폴커슨 알고리즘의 구현
//int V;
//capacity[u][v] = u에서 v로 보낼 수 있는 용량
//flow[u][v] = u에서 v로 흘러가는 유량(반대 방향인 경우 음수)
int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];
//flow[][]를 계산하고 총 유량을 반환한다.
int networkFlow(int source, int sink)
{
    //flow를 0으로 초기화한다.
    memset(flow, 0 ,sizeof(flow));
    int totalFlow = 0;
    while(true)
    {
        //너비 우선 탐색으로 증가 경로를 찾는다
        vector<int> parent(MAX_V, -1);
        queue<int> q;
        parent[source] = source;
        q.push(source);
        while (!q.empty() && parent[sink] == -1)
        {
            int here = q.front(); q.pop();
            FOR(there, 0, V)
            {
                if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1)
                {
                    q.push(there);
                    parent[there] = here;
                }
            }
        }
        //증가 경로가 없으면 종료한다
        if (parent[sink] == -1)
            break;
        //증가 결로를 통해 유량을 얼마나 보낼지 결정한다.
        int amount = INF;
        for(int p = sink; p != source; p = parent[p])
            amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
        //증가 경로를 통해 유량을 보낸다
        for(int p = sink; p != source; p = parent[p])
        {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        totalFlow += amount;
    }
    return totalFlow;
}

//이분 매칭 문제를 해결하는 증가 경로 알고리즘
//A와 B의 정점의 개수
int n, m;
//adj[i][j] = Ai와 Bi가 연결되어 있는가?
//bool adj[MAX_N][MAX_N];
//각 정점에 매칭된 상대 정점의 번호를 저장한다.
vector<int> aMatch, bMatch;
//dfs() 방문 여부
vector<bool> visited;
//A의 정점인 a에서 B의 매칭되지 않은 정점으로 가는 경로를 찾는다.
bool dfs(int a)
{
    if (visited[a])
        return false;
    visited[a] = true;
    FOR(b,0,m)
    {
        if (adj[a][b])
        {
            //b가 매칭되어 있지 않다면 bMatch[b]에서부터 시작해 증가 경로를 찾는다
            if(bMatch[b] == -1 || dfs(bMatch[b]))
            {
                //증가 경로 발견!! a와 b를 매치시킨다
                aMatch[a] = b;
                bMatch[b] = a;
                return true;
            }
        }
    }
    return false;
}
//aMatch, bMatch 배열을 계산하고 최대 매칭의 크기를 반환한다
int bipartiteMatch()
{
    //처음에는 어떤 정점도 연결되어 있지 않다.
    aMatch = vector<int>(n, -1);
    bMatch = vector<int>(m, -1);
    int size = 0;
    FOR(start, 0, n)
    {
        visited = vector<bool>(n, false);
        //깊이 우선 탐색을 이용해 start에서 시작한 증가 경로를 찾는다.
        if (dfs(start))
            size++;
    }
    return size;
}
//이분 그래프의 최대 독립 집합 계산하기
//각 정점에 매칭된 상대 정점의 번호를 저장한다. 매칭되지 않을 경우 -1
//vector<int> aMatch, bMatch;
//aChosen[i] = 최대 독립 집합에 A_i가 포함되었는가?
//bChosen[i] = 최대 독립 집합에 B_i가 포함되었는가?
vector<bool> aChosen, bChosen;
//이분 그래프의 정보가 주어질 때 실제 최대 독립 집합을 계산한다.
void calcMaxIndependentSet()
{
    //aMatch[]와 bMatch[]를 계산한다
    int C = bipartiteMatch();
    //1. A의 모든 정점들을 선택하고, B에서 대응되지 않은 정점들을 선택한다.
    aChosen = vector<bool>(n, true);
    bChosen = vector<bool>(m, false);
    FOR(i,0,m)
    {
        if (bMatch[i] == -1)
            bChosen[i] = true;
    }
    //2. 두 정점이 연결되어 있을 경우, 그중 A의 정점을 지우고 B의 대응된 정점을 대신 선택한다.
    //더 이상 변화가 일어나지 않을 때까지 반복한다.
    while(true)
    {
        bool changed = false;
        FOR(i, 0, n)
        {
            FOR(j, 0, m)
            {
                if(aChosen[i] && bChosen[j] && adj[i][j])
                {
                    //A에 항상 매칭에 포함된 정점임을 증명할 수 있다.
                    //assert(aMatch[i] != -1)
                    aChosen[i] = false;
                    bChosen[aMatch[i]] = true;
                    changed = true;
                }
            }
        }
        if (!changed) 
            break;
    }
}

//nlog(n) algorithm
vector<int> LIS(vector<int>& x)
{
	int n = x.size();
	vector<int> p(n, 0);
	vector<int> m(n+1, 0);
	int L = 0;

	for(int i = 0; i < n; i++)
	{
		int lo = 1;
		int hi = L;
		while(lo <= hi)
		{
			int mid = ceil((lo + hi) / 2.0);
			if (x[m[mid]] < x[i])
				lo = mid + 1;
			else
				hi = mid - 1;
		}
		int newL = lo;
		p[i] = m[newL - 1];
		m[newL] = i;
		L = max(L, newL);
	}

	vector<int> s(L, 0);
	int k = m[L];
	for(int i = L-1; i >=0 ;i--)
	{
		s[i] = x[k];
		k = p[k];
	}
	return s;
}

//nlog(n) algorithm
vector<int> LIS(vector<int>& x)
{
	int n = x.size();
	vector<int> p(n, 0);
	vector<int> m(n+1, 0);
	int L = 0;

	for(int i = 0; i < n; i++)
	{
		int lo = 1;
		int hi = L;
		while(lo <= hi)
		{
			int mid = ceil((lo + hi) / 2.0);
			if (x[m[mid]] < x[i])
				lo = mid + 1;
			else
				hi = mid - 1;
		}
		int newL = lo;
		p[i] = m[newL - 1];
		m[newL] = i;
		L = max(L, newL);
	}

	vector<int> s(L, 0);
	int k = m[L];
	for(int i = L-1; i >=0 ;i--)
	{
		s[i] = x[k];
		k = p[k];
	}
	return s;
}
const int MOD=1000000007;
int fastPow(int a, int k)
{
    int ret = 1;
    while(k > 0)
    {
        if (k & 1)
            ret = 1LL * ret * a % MOD;
        a = 1LL * a * a %MOD;
        k >>= 1;
    }
    return ret;
}
//a와 k가 서로 소일 때 a의 모듈라 역원
int getModInv(int a, int k)
{
    return fastPow(a, k - 2);
}

int main()
{
//	C(10,5,5);
    eratosthenes(MAX_N);
    FOR(i,0,n)
    {
        if (isPrime[MAX_N-1-i])
        {
            printf("%d", MAX_N-1-i);
        }
    }
    vector<int> v =factor(63);
    return 0;
}
