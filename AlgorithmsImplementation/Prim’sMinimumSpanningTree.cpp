#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define F first
#define S second
#define inf INT_MAX

int dist[1001];
vector< vector<pair<char, int> > >adjList(1000);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector< pair<pair<char, char>, int> >edges;
    set<pair<int, char> >s;
    map<char, pair<char, char> >mp;
    vector<pair<char, char> >res;

    for(int i = 0; i < m; i++) {
        char u, v;
        int w;
        cin >> u >> v >> w;
        edges.push_back({{u, v}, w});
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
        s.insert({inf, u});
        s.insert({inf, v});
        dist[u] = inf;
        dist[v] = inf;
    }

    char start;
    while(!s.empty()) {
        start = s.begin() ->S;
        dist[start] = -1;
        s.erase(s.begin());
        if(mp.find(start) != mp.end()) {
            res.push_back(mp[start]);
        }
        for(int i = 0; i < adjList[start].size(); i++) {
            int u = adjList[start][i].F, w = adjList[start][i].S;
            if(w < dist[u]) {
                s.erase({dist[u], u});
                dist[u] = w;
                s.insert({dist[u], u});
                mp[u] = {start, u};
            }
        }
    }

    for(int i = 0; i < res.size(); i++){
        cout << res[i].F << " " << res[i].S << endl;
    }

    return 0;
}
