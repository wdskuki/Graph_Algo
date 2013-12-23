#include <queue>
#include <iostream>
using namespace std;
#include <stdio.h>
#define INFINITE 999999
#define NIL -1

class DFS{
public:
	int n;// node num in the Graph
	int **adj; // node relation
	int my_time; // time 
	enum Color{WHITE, GRAY, BLACK};
	struct Node{
		Color clr;
		int d;
		int f;
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

		my_time = 0;
		fclose(fi);

	}


	void dfs(){
		for(int i = 0; i < n; i++){
			node[i].clr = WHITE;
			node[i].pi = NIL;
		}
		
		my_time = 0;

		for(int i = 0; i < n; i++){
			if(node[i].clr == WHITE)
				dfs_visit(i);
		}

	}
	void dfs_visit(int u){
		my_time = my_time + 1;
		node[u].d = my_time;
		node[u].clr = GRAY;
		for(int v = 0; v < n; v++){
			if(adj[u][v] == 0)
				continue;
			if(node[v].clr == WHITE){
				node[v].pi = u;
				dfs_visit(v);
			}
		}
		node[u].clr = BLACK;
		my_time = my_time + 1;
		node[u].f = my_time;
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
				<<"f: "<<node[i].f<<"\t"
				<<"pi: "<<node[i].pi<<endl;
	}
};


int main(int argc, char const *argv[])
{
	DFS d;
	d.init();
	d.dfs();
	d.print();
	d.clean();
	return 0;
}