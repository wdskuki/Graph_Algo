
/*匈牙利算法 (最大二分匹配) 伪代码*/
// bool 寻找从k出发的对应项出的可增广路
// {
//     while (从邻接表中列举k能关联到顶点j)
//     {
//         if (j不在增广路上)
//         {
//             把j加入增广路;
//             if (j是未盖点 或者 从j的对应项出发有可增广路)
//             {
//                 修改j的对应项为k;
//                 则从k的对应项出有可增广路,返回true;
//             }
//         }
//     }
//     则从k的对应项出没有可增广路,返回false;
// }

// void 匈牙利hungary()
// {
//     for i->1 to n
//     {
//         if (则从i的对应项出有可增广路)
//             匹配数++;
//     }
//     输出 匹配数;
// }

#include <stdio.h>
#include <string.h>

#define MAX 102
long n; //the number of vertex
long match; //the number of match
long adj[MAX][MAX]; 
bool used[MAX]; //the vertex in the augment path
long mat[MAX]; //mat[i] = j means i <-> j

FILE *fi, *fo;

void init(){
	n = 10;
	match = 0;
	for(long i = 1; i <= n; i++){
		for(long j = 1; j <= n; j++){
			adj[i][j] = 0;
		}
	}
	
	for(long i = 1; i <= n; i++)
		used[i] = false;

	for(long i = 1; i <= n; i++)
		mat[i] = 0;

	fi = fopen("./flyer.in", "r");
	fscanf(fi,"%ld", &n);
	long a, b;
	while(fscanf(fi, "%ld%ld", &a, &b)!= EOF){
		adj[a][b] = 1;
	}
	fclose(fi);
}

bool crossPath(long k){
	for(long i = 1; i <= n; i++){
		if(adj[k][i] == 0)
			continue;

		if(!used[i]){
			used[i] = true;
			if(mat[i] == 0 || crossPath(mat[i])){
				mat[i] = k;
				return true;
			}
		}
	}
	return false;
}

void hungarian(){
	for(long i = 1; i <= n; i++)
		mat[i] = 0;

	match = 0;
	
	for(long i = 1; i <= n; i++){
		if(crossPath(i)){
			match++;
		}
		for(long j = 1; j <= n; j++){
			used[j] = false;
		}
	}
}

// void print_adj(){
// 	fo = fopen("./flyer.out", "w");
// 	for(long i = 1; i <= n; i++){
// 		for(long j = 1; j <= n; j++){
// 			//fprintf(fo, "%ld ", adj[i][j]);
// 			printf("%ld ", adj[i][j]);
// 		}
// 		printf("\n");
// 	}
// 	fclose(fo);
// }
void print(){
	printf("%ld\n", match);
}

int main(int argc, char const *argv[])
{
	init();
	hungarian();
	print();
	//	print_adj();
	return 0;
}
