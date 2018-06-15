#include <iostream> //标准输入输出 
#include <queue> // 队列库 包含的成员 priority_queue<T> 
#include <vector> //包含vector 
#include <sstream> //包含stringstream 
#include <cstring> //包含memset() 
#include <string> //包含string 
#include <cstdlib> //包含malloc 
#include <cassert> //包含assert 
#include <cstdio> //这个是标准输入输入输出的C语言版 包含stdin 指针 
#include <algorithm>
#include <malloc.h> //包含_msize() 测量malloc分配了多少内存 
#define INF -1
#define LOCAL
using namespace std;
typedef vector<int> ROW;
typedef struct Edge
{
	int from, to, dist;
	Edge(int _from, int _to, int _dist) :from(_from), to(_to), dist(_dist) {
	}
	friend ostream& operator <<(ostream &out, Edge &edge) {
		out << edge.from << ' ' << edge.to << ' ' << edge.dist;
		return out;
	}
}Edge;
template <typename T>
void travel_vec(vector<T> &vec) {
	for (typename vector<T>::iterator vec_it = vec.begin(); vec_it != vec.end(); vec_it++) {
		cout << *vec_it << "	";
	}
	cout << endl;
}
struct Graph
{
	bool isDirect;//是否为有向图 
	int points, edge_count; //points定点数目,边计数
	vector<Edge> edges;//存储边的一个动态数组 
	vector<ROW> graph_index;//用索引图来索引edge 存储边的索引的二维数组 
	Graph(int _points, bool _isDirect) :points(_points), isDirect(_isDirect) {//graph的构造函数 
		this->edges.clear();
		this->edge_count = 0;
		this->graph_index.clear();
		for (int i = 0; i<_points; i++) {
			this->graph_index.push_back(ROW());//在二维数组中加入每一行 用每一行来表示每一个顶点链接的边 
		}
	}
	void addEdge(int _from, int _to, int _dist) {
		assert(_from >= 0 && _from<points);
		assert(_to >= 0 && _to<points);
		assert(graph_index[_from].size()<points);
		this->edges.push_back(Edge(_from, _to, _dist));//加入这条边 
		this->edge_count++;//边计数++ 
		graph_index[_from].push_back(edges.size() - 1);//把边的索引存入二维数组中 
		if (!isDirect) {
			graph_index[_to].push_back(edges.size() - 1);//如果是无向图则把反向的路径又存入对应的数组 
		}

	}
	bool hasEdge(int _from, int _to) {//查询是否存在这条边 
		for (int i = 0; i<edges.size(); i++) {
			if (edges[i].from == _from&&edges[i].to == _to) {
				return true;
			}
		}
		return false;
	}
};
struct HeapNode//堆节点存储元素 
{
	int h_dist, h_ver;//元素中包含距离和定点 
	bool operator <(const HeapNode &rhs) const {
		return this->h_dist>rhs.h_dist;// 
	}
	HeapNode(int _hver, int _hdist) :h_dist(_hdist), h_ver(_hver) {
	}
};
struct Dijkstra
{
	bool *marked;//找过的元素的数组 
	int *dist;//存储的是源点到某个点的距离 
	int *path;//保存路径
	Graph &graph;
	Dijkstra(Graph &_graph) :graph(_graph) {
		marked = (bool *)malloc(graph.points * sizeof(bool));//有多少个点就分配多少个空间来存储是否查询过这个点 
		dist = (int *)malloc(graph.points * sizeof(int));//存储源点到某个点的距离 
		path = (int *)malloc(graph.points * sizeof(int));//存储某个点前驱节点 从哪个地方来的 
	}
	void TravelDist() {//遍历dist数组 
		cout << "Dist array is ";
		for (int i = 0; i<graph.points; i++) {
			cout << dist[i] << ' ';
		}
		cout << endl;
	}
	void TravelPath() {//遍历path数组 
		cout << "Path array is ";
		for (int i = 0; i<graph.points; i++) {
			cout << path[i] << ' ';
		}
		cout << endl;
	}
	void dijkstra(int source) {
		priority_queue<HeapNode> qheap;//优先队列 让路径比较短的先出队列 
		memset(dist, INF, _msize(dist)); //初始化dist权值数组 全部为不可达  
//		for (int i = 0; i < graph.points; i++) dist[i] = INF, marked[i] = false;
		dist[source] = 0;//源点到自己的距离是0 	
		memset(marked, false, _msize(marked));
		//memset(marked, false, sizeof(bool)*graph->points);
		path[source] = source;
		qheap.push(HeapNode(source,0));//源点进队 
		while (!qheap.empty()) {//队列不为空 则执行出队 
			HeapNode tempnode = qheap.top();//出队的元素总是源点到某个点距离最小的那个元素 
			qheap.pop();//删除队头 
			int tempver = tempnode.h_ver;//找到出队的点 
			if (marked[tempver]) continue;//如果说这个点已经被访问过了，取下一个队头 
			marked[tempver] = true;//置位 这个点被访问过 
			int row_size=(this->graph.graph_index[tempver]).size();
			for (int i = 0; i<row_size; i++) {//松弛操作 
				Edge &tempEdge = graph.edges[this->graph.graph_index[tempver][i]];
				if(tempEdge.to==tempver&&!graph.isDirect) {
					swap(tempEdge.from, tempEdge.to);
				}
				if (dist[tempEdge.to] == INF || dist[tempEdge.to]>dist[tempver] + tempEdge.dist) {
					//如果说源点到某个点存储的距离是无穷 或者之前存储的距离大于 源点到当前点加上当前点到所寻找的点的距离之和 
					//V0 到 V4 之前的距离是20或者是INF 但是dist(v0->v1)+dist(v1->v4)<dist(v0->v4) 则替换dist(v0->v4)
					dist[tempEdge.to] = dist[tempver] + tempEdge.dist;
					path[tempEdge.to] = tempver;//并且存储寻找的点的前驱节点 比如说到v4的前驱节点就是v1 
					qheap.push(HeapNode(tempEdge.to, dist[tempEdge.to]));//并且让它入队 
				}
			}
		}
	}
	~Dijkstra() {
		delete marked;
		delete dist;
		delete path;
	}
};
int main(int argc, char *argv[]) {
#ifdef LOCAL
	FILE *file = NULL;
	file = freopen("intext.txt", "r", stdin);
	if (file != NULL) {
		cout << "read successfully" << endl;
	}
	//	freopen("outtext.txt","w",stdout);
#endif
	string line;
	while (getline(cin, line)) {//获取输入的一行 
								//		cout << line << endl;
		int points, edges;//存储点和边 
		int source_num;
		stringstream ss(line);
		ss >> points;
		ss >> edges;//把字符串转化为int 
		Graph graph(points, false);
		for (int e = 0; e<edges+1&&getline(cin, line); e++) {//遍历输入的边 
			ss.clear();
			ss.str(line);
			int in_num;
			int argu[3];//把每一行的参数存入数组 
			if (e == edges) {
				ss >> source_num;
				break;
			}
			for (int i = 0; i<3 && ss >> in_num; i++) {
				argu[i] = in_num;
			}
			//cout<<argu[0]<<' '<<argu[1]<<' '<<argu[2]<<endl;
			if (!graph.hasEdge(argu[0], argu[1])) {//如果说图里面不存在这一条边 防止平行边 
				graph.addEdge(argu[0], argu[1], argu[2]);//就加入这个图 
			}
		}
//		cout << source_num << endl;
		//travel_vec(graph.edges);//遍历 
		Dijkstra dijkstra(graph);
		dijkstra.dijkstra(source_num);
		dijkstra.TravelDist();
		dijkstra.TravelPath();
	}
	system("pause");
	return 0;
}

