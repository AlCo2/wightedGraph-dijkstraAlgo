#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 1e9;

vector<int> test;

struct Edge {
    int dest;
    int weight;
};

class Graph{
private:
    int verteceMax;
    vector<vector<Edge>> graph;

public:
    Graph(int verteceMax){
        this->verteceMax = verteceMax;
        graph.resize(verteceMax);
    }

    void addEdge(int src, int dest, int weight){
        graph[src].push_back({dest, weight});
        graph[dest].push_back({src, weight});
    }

    void show(){
        for(int i=0;i<verteceMax;i++){
            cout << "vertece "<< i<< ":" << endl;
            for(Edge edge : graph[i]){
                cout << "  edge(" << edge.dest << ")  weight: " << edge.weight;
            }
        cout << endl;
        }
    }
    void dijkstra(int src, int dest){
        vector<int> dist(verteceMax, INF);
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while(!pq.empty()){
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if(d>dist[u])
                continue;
            for(Edge& edge : graph[u]){
                int v = edge.dest;
                int w = edge.weight;
                if(dist[u]+w <dist[v]){
                    dist[v] = dist[u]+w;
                    pq.push({dist[v], v});
                }
            }
        }
        cout << dist[dest];
    }

};





int main(){
    Graph graph(6);
    graph.addEdge(0, 1, 6);
    graph.addEdge(0, 3, 1);
    graph.addEdge(1, 3, 2);
    graph.addEdge(1, 4, 2);
    graph.addEdge(1, 2, 5);
    graph.addEdge(2, 4, 5);
    graph.addEdge(3, 4, 1);
    graph.addEdge(5, 5, 0);
    graph.dijkstra(0, 2);
    return 0;
}
