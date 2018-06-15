#include <iostream>

using namespace std;

#define INF 99999

void Travel(int  (*dist)[4],int (*path)[4],int colnum){
    cout<<"dist is:"<<endl;
    for (int i = 0; i < colnum; i++) {
        for (int j = 0; j < colnum; j++) {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<"path is:"<<endl;
    for (int i = 0; i < colnum; i++) {
        for (int j = 0; j < colnum; j++) {
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


void Floyd(int (*dist)[4],int (*path)[4],int colnum){
    for (int k = 0; k < colnum; k++) {
        for (int i = 0; i < colnum;i++) {
            for (int j = 0; j < colnum; j++) {
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                    path[i][j]=k;
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
        Travel(dist, path, colnum);
    }
}

int main() {
    int Dist[4][4]={{0,1,4,INF},{INF,0,2,5},{INF,INF,0,1},{2,INF,INF,0}};
    int Path[4][4]={{-1,0,0,-1},{-1,-1,1,1},{-1,-1,-1,2},{3,-1,-1,-1}};
    Travel(Dist, Path,  4);
    Floyd(Dist, Path, 4);
    return 0;
}