//consider in undirected Graph

#include <list>
#include <iostream>
#include <algorithm>
using namespace std;
#include <stdio.h>
#define INFINITE 999999
#define NIL -1

class Prim{
public:
	int n;// node num in the Graph
	int **adj; // node relation

	struct Node{
		int id;
		int key;
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

		int v1, v2, w;
		while(fscanf(fi, "%d%d%d",&v1, &v2, &w) != EOF){
			adj[v1][v2] = w;
			adj[v2][v1] = w;
		}		

		fclose(fi);

	}

	void prim(int r){
		for(int i = 0; i < n; i++){
			node[i].key = INFINITE;
			node[i].pi = NIL;
			node[i].id = i;
		}
		node[r].key = 0;
		list< Node* > Q;
		for(int i = 0; i < n; i++) 
			Q.push_back(&node[i]);
		while(!Q.empty()){
			int u = extract_min(Q);
			for(int v = 0; v < n; v++){
				if(adj[u][v] == 0)
					continue;
				if( (find(Q.begin(), Q.end(), &node[v]) != Q.end() ) &&
					adj[u][v] < node[v].key){
					node[v].pi = u;
					node[v].key = adj[u][v];
				}
			}
		}
	}

	int extract_min(list< Node * > &Q){
		list< Node * > :: iterator minIter, iter;
		minIter = Q.begin();
		for(iter = Q.begin(); iter != Q.end(); iter++){
			if((*iter)->key < (*minIter)->key)
				minIter = iter;
		}
		int id = (*minIter)->id;
		Q.erase(minIter);
		return id;
	}


	void clean(){
		delete [] node;

		for(int i = 0; i < n; i++)
			delete [] adj[i];
		delete [] adj;
	}
	void print_adj(){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cout<<adj[i][j]<<" ";
			cout<<endl;
		}
	}
	void print(){
		for(int i = 0; i < n; i++){
			cout<<"node: "<<i<<"\t"
				<<"key: "<<node[i].key<<"\t"
				<<"pi: "<<node[i].pi<<endl;
		}
	}
};


int main(int argc, char const *argv[])
{
	Prim p;
	p.init();
	p.prim(0);
	//p.print_adj();
	p.print();
	p.clean();
	return 0;
}