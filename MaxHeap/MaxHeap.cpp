//IMPORTANT: index is from i: a[1], a[2] ,....

#include <iostream>
using namespace std;

void max_heapify(int *a, int i, int heap_size){
	int left = i*2;
	int right = i*2+1;
	int large = i;
	if(left <= heap_size && a[left] > a[i])
		large = left;
	if(right <= heap_size && a[right] > a[large])
		large = right;
	if(large != i){
		int t = a[i];
		a[i] = a[large];
		a[large] = t;
		max_heapify(a, large, heap_size);
	}
}

void build_max_heap(int *a, int len, int &heap_size){
	heap_size = len;
	for(int i = len/2; i >= 1; i--)
		max_heapify(a, i, heap_size);
}

void heap_sort(int *a, int len, int &heap_size){
	build_max_heap(a, len, heap_size);
	for(int i = len; i >= 2; i--){
		int t = a[i];
		a[i] = a[1];
		a[1] = t;
		
		heap_size -= 1;

		max_heapify(a, 1, heap_size);
	}
}

void print(int *a, int len){
	for(int i = 1; i <= len; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	int a[] = {-1,21,3,1,2,42,5,12,56};
	int len = 8;
	int heap_size;
	heap_sort(a, len, heap_size);

	print(a, len);
	return 0;
}