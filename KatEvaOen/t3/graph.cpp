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
        printpath(parent, p, char('A' + node) + string("") + path);
    }
}

int main(){
    int graph [V][V]{
        //Metrix
        //A  B  C   D  E   F
        { 0, 5, 7, 3, 11, 0}, //The first block's distances
        { 5, 0, 7, 3, 0, 0}, //The second block
        { 7, 7, 0, 0, 6, 4},
        { 3, 3, 0, 0, 0, 0},
        { 11, 0, 6, 0, 0, 0},
        { 0, 0, 4, 0, 0, 0}
    };

    int distance[V]; //Jarak terpendek
    int visited[V]; //Vertex visited

    vector<int> parent[V];
    int start = 3; //Start D
    int finish = 5; //Finish F

    for(int i = 0; i < V; i++){
        distance[i] = INF; //Haven't started
        visited[i] = 0; //Haven't started        
    }
    distance[start] = 0;
    parent[start].push_back(-1); //Vertex D sdh pasti tdk dipakai

    for(int i = 0; i < V - 1; i++){ //Node D can't be used anymore so -1
        int min = INF;
        int u = -1; //u stores edge w distance
    
        for(int j = 0; j < V - 2; j++){
            if(!visited[j] && distance[j] < min){
                min = distance[j];
                u = j; //to store the nominal's distance
            }
        }
        if(u == -1) break;
        visited[u] = 1; //to change into the node beside it
        
        //loop to finish
        for(int k = 0; k < V; k++){
            if(!visited[k] && graph[u][k] != 0){
                int newDist = distance[u] + graph[u][k];
                //newdistance = jarak lama + jarak yang akan dikunjungi
                if(newDist < distance[k]){
                    distance[k] = newDist;
                    parent[k].clear(); //to delete the old parent
                    parent[k].push_back(u); //to store the new node
                }
                else if(newDist == distance[k]){
                    parent[k].push_back(u); //to store the next new node 
                }
            }
        }
    }
    cout<<"Jarak pendek = "<< distance[finish] <<endl;
    cout<<"Semua Path & Path / Kota: ";

    printpath(parent, finish, "");

    return 0;
}
