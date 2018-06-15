#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib> 
using namespace std;
typedef vector<int> ROW;
typedef struct Graph{
	int ver_count;
	bool isDirected;
	vector<ROW> graph;
	Graph(int _ver_count,bool _isDirected):ver_count(_ver_count),isDirected(_isDirected){
		graph.clear();
		for(int i=0;i<_ver_count;i++){
			graph.push_back(ROW()); 
		}
	} 
	void addEdge(int _from,int _to){
		graph[_from].push_back(_to);
		if(!isDirected){
			graph[_to].push_back(_from);
		}
	} 
	bool hasEdge(int _from,int _to){
		for(int i=0;i<graph[_from].size();i++){
			if(graph[_from][i]==_to){
				return true;
			}
		}
		return false;
	}
}Graph; 

struct DFS{
	Graph &graph;
	bool *isVisited;
	int ccount;//连通分量的记录 
	DFS(Graph &_graph):graph(_graph){
		isVisited=(bool *)malloc(sizeof(bool)*_graph.ver_count);
		for(int i=graph.ver_count;i>0;i--) isVisited[i]=false; 
		ccount=0;
	}
	void __dfs(int ver){
		isVisited[ver]=true;
		for(int i=0;i<graph[ver].size();i++){
			if(!isVisited[i]){
				__dfs(i);
			} 
		}
	}
	void dfsForCount(){
		for(int i=0;i<graph.ver_count;i++){
			if(!isVisited[i]){
				__dfs(i);
				ccount++;
			}
		}
	}
	~DFS(){
		delete isVisited;
	}	
};
 
int main(int argc, char *argv[]) {
	string line;
	while(getline(cin,line)){
		
	} 
	return 0;
}
