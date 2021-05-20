#include <iostream>

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

bool BellmanFord(struct Graph* graph, int source){
    int V = graph->V;
    int E = graph->E;

    // Initialize single source
    for (int i = 0; i < V; i++){
        graph->vertices[i].distance = INT_MAX;
        graph->vertices[i].pred = -1;
    }
    graph->vertices[0].distance = 0;

    // Relax
    for (int i = 1; i <= V - 1; i++){
        for (int j = 0; j < E; j++){
            int u = graph->edges[j].source;
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

    // Check negative-weight cycles
    for (int i = 0; i < E; i++){
        int u = graph->edges[i].source;
        int v = graph->edges[i].destination;
        int weight = graph->edges[i].weight;
        int u_dist = graph->vertices[u].distance;
        int v_dist = graph->vertices[v].distance;
        if (u_dist + weight < v_dist){
            return false;
        }
    }

    return true;
}

int main(){
    int V = 5;
    int E = 8;
    struct Graph* graph = CreateGraph(V, E);
    int sources[8] = {0, 0, 1, 1, 1, 3, 3, 4};
    int destinations[8] = {1, 2, 2, 3, 4, 2, 1, 3};
    int weights[8] = {-1, 4, 3, 2, 2, 5, 1, -3};

    for (int i = 0; i < 8; ++i) {
        graph->edges[i].source = sources[i];
        graph->edges[i].destination = destinations[i];
        graph->edges[i].weight = weights[i];
    }

    bool result = BellmanFord(graph, 0);
    if (result){
        std::cout << "There is no negative-weight cycle in the graph. Bellman-Ford algorithm works." << std::endl;
        std::cout << "Vertex  Distance-to-Source  Predecessor-Vertex" << std::endl;
        for (int i = 0; i < V; i++){
            std::cout << i << "       ";
            std::cout << graph->vertices[i].distance << "                   ";
            std::cout << graph->vertices[i].pred << std::endl;
        }
    } else{
        std::cout << "There is negative-weight cycle in the graph. Bellman-Ford algorithm doesn't work." << std::endl;
    }
}