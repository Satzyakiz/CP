

#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr,int n,int i){
	int largest = i, left = 2*i+1, right = 2*i+2;
	if(left < n && arr[left] > arr[largest]) largest = left;
	if(right < n && arr[right] > arr[largest]) largest = right;
	if(largest != i){
		swap(arr[i],arr[largest]);
		heapify(arr,n,largest);
	}
}
void buildheap(vector<int> &arr){
	int n = arr.size();
	for(int i=n/2-1; i>=0; i--){
		heapify(arr,n,i);
	}
}
void heapsort(vector<int> &arr){
	buildheap(arr);
	for(int i=arr.size()-1; i>=0; i--){
		swap(arr[i],arr[0]);
		heapify(arr,i,0);
	}
}
void solve(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) cin>>arr[i];
	heapsort(arr);
	for(int &x: arr) cout<<x<<" ";
	cout<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
