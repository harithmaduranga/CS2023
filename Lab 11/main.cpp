#include <iostream>

#define INF 1000000

using namespace std;

// To check whether all vertices are visited, in order to end the algorithm running.
bool check_visited(int* visited){
    for(int v=0; v<6; v++){
        if(!visited[v]){
            return false;
        }
    }
    return true;
}

int main()
{
    // Adjacency matrix of the graph.
    int matrix[6][6] = {{0,3,0,0,0,1},
                        {3,0,2,1,10,0},
                        {0,2,0,3,0,5},
                        {0,1,3,0,5,0},
                        {0,10,0,5,0,4},
                        {1,0,5,0,4,0}};

    int s;  // Current source node variable

    int visited[6] = {false,false,false,false,false,false}; // Initial condition. No node has been visited.

    visited[0] = true;  // Start from node 0.
    s = 0;

    // Resulting adjacency matrix to be
    int MST[6][6] =    {{0,0,0,0,0,0},
                        {0,0,0,0,0,0},
                        {0,0,0,0,0,0},
                        {0,0,0,0,0,0},
                        {0,0,0,0,0,0},
                        {0,0,0,0,0,0}};


    // Iteration ends when all vertices are visited.
    while(!check_visited(visited)){

        int temp_min_weight = INF;  // Minimum weighted edge in each loop.
        int temp_min_weight_a, temp_min_weight_b;   // Between which pair of nodes it has.

        // In each loop, we consider the edges of current and previous source nodes.
        // Such that no one helps creating a cycle.
        // If any node lies between two visited nodes it hepls to create a cycle.
        // And find the minimum of them.
        for(int a=0; a<6; a++){
            if(visited[a]){
                for(int b=0; b<6; b++){
                    if(!visited[b]){
                        if(matrix[a][b] < temp_min_weight && matrix[a][b] != 0){
                            temp_min_weight = matrix[a][b];
                            temp_min_weight_a = a;
                            temp_min_weight_b = b;
                        }
                    }
                }
            }
        }

        // Since this is an undirected graph.
        MST[temp_min_weight_a][temp_min_weight_b] = temp_min_weight;
        MST[temp_min_weight_b][temp_min_weight_a] = temp_min_weight;

        // Where current minimum starts is already visited. We should make where it ends visited.
        visited[temp_min_weight_b] = true;

    }

    // Print the resulting adjacency matrix.
    for(int a=0; a<6; a++){
        for(int b=0; b<6; b++){
            cout << MST[a][b] << " ";
        }
        cout << endl;
    }

}
