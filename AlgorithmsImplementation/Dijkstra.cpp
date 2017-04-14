#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<char, vector<pair <char, int> > >adj;
map<char, int>dist, mark;
map<char, char> parent;

const int INF = 1e9;

void dijkstra(char start) {

    dist[start] = 0;
    priority_queue< pair<int, char>, vector< pair<int, char> >, greater< pair<int, int> > > pq;
    pq.push(make_pair(dist[start], start));
    while(!pq.empty()) {
        char top = pq.top().second;
        pq.pop();

        if(mark[top])continue;

        mark[top] = 1;

        for(int i = 0; i < adj[top].size(); i++) {
            if(dist[adj[top][i].first] > dist[top] + adj[top][i].second) {
                dist[adj[top][i].first] = dist[top] + adj[top][i].second;
                pq.push(make_pair(dist[adj[top][i].first], adj[top][i].first));
                parent[adj[top][i].first] = top;
            }
        }
    }
}

int main() {

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        char x, y;
        int w;
        cin >> x >> y >> w;
        adj[x].push_back(make_pair(y, w));
        adj[y].push_back(make_pair(x, w));
        mark[x] = mark[y] = 0;
        dist[x] = dist[y] = INF;
    }
    dijkstra('A');

    for(map<char, char>::iterator it = parent.begin(); it != parent.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    
    return 0;

}
