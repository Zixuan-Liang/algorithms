#include <iostream>
#include <vector>
#include <algorithm>

struct Vertex{
    int distance;
    int pred;
};

struct Edge{
    int source;
    int destination;
    int weight;
};

struct Graph{
    int V;
    int E;
    struct Vertex* vertices;
    struct Edge* edges;
};

struct Graph* CreateGraph(int V, int E){
    auto* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->vertices = new Vertex[V];
    graph->edges = new Edge[E];
    return graph;
}

void Dijkstra(struct Graph* graph, int source){
    int V = graph->V;
    int E = graph->E;

    // Initialize single source
    for (int i = 0; i < V; i++){
        graph->vertices[i].distance = INT_MAX;
        graph->vertices[i].pred = -1;
    }
    graph->vertices[0].distance = 0;

    std::vector<int> queue;
    queue.reserve(V);
    for (int i = 0; i < V; i++){
        queue.push_back(i);
    }

    while (!queue.empty()){
        // Extract min
        int u = queue[0];
        int min_distance = graph->vertices[u].distance;
        for (int i : queue){
            if (graph->vertices[i].distance < min_distance){
                u = i;
                min_distance = graph->vertices[i].distance;
            }
        }
        queue.erase(std::remove(queue.begin(), queue.end(), u), queue.end());
        // Relax
        for (int j = 0; j < E; j++){
            if (graph->edges[j].source == u){
                int v = graph->edges[j].destination;
                int weight = graph->edges[j].weight;
                int u_dist = graph->vertices[u].distance;
                int v_dist = graph->vertices[v].distance;
                if (u_dist + weight < v_dist){
                    graph->vertices[v].distance = u_dist + weight;
                    graph->vertices[v].pred = u;
                }
            }
        }
    }
}

int main(){
    int V = 5;
    int E = 10;
    struct Graph* graph = CreateGraph(V, E);
    int sources[] = {0,1,1,3,3,2,4,0,3,4};
    int destinations[] = {1,2,3,1,2,4,2,3,4,0};
    int weights[] = {10,1,2,3,9,4,6,5,2,7};

    for (int i = 0; i < E; ++i) {
        graph->edges[i].source = sources[i];
        graph->edges[i].destination = destinations[i];
        graph->edges[i].weight = weights[i];
    }

    Dijkstra(graph, 0);

    std::cout << "Vertex  Distance-to-Source  Predecessor-Vertex" << std::endl;
    for (int i = 0; i < V; i++){
        std::cout << i << "       ";
        std::cout << graph->vertices[i].distance << "                   ";
        std::cout << graph->vertices[i].pred << std::endl;
    }
}