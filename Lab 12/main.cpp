#include <iostream>

#define INF 1000000

using namespace std;

int* Dijkstras(int s, int matrix[6][6]){

    int distance[6] = {INF,INF,INF,INF,INF,INF};
    int pred[6] = {s,s,s,s,s,s};
    bool visited[6] = {false,false,false,false,false,false};

    distance[s] = 0;
    for(int i=0; i<6; i++){
        if(matrix[s][i] != 0){
            distance[i] = matrix[s][i];
        }
    }
    visited[s] = true;

    for(int i=0; i<5; i++){
        int g_distance = INF;
        int g;
        for(int j=0; j<6; j++){
            if(distance[j] < g_distance && !visited[j]){
                g = j;
                g_distance = distance[j];
            }
        }

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
        total_time += distance[d];
    }
    avg_time = total_time/5.0;
    printf("Average Time = %.2f", avg_time);

    return distance;
}

int main()
{
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
