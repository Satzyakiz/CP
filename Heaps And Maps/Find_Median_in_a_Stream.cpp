// Given an input stream of N integers. The task is to insert these numbers
// into a new stream and find the median of the stream formed by each insertion
// of X to the new stream.
//
// Input:
// 4
// 5
// 15
// 1
// 3
// Output:
// 5
// 10
// 5
// 4

#include<bits/stdc++.h>
using namespace std;

priority_queue<int>leftHalf; // max heap
priority_queue<int,vector<int>,greater<int>>rightHalf; // min heap

void addToHeap(int num)
{
    if(leftHalf.empty()||num<leftHalf.top())
     leftHalf.push(num);
    else
    rightHalf.push(num);
}

void rebalance()
{
    if(leftHalf.size()-rightHalf.size()==0)
    {
        // do nothing
        return;
    }
    else if(leftHalf.size()>rightHalf.size()) // left heap is bigger
    {
        rightHalf.push(leftHalf.top());
        leftHalf.pop();
    }
    else // right heap is bigger
    {
        leftHalf.push(rightHalf.top());
        rightHalf.pop();
    }
}

int getMedian()
{
    if(leftHalf.size()==rightHalf.size())
    {
        return (leftHalf.top()+rightHalf.top())/2;
    }
    else if(leftHalf.size()>rightHalf.size())
    {
        return leftHalf.top();
    }
    return rightHalf.top();
}
int main()
{
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
	    addToHeap(arr[i]);
	    rebalance();
	    cout<<getMedian()<<endl;
	}
	return 0;
}
