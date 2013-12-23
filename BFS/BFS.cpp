#include <queue>
#include <iostream>
using namespace std;
#include <stdio.h>
#define MAX 999999

class BFS{
public:
	int n;// node num in the Graph
	int **adj; // node relation
	
	enum Color{WHITE, GRAY, BLACK};
	struct Node{
		Color clr;
		int d;
		int pi;
	} *node; // node struct

	void init(){
		FILE *fi;
		fi = fopen("input.in", "r");
		fscanf(fi, "%d", &n);

		node = new Node [n];

		adj = new int * [n];
		for(int i = 0; i < n; i++)
			adj[i] = new int [n];

		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				adj[i][j] = 0;

		int v1, v2;
		while(fscanf(fi, "%d%d",&v1, &v2) != EOF)
			adj[v1][v2] = 1;		

		fclose(fi);

	}

	void bfs(int s){
		for(int i = 0; i < n; i++){
			node[i].clr = WHITE;
			node[i].d = MAX;
			node[i].pi = -1;
		}
		node[s].clr = GRAY;
		node[s].d = 0;
		node[s].pi = -1;

		queue<int> Q;
		Q.push(s);
		while(!Q.empty()){
			int u = Q.front();
			Q.pop();
			for(int v = 0; v < n; v++){
				if(adj[u][v] == 0)
					continue;
				if(node[v].clr == WHITE){
					node[v].clr = GRAY;
					node[v].d = node[u].d + 1;
					node[v].pi = u;
					Q.push(v);
				}
			}
			node[u].clr = BLACK;
		}
	}
	void clean(){
		delete [] node;

		for(int i = 0; i < n; i++)
			delete adj[i];
		delete adj;
	}
	void print_adj(){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cout<<adj[i][j]<<" ";
			cout<<endl;
		}
	}
	void print(){
		for(int i = 0; i < n; i++)
			cout<<"node: "<<i<<"\t"
				<<"Color: "<<node[i].clr<<"\t"
				<<"d: "<<node[i].d<<"\t"
				<<"pi: "<<node[i].pi<<endl;
	}
};


int main(int argc, char const *argv[])
{
	BFS b;
	b.init();
	b.bfs(1);
	b.print();
	b.clean();
	return 0;
}