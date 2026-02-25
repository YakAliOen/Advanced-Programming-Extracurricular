#include<iostream>
using namespace std;
#define INF  9999 // angka tidak terbatas
#define V  6 // jumlah vertex : 6 
int main(){
    // matriks / array 2 dimensi = { 1  1}
    //                           = { 2, 2}
    // array 1 dimensi = {1,2,3,4}
 int graph[V][V] = {
        //A  B  C  D  E  F
        { 0, 5, 4, 0,11, 0}, // A
        { 5, 0, 7, 3, 0, 0}, // B
        { 4, 7, 0, 0, 6, 4}, // C
        { 0, 3, 0, 0, 0, 0}, // D
        {11, 0, 6, 0, 0, 0}, // E
        { 0, 0, 4, 0, 0, 0}  // F
    };
    int distance[V]; // jarak terpendek
    int visited[V]; // vertex yang dikunjungi
    int parent[V]; // node yang akan diaktfikan
    int start = 3;          // Start D
    int finish = 5;          // Finish F
   
    // For loop awal
    for(int i = 0; i < V;i++){
        distance[i] = INF;
        visited[i] =0;
        parent[i] = -1 ; // vertex D sudah pasti tidak dipakai
    }
    distance[start] = 0;
    // Logic Shortest Path
    for(int i = 0; i < V - 1;i++){ // v-1 karena node D sudah tidak dipakai
    // Min = menyimpan jarak terkecil (sementara), u = menyimpan edge dengan jarak terkecil
        int min = INF;
        int u = -1 ;
        for (int j = 0; j<V; j++){
            if(!visited[j] && distance[j] < min){
         // jika vertex J belum dicek dan jarak paling kecil maka node J dipilih
            min = distance[j];       
            u = j; // untuk menyimpan edge / nominal jarak
            }
        }
        visited[u] = 1; // pindah ke node sebelah

        // Loop Untuk melanjutkan ke finish
        for (int k= 0; k<V;k ++){
            if(!visited[k] && graph[u][k] !=0 &&
            //node belum sampai ke finish dan nilai graph dari u dan v tidak 0
            distance[u] + graph[u][k] < distance[k]) {
            //jarak sementara + nilai graph < jarak sebelumnya
            distance[k] = distance[u] + graph[u][k];
            // hasil akhir = jarak sementara + jarak sebelumnya
            parent[k] = u; // proses menyimpan node dilewati untuk di output   
            }
        }
    }
    // output jarak
    cout<< " Jarak terpendek ="<< distance[finish] <<endl;
    cout <<"Path / Kota :";
    int temp = finish;
    while (temp != -1){
        cout<<char('A' + temp) <<" ";
        temp = parent[temp];
    }
    return 0;
}
