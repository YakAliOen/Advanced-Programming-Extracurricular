#include <iostream>
#include <vector> //untuk menyimpan data dari rute menuju F
using namespace std;
#define INF 9999
#define V 6 //amount of vertex
//Function to showcase all route

void printpath(vector <int>parent[], int node, string path){
    //Vector <int>: to store all route (yg dikunjungi)
    if(node == -1){
        cout<< path <<endl;
        return;
    }
    //loop for showing path
    for(int i=0; i < parent[node].size(); i++){
        int p = parent[node][i]; //to take parent or an active node
        //proses output rute D - F
        printpath(parent, p, char('A' + node) + string(""));
    }
}

int main(){
    int graph [V][V]{
        //Metrix
        //A  B  C   D  E   F
        { 0, 5, 10, 0, 11, 0}, //The first block's distances
        { 5, 0, 7, 3, 0, 0}, //The second block
        { 10, 7, 0, 0, 15, 4},
        { 0, 3, 0, 0, 0, 0},
        { 11, 0, 15, 0, 0, 0},
        { 0, 0, 0, 4, 0, 0}
    };

    int distance[V]; //Jarak terpendek
    int visited[V]; //Vertex visited
    int parent[V]; //The node that'll be activated
    int start = 3; //Start D
    int finish = 5; //Finish F

    for(int i = 0; i < V; i++){
        distance[i] = INF; //Haven't started
        visited[i] = 0; //Haven't started
        parent[i] = -1; //Vertex D sdh pasti tdk dipakai        
    }
    distance[start] = 0;

    for(int i = 0; i < V - 1; i++){ //Node D can't be used anymore so -1
        int min = INF;
        int u = -1; //u stores edge w distance
    
        for(int j = 0; j < V - 2; j++){
            if(!visited[j] && distance[j] < min){
                min = distance[j];
                u = j; //to store the nominal's distance
            }
        }
        visited[u] = 1; //to change into the node beside it
        
        //loop to finish
        for(int k = 0; k < V; k++){
             if(!visited[V] && graph[u][k] != 0 && distance[u] + graph[u][k] < distance[V]){
                distance[k] = distance[u] + graph[u][k]; 
                parent[k] = u; //process to store node for through output
            }
        }
    }
    cout<<"Jarak pendek = "<< distance[finish] <<endl;
    int temp = finish;
    
    while(temp != -1){
        cout<<char('A' + temp)<<" "; //char = one alphabet only
        temp = parent[temp];
    }

    return 0;
}
