#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector< vector<pair <int, int > > >adj(100);
vector<pair<int, int> >dist(100);
const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair< pair<int, int>, int > >edge;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back(make_pair(make_pair(u, v), w));
        dist[u].first = INF;
        dist[v].first = INF;
    }
    dist[0].first = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < edge.size(); j++) {
            int u = edge[j].first.first, v = edge[j].first.second, w = edge[j].second;
            if(dist[v].first > dist[u].first + w) {
                if(i == n) {
                    cout << "Negative cycle found\n";
                    break;
                }
                dist[v].first = dist[u].first + w;
                dist[v].second = u;
            }
        }
    }

    for(int i = 0; i< n; i++){
        cout << i << "---> " << dist[i].first << " Parent --->" << dist[i].second <<endl;
    }
    return 0;
}
