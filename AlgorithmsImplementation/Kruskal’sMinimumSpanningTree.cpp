#include <bits/stdc++.h>
using namespace std;

vector< vector<pair<int, int> > > mst(100);

struct getMST{
    int root[101];
    int rank[101];
    getMST(){
        for(int i = 0; i <= 100; i++){
            root[i] = i;
            rank[i] = 0;
        }
    }
    int find(int node){
        if(root[node] != node)
            root[node] = find(root[node]);
        return root[node];
    }
    bool Union(int x,int y){
        int rootX = find(x);
        int rootY = find(y);

        if(rootX == rootY)
            return 0;
        if(rank[rootX] > rank[rootY]){
            root[rootY] = rootX;
        }
        else if(rank[rootY] > rank[rootX]){
            root[rootX] = rootY;
        }
        else{
            root[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int > > >edges(m+1);
    for(int i = 0; i< m; i++){
        cin >> edges[i].first >> edges[i].second.first >> edges[i].second.second;
    }
    sort(edges.begin(), edges.end());
    getMST myMST;
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].second.first, v = edges[i].second.second, w = edges[i].first;
        if(myMST.Union(u, v)){
            mst[u].push_back(make_pair(v, w));
            mst[v].push_back(make_pair(u, w));
        }
    }
    return 0;
}
