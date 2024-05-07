// Ricardo Jiménez Ureña A01636825
// Rodrigo Chavez Avalos A01635547
#include <iostream>
#include <vector>
#include <climits>
#include <fstream>

using namespace std;

// Complexity: O(V^2) 
int findMinVertex(vector<double>& distance, vector<bool>& visited) {
    int minVertex = -1;
    for(int i = 0; i < distance.size(); i++) {
        if(!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])) {
            minVertex = i;
        }
    }
    return minVertex;
}

// Complexity: O(V^2) 
void dijkstra(vector<vector<double> >& graph, int src) {
    int n = graph.size();
    vector<double> distance(n, INT_MAX);
    vector<bool> visited(n, false);
    distance[src] = 0;
    for(int i = 0; i < n-1; i++) {
        int minVertex = findMinVertex(distance, visited);
        visited[minVertex] = true;
        for(int j = 0; j < n; j++) {
            if(graph[minVertex][j] != -1 && !visited[j] && distance[minVertex] != INT_MAX && distance[minVertex] + graph[minVertex][j] < distance[j]) {
                distance[j] = distance[minVertex] + graph[minVertex][j];
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(i != src) {
            cout << "node " << src << " to node " << i << " : " << (distance[i] == INT_MAX ? -1 : distance[i]) << endl;
        }
    }
}

// Complexity: O(V^3) 
void floyd(vector<vector<double> >& graph) {
    int n = graph.size();
    vector<vector<double> > dist = graph;
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][k] != -1 && dist[k][j] != -1) {
                    if(dist[i][j] == -1 || dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
    cout << "\nFloyd :" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ifstream file("1000EWD.txt");
    if(!file.is_open()) {
        cout << "Error opening file. Exiting...\n";
        return 1;
    }
    int n, edges;
    file >> n >> edges;
    vector<vector<double> > graph(n, vector<double>(n, -1));
    for(int i = 0; i < n; i++) {
        graph[i][i] = 0;
    }
    for(int i = 0; i < edges; i++) {
        int u, v;
        double w;
        file >> u >> v >> w;
        if(u >= n || v >= n || u < 0 || v < 0) {
            cout << "Invalid node number in edge data: " << u << " " << v << " " << w << ". Exiting...\n";
            return 1;
        }
        graph[u][v] = w;
    }
    file.close();
    for(int i = 0; i < n; i++) {
        dijkstra(graph, i);
    }
    floyd(graph);
    return 0;
}