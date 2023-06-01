#include <iostream>

#define INF 1000000   // The big number to suggest infinite distance

using namespace std;

// Function to detect the shortest path weight and average time
int* Dijkstras(int s, int matrix[6][6]){

    int distance[6] = {INF,INF,INF,INF,INF,INF};  // Initial distances
    int pred[6] = {s,s,s,s,s,s};    // Predecessors
    bool visited[6] = {false,false,false,false,false,false};  // Guided nodes

    // First, detects the distances from source node
    distance[s] = 0;
    for(int i=0; i<6; i++){
        if(matrix[s][i] != 0){
            distance[i] = matrix[s][i];
        }
    }
    visited[s] = true;

    // Then, we have to do that 5 more times.
    for(int i=0; i<5; i++){
        // The unvisited least weighted node with current shortest path, will become the guide for this step.
        int g_distance = INF;
        int g;
        for(int j=0; j<6; j++){
            if(distance[j] < g_distance && !visited[j]){
                g = j;
                g_distance = distance[j];
            }
        }

        // If any node can be visited via current giude node through a shorter path than it has been visited previously, assign the new distance.
        // Assign the current guide node as the predecessor.
        for(int k=0; k<6; k++){
            int temp = matrix[g][k];
            if(temp!=0 && !visited[k]){
                if(distance[k] > distance[g]+temp){
                    distance[k] = distance[g]+temp;                }
            }
        }
        visited[g] = true;
    }

    float avg_time;
    int total_time;

    cout << "Source = " << s << endl;
    for(int d=0; d<6; d++){
        cout << d << " --> " << distance[d] << endl;
        total_time += distance[d];  // Total time from source node
    }
    avg_time = total_time/5.0;
    printf("Average Time = %.2f", avg_time);

    return distance;
}

int main()
{
    // Adgacency matrix
    int matrix[6][6] = {{0,10,0,0,15,5},
              {10,0,10,30,0,0},
              {0,10,0,12,5,0},
              {0,30,12,0,0,20},
              {15,0,5,0,0,0},
              {5,0,0,20,0,0} };

    int* shortest_distances = Dijkstras(5, matrix);
    /*for(int d=0; d<6; d++){
        cout << d << " --> " << shortest_distances[d] << endl;
    }*/
}
