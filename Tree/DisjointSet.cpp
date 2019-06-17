#include <vector>
// 트리를 이용해 상호 배제적 집합을 구한다.
struct OptimizedDisjointSet
{
    vector<int> parent, rank;
    OptimizedDisjointSet(int n): parent(n), rank(n, 1)
    {
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
    // u가 속한 트리의 루트의 번호를 반환한다.
    int find(int u)
    {
        if ( u == parent[u])
            return u;
        
        return parent[u] = find(parent[u]);
    }
    // u가 속한 트리와 v가 속한 트리를 합한다.
    void merge(int u, int v)
    {
        u = find(u);
        v = find(v);
        // u와 v가 이미 같은 집합에 속하는 경우를 걸러낸다.
        if (u == v)
            return;

        if (rank[u] > rand[v]) 
            swap(u, v);
        // 이제 rank[v]가 항상 rank[u] 이상이므로 u를 v의 자식으로 넣는다.
        parent[u] = v;
        if (rank[u] == rank[v])
            ++rank[v];
    }
};
