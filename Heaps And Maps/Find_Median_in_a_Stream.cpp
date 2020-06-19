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



//Leetcode:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    void addNum(int num) {
        if(left.empty() || (num < left.top()))
            left.push(num);
        else
            right.push(num);

        if(left.size() > (right.size()+1)){
            right.push(left.top());
            left.pop();
        }
        else if(left.size()+1 < right.size())
        {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if(left.size() == right.size())
            return left.empty() ? 0 : ((left.top()+right.top())/2.0);
        else
            return (left.size() > right.size()) ? left.top() : right.top();
    }
