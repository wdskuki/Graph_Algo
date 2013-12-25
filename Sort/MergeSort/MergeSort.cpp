#include <iostream>
using namespace std;
#define MAXIMUM 9999999
#define MINIMUM (-1)

void merge(int *a ,int beg, int mid, int end){
	int leftLen = mid-beg+1;
	int rightLen = end-mid;
	int *left = new int[leftLen+1];
	int *right = new int[rightLen+1];

	for(int i = beg; i <= mid; i++)
		left[i-beg] = a[i];
	left[leftLen] = MAXIMUM;
	for(int i = mid+1; i <= end; i++)
		right[i-mid-1] = a[i];
	right[rightLen] = MAXIMUM;

	int leftIndex = 0;
	int rightIndex = 0;
	for(int i = beg; i <= end; i++){
		if(left[leftIndex] <= right[rightIndex]){
			a[i] = left[leftIndex];
			leftIndex++;
		}else{
			a[i] = right[rightIndex];
			rightIndex++;
		}
	}

	delete []left;
	delete []right;
}

void merge_sort(int *a, int beg, int end){
	if(beg >= end)
		return;
	int mid = (beg+end)/2;
	merge_sort(a, beg, mid);
	merge_sort(a, mid+1, end);
	merge(a, beg, mid, end);
}


void print(int *a, int n){
	for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n){
		int *a = new int[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		merge_sort(a, 0, n-1);
		print(a, n);
		delete []a;
	}
	return 0;
}