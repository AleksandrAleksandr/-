#include <iostream>
#include <fstream>
#include "vector"
using namespace std;

class Graph
{
public:
	Graph(int n){ used.resize(n); enter.resize(n); low.resize(n); graph.resize(n); this->siz = n;};
	vector<vector<int>> graph; 
	
	void dfs(int, int);
	void FindBridges();
	void Bridge(int, int);
private:
	int siz;
	int time;
	vector <bool> used;
	vector <int> enter;
	vector <int> low;
};

void Graph::dfs(int a, int parent = -1)
{
	used[a] = true;
	time++;
	enter[a] = time;
	low[a] = time;
	for (size_t i = 0; i < graph[a].size(); ++i) //потомки a
	{
		int to = graph[a][i];  //потомок
		if (to == parent) continue;

		if (used[to]){ low[a] = min( low[a], enter[to]); /*cout<<a<<" "<<to<<" -reverse"<<endl;*/ } //обратное ребро
		else{
			dfs(to, a);
			low[a] = min ( low[a], low[to]);
			//cout<<"a="<<a<<" b="<<to<<" "<<low[a]<<" "<<low[to]<<" "<<enter[a]<<endl;
			if (low[to] > enter[a])
				Bridge(a, to);
		}
	}
};

void Graph::FindBridges()
{
	//cout<<graph[0].size()<<endl;
	time = 0;
	for (int i = 0; i < siz; ++i)
		used[i] = false;
	for (int i = 0; i < siz; ++i)
		if (!used[i])
			dfs(i);
}

void Graph::Bridge(int a, int b)
{
	cout<<"edge "<< a <<" "<< b <<" is bridge"<<endl;
}

void createGraph()
{
	char buf[10];
	ifstream file;
	file.open("graph.txt");
	file.getline(buf, 10);
	int point = atoi(buf);
	//cout<<point<<endl;
	Graph g(point);
	
	while (file.getline(buf, 10))
	{
		int i = 0;
		string left = "";
		string right = "";
		while (buf[i] != ' ')
		{
			left += buf[i];
			i++;
		}
		i++;
		while (buf[i] <= '9' && buf[i]>= '0')
		{
			right += buf[i];
			i++;
		}
		int start = atoi(left.c_str());
		int finish = atoi(right.c_str());
		g.graph[start].push_back(finish);
		g.graph[finish].push_back(start);
		//cout<<start<<" "<<finish<<endl;
	}
	g.FindBridges();
}


void main()
{
	createGraph();
	system("pause");
}