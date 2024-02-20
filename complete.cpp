#include<bits/stdc++.h>
using namespace std;

int n;

class graph {
    public:

    unordered_map<int, vector<int> > adj;
    vector<vector<int> > edges;

    void addEdge(int u, int v, bool isDirected) {

        vector<int> store;

        adj[u].push_back(v);
        store.push_back(u);
        store.push_back(v);

        edges.push_back(store);
        if(!isDirected) {
            adj[v].push_back(u);
        }
        
    }

    void printEdges() {
        cout << "-- Edges --" << endl;
        for(auto i:edges) {
            for(auto j:i) {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << "-- Edges --" << endl;
    }

    void printList() {

        for(auto i:adj) {
            cout << i.first << " -> ";

            for(auto j:i.second) {
                cout << j << ", ";
            }
            
            cout << endl;
        }

    }

    vector<int> bfsTraversalAns;
    vector<int> dfsTraversalAns;
    unordered_map<int, bool> visited;
    
    void bfs(int node) {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while(!q.empty()) {
            int frontElement = q.front();
            q.pop();
            bfsTraversalAns.push_back(frontElement);

            for(auto i:adj[frontElement]) {
                if(!visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    void bfsTraversal() {

        for(int i = 1; i <= n; i++) {
            if(!visited[i]) {
                bfs(i);
            }
        }
        cout << endl;
        cout << "BFS traversal: ";
        for(int i = 0; i < bfsTraversalAns.size(); i++) {
            cout << bfsTraversalAns[i] << " ";
        }
        cout << endl;

    }

    void dfs(int node, unordered_map<int, bool> &thisVisited, unordered_map<int, vector<int> > &adj, vector<int> &dfsTraversalAns) {
        dfsTraversalAns.push_back(node);
        thisVisited[node] = true;
        for(auto i:adj[node]) {
            if(!thisVisited[i]) {
                dfs(i, thisVisited, adj, dfsTraversalAns);
            }
        }
    }

    void dfsTraversal() {
        unordered_map<int, bool> thisVisited;
        for(int i = 1; i <= n; i++) {
            if(!thisVisited[i]) {
                dfs(i, thisVisited, adj, dfsTraversalAns);
            }
        }
        cout << endl;
        cout << "DFS traversal: ";
        for(int i = 0; i < dfsTraversalAns.size(); ++i) {
            cout << dfsTraversalAns[i] << " ";
        }
        cout << endl;
    }

    vector<int> getBFS() {
        return bfsTraversalAns;
    }
    
    vector<int> getDFS() {
        return dfsTraversalAns;
    }
};

int main() {

    cout << "Enter the number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    graph g;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, false);
    }

    g.printList();
    cout << endl;
    g.printEdges();
    cout << "BFS traversal" << endl;
    g.bfsTraversal();
    g.dfsTraversal();

    return 0;
}