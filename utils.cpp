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

//���μ� ����
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
// �ּҰ������ �ſ� Ŭ ��
//From 1 to n ��� ������ �ּҰ����
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
		b[r-1]=a[n-1];//����������
//		b[r-1]=a[9-(n-1)]; //��������
		C(n-1,r-1,q);
		C(n-1,r,q);
	}
}

//��� ����
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

//������� ����
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

//��� A^m�� �����Ѵ�
vector<vector<double> > pow(const vector<vector<double> >& a, int m)
{
	if (m == 1)
		return a;
	if (m % 2 == 1)
		return MultiMatrix(pow(a, m - 1), a);

	vector<vector<double> > half = pow(a, m / 2);
	return MultiMatrix(half, half);
}
//int x1, int y1 : ù��° �簢���� left-bottom
//int x2, int y2 : ù��° �簢���� right-top 
//int x3, int y3 : �ι�° �簢���� left-bottom
//int x4, int y4 : �ι�° �簢���� right-top 
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
//��� ����
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
//�м� ���� 1/2 * 3/4 (a[0] = 1, a[1] = 2, b[0] = 3, b[1] = 4)
int* multiplyFractions(int* a, int* b)
{
   int c[2]={a[0]*b[0], a[1]*b[1]};
   return c;
}
//�м� ����
int* addFractions(int* a, int* b)
{
   ll denom = Lcm(a[1],b[1]);
   int c[2] = {denom/a[1]*a[0] + denom/b[1]*b[0], denom};
   return c;
}
//�м� ���
void reduceFraction(int* a)
{
   ll b = Gcd(a[0],a[1]);
   a[0]/=b;
   a[1]/=b;
}
//���Ҽ� ���ϱ�
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

//minFactor[i] : i�� ���� ���� ���μ�(i�� �Ҽ��� ��� �ڱ� �ڽ�)
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
//2�̻��� �ڿ��� n�� ���μ� ������ ����� ��ȯ�Ѵ�.
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
//���� : http://bbolmin.tistory.com/45

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

    ret.r = r1; // �ִ�����(gcd)
    ret.s = s1; // ū���� ���ϴ� ��
    ret.t = t1; // ���� ���� ���ϴ� ��

    if(r1 == 1) //������ ����
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

//sub�� st�� subsequence���� ����
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
//ax^2 + bx + c = 0�� ���� ũ�� ������� ��ȯ
const double EPSILON = 1e-9;
const double INFTY = 1e200;
vector<double> solve2(double a, double b, double c)
{
    double d = b*b - 4*a*c;
    //�Ǳ��� ���� ���
    if (d < -EPSILON) 
        return vector<double>();
    //�߱�
    if (d < EPSILON)
        return vector<double>(1, -b / (2*a));
    vector<double> ret;
    ret.push_back((-b - sqrt(d)) / (2*a));
    ret.push_back((-b + sqrt(d)) / (2*a));
    return ret;


}
//N���� �ڱ� �ڽ��� ã���鼭 ��Ÿ���� �κ� ��ġ�� �̿��� pi[]�� ����Ѵ�
//pi[i]=N[..i]�� ���λ絵 �ǰ� ���̻絵 �Ǵ� ���ڿ��� �ִ� ����
vector<int> getPartialMatch(const string& n)
{
    int m = n.size();
    vector<int> pi(m, 0);
    //kmp�� �ڽ��� ã�´�.
    //n���� n�� ã�´�. begin=0�̸� �ڱ� �ڽ��� ã���ϱ� �ȵ�!!
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
//'¤����'H�� �κ� ���ڿ��� '�ٴ�'N�� �����ϴ� ���� ��ġ���� ��� ��ȯ�Ѵ�
vector<int> kmpSearch(const string& H, const string& N){
    int n = H.size(), m = N.size();
    vector<int> ret;
    //pi[i]=N[..i]�� ���λ絵 �ǰ� ���̻絵 �Ǵ� ���ڿ��� �ִ� ����
    vector<int> pi = getPartialMatch(N);
    // begin = match = 0�������� �����Ѵ�
    int begin = 0, matched = 0;
    while(begin <= n - m)
    {
        //���� ¤������ �ش� ���ڰ� �ٴ��� �ش� ���ڿ� ���ٸ�
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
//�� ���̻���� ùt���ڸ� �������� �� �׷� ��ȣ�� �־��� ��,
//�־��� �� ���̻縦 ù 2*t���ڸ� �������� ���Ѵ�.
//group[]�� ���̰� 0�� ���̻絵 �����Ѵ�.
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
        //ù t���ڰ� �ٸ��� �̵��� �̿��� ���Ѵ�.
        if (group[a] != group[b]) 
            return group[a] < group[b];
        return group[a+t] < group[b+t];
    }
};
//s�� ���̻� �迭�� ����Ѵ�.
vector<int> getSuffixArray(const string& s)
{
    int n = s.size();
    //group[i] = ���̻���� ù t���� �������� �������� �� s[i..]�� ���� �׷��ȣ
    //t=1�� ���� ������ �� ���� s[i..]�� ù ���ڷ� �׷��ȣ�� �����൵ ���� ȿ���� �ִ�.
    int t = 1;
    vector<int> group(n + 1);
    FOR(i,0,n)
        group[i] = s[i];
    group[n] = -1;
    //��������δ� ���̻� �迭�� ��ȯ�� ��. �� �迭�� log(n)�� �����Ѵ�.
    vector<int> perm(n);
    FOR(i,0,n)
        perm[n] = i;
    while(t < n)
    {
        //group[]�� ù t���ڸ� �������� ����ص״�.
        //ù 2t���ڸ� �������� perm�� �ٽ� �����Ѵ�.
        Comparator compareUsing2T(group, t);
        sort(perm.begin(), perm.end(), compareUsing2T);
        //2t���ڰ� �Ѵ´ٸ� ���� ���̻� �迭 �ϼ�!
        t *= 2;
        if(t >= n)
            break;
        //2t���ڸ� �������� �� �׷� ������ �����.
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
    //heap�� �� ���� newValue�� ����
    heap.push_back(newValue);
    //���� newValue�� ��ġ
    int idx = heap.size() - 1;
    while(idx > 0 && heap[(idx - 1) / 2] < heap[idx])
    {
        swap(heap[idx], heap[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}
//������ ��� �ִ� ������ heap[0]�� �����Ѵ�
void pop_heap(vector<int>& heap)
{
    heap[0] = heap.back();
    heap.pop_back();
    int here = 0;
    while(true)
    {
        int left = 2 * here + 1, right = 2 * here + 2;
        //leaf�� ������ ���
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


//���� Ʈ���� ����. ������ �迭 A[]�� �κ����� ������ ����� �� �ֵ��� �Ѵ�.
//�ʱ�ȭ�ÿ��� A[]�� ���Ұ� ���� 0�̶�� �����Ѵ�.
struct FenwickTree
{
    vector<int> tree;
    FenwickTree(int n):tree(n + 1) {}
    //A[0..pos]�� �κ����� ���Ѵ�.
    int sum(int pos)
    {
        ++pos;
        int ret = 0;
        while(pos > 0)
        {
            ret += tree[pos];
            //���� ������ ã�� ���� ���� ��Ʈ�� �����.
            pos &= (pos - 1);
        }
        return ret;
    }
    //A[pos]�� val�� ���Ѵ�.
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
//Ʈ���� �̿��� ��ȣ ������ ������ �����Ѵ�
struct OptimizedDisjointSet
{
    vector<int> parent, rank;
    OptimizedDisjointSet(int n) : parent(n), rank(n, 1)
    {
        FOR(i, 0, n)
            parent[i] = i;
    }
    //u�� ���� Ʈ���� ��Ʈ�� ��ȣ�� ��ȯ�Ѵ�
    int find(int u)
    {
        if (u == parent[u])
            return u;
        return parent[u] = find(parent[u]);
    }
    //u�� ���� Ʈ���� v�� ���� Ʈ���� ��ģ��
    void merge(int u, int v)
    {
        u = find(u);
        v = find(v);
        //u�� v�� �̹� ���� ���տ� ���ϴ� ���� �ɷ�����
        if (u == v)
            return;
        if (rank[u] > rank[v])
            swap(u, v);
        //���� rank[v]�� �׻� rank[u] �̻��̹Ƿ� u�� v�� �ڽ����� �ִ´�.
        parent[u] = v;
        if(rank[u] == rank[v])
            rank[v]++;
    }
};

//Ʈ������ ��带 ǥ���ϴ� ��ü�� ����
//���ĺ� �빮�ڸ� �����ϴ� ��� �� ���� 26���� �ڼ��� ���� �� �ִ�.
const int ALPHABETS = 26;
int toNumber(char ch) {return ch-'A';}
//Ʈ������ �� ��带 ��Ÿ���� ��ü
struct TrieNode
{
	TrieNode* children[ALPHABETS];
	//�� ��ġ���� ������ ���ڿ��� ��ȣ
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
	//�� ��带 ��Ʈ�� �ϴ� Ʈ���̿� ��ȣ id�� ���ڿ� key�� �߰��Ѵ�.
	void insert(const char* key, int id)
	{
		if (*key == 0)
			terminal = id;
		else
		{
			int next = toNumber(*key);
			//�ش� �ڽ� ��尡 ���ٸ� �����Ѵ�.
			if (children[next] == NULL)
				children[next] = new TrieNode();
			//�ش� ���� ���� ��� ȣ��
			children[next]->insert(key + 1, id);
		}
	}
	//�� ��带 ��Ʈ�� �ϴ� Ʈ���̿� ���ڿ� key�� �����Ǵ� ��带 ã�´�.
	//������ NULL�� ��ȯ�Ѵ�.
	TrieNode* find(const char* key)
	{
		if (*key == 0)
			return this;
		int next = toNumber(*key);
		if (children[next] == NULL)
			return NULL;
		return children[next]->find(key + 1);
	}

	//��ȣ-�ڶ�� �˰����� ���� Ʈ������ �� ��忡 ���������� ����ؾ��� ����
	//���� ���� : �� ��忡�� ��Ī�� �������� �� �̰����� ���� ����Ѵ�.
	//�� ��忡 �����Ǵ� ���ڿ��� ���̻��̸鼭 Ʈ���̿� ���Ե� �ִ� ���ڿ�
	TrieNode* fail;
	//��� ���ڿ� ��� : �� ��尡 �湮�Ǿ��� �� �����ϴ� �ٴ� ���ڿ����� ��ȣ
	vector<int> output;
};
//��ȣ-�ڶ�� �˰��򿡼� ���� �Լ��� ���
//Ʈ���̰� �־��� �� �� ��忡 ���� ���� ����� ��� ���ڿ� ����� ����Ѵ�.
void computeFailFunc(TrieNode* root)
{
	//��Ʈ���� ������ �� �ܰ辿 �Ʒ��� �������� �� ����� ���� ������ ����Ѵ�.
	queue<TrieNode*> q;
	//��Ʈ�� ���� ������ �ڱ� �ڽ�
	root->fail = root;
	q.push(root);
	while(!q.empty())
	{
		TrieNode* here = q.front();
		q.pop();
		//here�� ��� �ڼտ� ���� ���� ������ ����ϰ� �̵��� ť�� �ִ´�.
		FOR(edge, 0, ALPHABETS)
		{
			TrieNode* child = here->children[edge];
			if (!child)
				continue;
			//1���� ����� ���� ������ �׻� ��Ʈ
			if (here == root)
				child->fail = root;
			else
			{
				//�ƴ� ��� �θ��� ���� ������ ���󰡸鼭 ���� ������ ã�´�
				TrieNode* t = here->fail;
				while(t != root && t->children[edge] == NULL)
					t = t->fail;
				if (t->children[edge])
					t = t->children[edge];
				child->fail = t;
			}
			//�� ��ġ���� ������ �ٴ� ���ڿ��� ������ �߰��Ѵ�.
			child->output = child->fail->output;
			if (child->terminal != -1)
				child->output.push_back(child->terminal);
			q.push(child);
		}
	}
}
//��ȣ-�ڶ�� �˰����� ���� Ž�� ����
//trie�� ���Ե� ���ϵ��� s���� ã�´�.
//s������ ������ ������ ������ (������ ���� ��ġ, ���� ��ȣ)�� ���� �����Ѵ�.
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

//�׷����� ���� ����Ʈ ǥ��
vector<vector<int> > adj;
//�� ������ �湮�ߴ��� ����
vector<bool> visited;
//���� �켱 Ž���� �����Ѵ�
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
//������ �����ϴ� ���� �켱 Ž���� ����
//discovered[i] = i��° ������ �߰� ����
//finished[i] = dfs(i)�� ����Ǿ����� 1, �ƴϸ� 0
vector<int> discovered, finished;
//���ݱ��� �߰��� ������ ��
int counter = 0;
void dfs2(int here)
{
    discovered[here] = counter++;
    //��� ���� ������ ��ȸ�ϸ鼭
    for(int i = 0; i < adj[here].size(); i++)
    {
        int there = adj[here][i];
        cout << "(" << here << ", " << there << ") is a";
        //���� �湮�� �� ���ٸ� �湮�Ѵ�.
        if (discovered[there] == -1)
        {
            cout << "tree edge" << endl;
            dfs(there);
        }
        //���� there�� here���� �ʰ� �߰ߵǾ��ٸ� there�� here�� �ļ��̴�.(������ ����)
        else if(discovered[here] < discovered[there])
            cout << "forward edge" << endl;
        //���� dfs2(there)�� ������� �ʾҴٸ� there�� here�� ������(������ ����)
        else if (finished[there] == 0)
            cout << "back edge" << endl;
        //�� ���� ���� ��� ���� ����
        else
            cout << "cross edge" << endl;
    }
    finished[here] = 1;
}
//��� ������ �湮�Ѵ�.
void dfsAll()
{
    //visited�� ��� false�� �ʱ�ȭ�Ѵ�.
    visited = vector<bool>(adj.size(), false);
    //��� ������ ��ȸ�ϸ鼭 ���� �湮�� ���� ������ �湮�Ѵ�
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


//���� �켱 Ž���� �̿��� ���Ϸ� ��Ŷ ã��
//vector<vector<int> > adj;
//���� �׷����� ���� ���(adj)�� �־��� �� ���Ϸ� ��Ŷ�� ����Ѵ�
//����� ������� circuit�� �������� ���Ϸ� ��Ŷ�� �ȴ�
void getEulerCircuit(int here, vector<int>& circuit)
{
    for(int there = 0; there < adj[here].size(); there++)
    {
        while(adj[here][there] > 0)
        {
            adj[here][there]--;//���� ������ ��� �����
            adj[there][here]--;
            getEulerCircuit(there, circuit);
        }
    }
    circuit.push_back(here);
}
// ���� �׷������� �������� ã�� �˰���
// �� ������ �߰� ����. -1�� �ʱ�ȭ�Ѵ�.
//vector<int> discovered;
//�� ������ ���������� ���θ� �����Ѵ�. false�� �ʱ�ȭ�Ѵ�.
vector<bool> isCutVertex;
//int counter = 0;
//here�� ��Ʈ�� �ϴ� ����Ʈ���� �ִ� ���������� ã�´�.
//��ȯ���� �ش� ����Ʈ������ ������ �������� �� �� �ִ� ���� ��
//���� ���� �߰ߵ� ������ �߰� ����. ó�� ȣ���� ���� isRoot = true�� �д�.
int findCutVertex(int here, bool isRoot)
{
    //�߰߼����� ����Ѵ�.
    discovered[here] = counter++;
    int ret = discovered[here];
    //��Ʈ�� ����� ������ ������ ���� �ڼ� ����Ʈ���� ������ ����.
    int children = 0;
    for(int i = 0; i< adj[here].size(); ++i)
    {
        int there = adj[here][i];
        if(discovered[there] == -1)
        {
            ++children;
            //�� ����Ʈ������ �� �� �ִ� ���� ���� ������ ��ȣ
            int subtree = findCutVertex(there, false);
            //�� ��尡 �ڱ� �ڽ� ���Ͽ� �ִٸ� ���� ��ġ�� ������
            if (!isRoot && subtree >= discovered[here])
                isCutVertex[here] = true;
            ret = min(ret, subtree);
        }
        else
            ret = min(ret, discovered[there]);
    }
    //��Ʈ�� ��� ������ ������ ����Ʈ���� ������ �Ѵ�.
    if (isRoot)
        isCutVertex[here] = (children >= 2);
    return ret;
}
//Ÿ���� ������ ������Ʈ �и� �˰����� ����
//�� ������ ������Ʈ ��ȣ. ������Ʈ ��ȣ�� 0���� �����ϸ�, ���� ������ ������Ʈ�� ���� �������� ������Ʈ ��ȣ�� ����.
vector<int> sccId;

//�� ������ �߰� ������ scc() ���� ����
//vector<int> discovered, finished;

//������ ��ȣ�� ���� ����
stack<int> st;

int sccCounter, vertexCounter;
//here�� ��Ʈ�� �ϴ� ����Ʈ������ ������ �������� ���� �� �ִ� �ּ��� �߰߼����� ��ȯ�Ѵ�.
int scc(int here)
{
    int ret = discovered[here] = vertexCounter++;
    //���ÿ� here�� �ִ´�. here�� �ļյ��� ��� ���ÿ��� here�Ŀ� ����.
    st.push(here);
    for(int i = 0; i < adj[here].size(); i++)
    {
        int there = adj[here][i];
        //(here, there)�� Ʈ�� ����
        if (discovered[there] == -1)
            ret = min(ret, scc(there));
        //(here, there)�� �������̳� ���� ����
        else if (discovered[there] < discovered[here] && sccId[there] == -1)
            ret = min(ret, discovered[there]);
    }
    //here�� ������ ������Ʈ�� ��Ʈ�ΰ� Ȯ���Ѵ�.
    if (ret == discovered[here])
    {
        //here�� ��Ʈ�� �ϴ� ����Ʈ���� ���� �ִ� �������� ���� �ϳ��� ������Ʈ�� ���´�.
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

//tarjan�� SCC �˰���
vector<int> tarjanSCC()
{
    //�迭���� ���� �ʱ�ȭ
    sccId = discovered = vector<int>(adj.size(), -1);
    finished = vector<int>(adj.size(), 0);
    //ī���� �ʱ�ȭ
    sccCounter = vertexCounter = 0;
    //��� ������ ���Ͽ� scc() ȣ��
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
    ////�� ��ġ���� ������ ���ڿ��� ��ȣ
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
    //�� ��带 ��Ʈ�� �ϴ� Ʈ���̿� ���ڿ� key�� �߰��Ѵ�.
    void insert(const char* key){
        //���ڿ��� ������ terminal�� ������ �ٲٰ� ����
        if (*key == 0)
            terminal = true;
        else
        {
            int next = toNumber(*key);
            //�ش� �ڽ� ��尡 ���ٸ� �����Ѵ�
            if (children[next] == NULL)
                children[next] = new TrieNode();
            //�ش� �ڽ� ���� ��� ȣ��
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
    //��ȣ-�ڶ�� �˰����� ���� Ʈ������ �� ��忡 �߰������� ����ؾ��� ����
    //���� ���� : �� ��忡�� ��Ī�� �������� �� �̰����� ���� �����Ѵ�.
    //�� ��忡 �����Ǵ� ���ڿ��� ���̻��̸� Ʈ���̿� ���Ե� �ִ� ���ڿ�
    TrieNode *fail;
    //��� ���ڿ� ��� : �� ��尡 �湮�Ǿ��� �� �����ϴ� �ٴ� ���ڿ��� ��ȣ
    vector<int> output;

};

//Ʈ���̰� �־��� �� �� ��忡 ���� ���� ����� ��� ���ڿ� ����� ����Ѵ�
void computeFailFunc(TrieNode* root)
{
    //��Ʈ�������� ������ �� �ܰ辿 �Ʒ��� �������� �� ����� ���� ������ ����Ѵ�.
    queue<TrieNode*> q;
    //��Ʈ�� ���� ������ �ڱ� �ڽ�
    root->fail = root;
    q.push(root);
    while(!q.empty())
    {
        TrieNode* here = q.front();
        q.pop();
        //here�� ��� �ڼտ� ���� ���� ������ ����ϰ� �̵��� ť�� �ִ´�.
        FOR(edge,0,ALPHABETS)
        {
            TrieNode* child = here->children[edge];
            if (!child)
                continue;
            //1���� ����� ���� ������ �׻� ��Ʈ
            if (here == root)
                child->fail = root;
            else
            {
                //�ƴ� ��� �θ��� ���� ������ ���󰡸鼭 ���� ������ ã�´�.
                TrieNode* t = here->fail;
                while(t != root && t->children[edge] == NULL)
                    t = t->fail;
                if (t->children[edge])
                    t = t->children[edge];
                child->fail = t;
            }
            //��� ���ڿ� ��� : ���� ������ ���� ��忡�� �����ؿ� ��,
            //�� ��ġ���� ������ �ٴ� ���ڿ��� ������ �߰��Ѵ�.
            child->output = child->fail->output;
            if (child->terminal != -1)
                child->output.push_back(child->terminal);
            q.push(child);
        }
    }
}
//start���� ������ �׷����� �ʺ� �켱 Ž���ϰ� �� ������ �湮 ������ ��ȯ�Ѵ�.
vector<int> bfs(int start)
{
    //�� ������ �湮 ����
    vector<bool> discovered(adj.size(), false);
    //�湮�� ���� ����� �����ϴ� ť
    queue<int> q;
    //������ �湮 ����
    vector<int> order;
    discovered[start] = true;
    q.push(start);
    while(!q.empty())
    {
        int here = q.front();
        q.pop();
        //here�� �湮�Ѵ�
        order.push_back(here);
        for(int i = 0; i<adj[here].size(); i++)
        {
            int there = adj[here][i];
            //ó�� ���� �����̸� �湮 ��Ͽ� ����ִ´�
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
//���ͽ�Ʈ��
//������ ����
const int MAX_V = 100;
int V;
//�׷����� ���� ����Ʈ. (����� ���� ��ȣ, ���� ����ġ) ���� ��´�.
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
        //���� ���� ���� �ͺ��� �� ª�� ��θ� �˰� �ִٸ� ���� ���� ���� ���ǹ��ϴ�.
        if (dist[here] < cost)
            continue;
        //������ �������� ��� �˻��Ѵ�.
        FOR(i, 0, adjD[here].size())
        {
            int there = adjD[here][i].first;
            int nextDist = cost + adjD[here][i].second;
            //�� ª�� ��ΰ� �߰ߵǸ�, dist[]�� �����ϰ� �켱���� ť�� �ִ´�.
            if (dist[there] > nextDist)
            {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    return dist;
}
//�켱���� ť�� ������� ���� ���ͽ�Ʈ�� �˰���
vector<int> dijkstra2(int src)
{
    vector<int> dist(V, numeric_limits<int>::max());
    //�� ������ �湮�ߴ��� ���θ� �����Ѵ�
    vector<bool> visited(V,false);
    dist[src] = 0;
    visited[src] = true;
    while(true)
    {
        //���� �湮���� ���� ���� �� ���� ����� ������ ã�´�.
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
        //���� ����� ������ �湮�Ѵ�.
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
//����-���� �˰����� ����
//������ ����
//int V;
//�׷����� ���� ����Ʈ(����� ���� ��ȣ, ���� ����ġ) ���� ��´�.
//vector<pair<int, int> > adjD[MAX_V];
//���� ����Ŭ�� ���� ��� �ֺ� �迭�� ����
vector<int> bellmanFord(int src)
{
    //�������� ������ ��� ���������� �ִ� �Ÿ� ������ �д�.
    vector<int> upper(V, numeric_limits<int>::max() - 1000000000);
    upper[src] = 0;
    bool updated;
    //V�� ��ȸ�Ѵ�.
    FOR(iter, 0, V)
    {
        updated = false;
        FOR(here, 0, V)
        {
            FOR(i, 0, adj[here].size())
            {
                int there = adjD[here][i].first;
                int cost = adjD[here][i].second;
                //(here, there) ������ ���� ��ȭ�� �õ��Ѵ�.
                if (upper[there] > upper[here] + cost)
                {
                    //����
                    upper[there] = upper[here] + cost;
                    updated = true;
                }
            }
        }
        //��� ������ ���� ��ȭ�� �������� ��� V-1���� �� �ʿ���� ���� �����Ѵ�.
        if (!updated)
            break;
    }
    //V��° ��ȭ�� �����ߴٸ� ���� ����Ŭ�� �ִ�. 
    if (updated)
        upper.clear();
    return upper;
}

//�÷��̵� �˰��� ����
//������ ����
//int V;
//�׷����� ���� ��� ǥ��
//adj[u][v] = u���� v�� ���� ������ ����ġ. ������ ������ ���� ū ���� �ִ´�.
//int adj[MAX_V][MAX_V];
//�÷��̵��� ��� �� �ִ� �Ÿ� �˰���
void floyd()
{
    FOR(i,0,V)
        adj[i][i] = 0;
    FOR(k, 0, V)
        FOR(i, 0, V)
            FOR(j, 0, V)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}
//�÷��̵� �˰����� ���� �ִ� ��� ����ϱ�
//via[u][v] = u���� v���� ���� �ִ� ��ΰ� �����ϴ� �� �� ���� ��ȣ�� ū ����
//-1�� �ʱ�ȭ�� �д�.
int via[MAX_V][MAX_V];
//�÷��̵��� ��� �� �ִ� �Ÿ� �˰���
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
//u���� v�� ���� �ִ� ��θ� ����� path�� �����Ѵ�.
void reconstruct(int u, int v, vector<int>& path)
{
    //�������
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
        path.pop_back();//w�� �ߺ����� ���Ƿ� �����.
        reconstruct(w, v, path);
    }
}

//ũ�罺Į�� �ּ� ���д� ���� �˰���
//Ʈ���� �̿��� ��ȣ ������ ������ �����Ѵ�.
//const int MAX_V = 100;
//������ ����
//int V;
//�׷����� ���� ����Ʈ(����� ������ȣ, ���� ����ġ) ���� ��´�
//vector<pair<int, int> > adj[MAX_V];

//�־��� �׷����� ���� �ּ� ���д� Ʈ���� ���Ե� ������ ����� selected�� 
//�����ϰ� ����ġ�� ���� ��ȯ�Ѵ�.
int kruskal(vector<pair<int, int> >& selected)
{
	int ret = 0;
	selected.clear();
	//(����ġ, (����1, ����2))�� ����� ��´�
	vector<pair<int, pair<int, int> > > edges;
	FOR(u, 0, V)
	{
		FOR(i, 0, adjD[u].size())
		{
			int v = adjD[u][i].first, cost = adjD[u][i].second;
			edges.push_back(make_pair(cost, make_pair(u, v)));
		}
	}
	//����ġ ������ ����
	sort(edges.begin(), edges.end());
	//ó������ ��� ������ �и��Ǿ� �ִ�.
	OptimizedDisjointSet sets(V);
	FOR(i, 0, edges.size())
	{
		//����(u, v)�� �˻��Ѵ�.
		int cost = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;
		//�̹� u�� v�� ����Ǿ� ���� ��� �����Ѵ�.
		if (sets.find(u) == sets.find(v))
			continue;
		//�� ���� ��ģ��.
		sets.merge(u, v);
		selected.push_back(make_pair(u, v));
		ret += cost;
	}
	return ret;
}

//���� �˰����� ����
const int INF = 987654321;
//������ ����
//int V;
//�׷����� ��������Ʈ. (����� ���� ��ȣ, ���� ����ġ) ���� ��´�.
//vector<pair<int, int> > adjD[MAX_V];
//�־��� �׷����� ���� �ּ� ���д� Ʈ���� ���Ե� ���� ����� selected�� �����ϰ�, ����ġ�� ���� ��ȯ�Ѵ�.
int prim(vector<pair<int, int> >& selected)
{
    selected.clear();
    //�ش� ������ Ʈ���� ���ԵǾ� �ֳ�?
    vector<bool> added(V, false);
    //Ʈ���� ������ ���� �� �ش� ������ ��� �ּ� ������ ������ �����Ѵ�.
    vector<int> minWeight(V, INF), parent(V, -1);
    //����ġ�� ���� ������ ����
    int ret = 0;
    //0�� ������ ����������: �׻� Ʈ���� ���� ���� �߰��Ѵ�.
    minWeight[0] = parent[0] = 0;
    FOR(iter, 0, V)
    {
        //������ Ʈ���� �߰��� ���� u�� ã�´�.
        int u = -1;
        FOR(v, 0, V)
            if (!added[v] && (u == -1 || minWeight[u] > minWeight[v]))
                u = v;
        //(parent[u], u)�� Ʈ���� �߰��Ѵ�.
        if (parent[u] != u)
            selected.push_back(make_pair(parent[u], u));
        ret += minWeight[u];
        added[u] = true;
        //u�� ������ ���� (u,v)���� �˻��Ѵ�.
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

//��Ʈ��ũ ���� ������ �ذ��ϴ� ����-��Ŀ�� �˰����� ����
//int V;
//capacity[u][v] = u���� v�� ���� �� �ִ� �뷮
//flow[u][v] = u���� v�� �귯���� ����(�ݴ� ������ ��� ����)
int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];
//flow[][]�� ����ϰ� �� ������ ��ȯ�Ѵ�.
int networkFlow(int source, int sink)
{
    //flow�� 0���� �ʱ�ȭ�Ѵ�.
    memset(flow, 0 ,sizeof(flow));
    int totalFlow = 0;
    while(true)
    {
        //�ʺ� �켱 Ž������ ���� ��θ� ã�´�
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
        //���� ��ΰ� ������ �����Ѵ�
        if (parent[sink] == -1)
            break;
        //���� ��θ� ���� ������ �󸶳� ������ �����Ѵ�.
        int amount = INF;
        for(int p = sink; p != source; p = parent[p])
            amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
        //���� ��θ� ���� ������ ������
        for(int p = sink; p != source; p = parent[p])
        {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        totalFlow += amount;
    }
    return totalFlow;
}

//�̺� ��Ī ������ �ذ��ϴ� ���� ��� �˰���
//A�� B�� ������ ����
int n, m;
//adj[i][j] = Ai�� Bi�� ����Ǿ� �ִ°�?
//bool adj[MAX_N][MAX_N];
//�� ������ ��Ī�� ��� ������ ��ȣ�� �����Ѵ�.
vector<int> aMatch, bMatch;
//dfs() �湮 ����
vector<bool> visited;
//A�� ������ a���� B�� ��Ī���� ���� �������� ���� ��θ� ã�´�.
bool dfs(int a)
{
    if (visited[a])
        return false;
    visited[a] = true;
    FOR(b,0,m)
    {
        if (adj[a][b])
        {
            //b�� ��Ī�Ǿ� ���� �ʴٸ� bMatch[b]�������� ������ ���� ��θ� ã�´�
            if(bMatch[b] == -1 || dfs(bMatch[b]))
            {
                //���� ��� �߰�!! a�� b�� ��ġ��Ų��
                aMatch[a] = b;
                bMatch[b] = a;
                return true;
            }
        }
    }
    return false;
}
//aMatch, bMatch �迭�� ����ϰ� �ִ� ��Ī�� ũ�⸦ ��ȯ�Ѵ�
int bipartiteMatch()
{
    //ó������ � ������ ����Ǿ� ���� �ʴ�.
    aMatch = vector<int>(n, -1);
    bMatch = vector<int>(m, -1);
    int size = 0;
    FOR(start, 0, n)
    {
        visited = vector<bool>(n, false);
        //���� �켱 Ž���� �̿��� start���� ������ ���� ��θ� ã�´�.
        if (dfs(start))
            size++;
    }
    return size;
}
//�̺� �׷����� �ִ� ���� ���� ����ϱ�
//�� ������ ��Ī�� ��� ������ ��ȣ�� �����Ѵ�. ��Ī���� ���� ��� -1
//vector<int> aMatch, bMatch;
//aChosen[i] = �ִ� ���� ���տ� A_i�� ���ԵǾ��°�?
//bChosen[i] = �ִ� ���� ���տ� B_i�� ���ԵǾ��°�?
vector<bool> aChosen, bChosen;
//�̺� �׷����� ������ �־��� �� ���� �ִ� ���� ������ ����Ѵ�.
void calcMaxIndependentSet()
{
    //aMatch[]�� bMatch[]�� ����Ѵ�
    int C = bipartiteMatch();
    //1. A�� ��� �������� �����ϰ�, B���� �������� ���� �������� �����Ѵ�.
    aChosen = vector<bool>(n, true);
    bChosen = vector<bool>(m, false);
    FOR(i,0,m)
    {
        if (bMatch[i] == -1)
            bChosen[i] = true;
    }
    //2. �� ������ ����Ǿ� ���� ���, ���� A�� ������ ����� B�� ������ ������ ��� �����Ѵ�.
    //�� �̻� ��ȭ�� �Ͼ�� ���� ������ �ݺ��Ѵ�.
    while(true)
    {
        bool changed = false;
        FOR(i, 0, n)
        {
            FOR(j, 0, m)
            {
                if(aChosen[i] && bChosen[j] && adj[i][j])
                {
                    //A�� �׻� ��Ī�� ���Ե� �������� ������ �� �ִ�.
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
//a�� k�� ���� ���� �� a�� ���� ����
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
