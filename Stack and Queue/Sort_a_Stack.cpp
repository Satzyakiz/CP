// Given a stack, the task is to sort it such that the
// top of the stack has the greatest element.
// Source: GFG


void SortedStack :: sort()
{
   //Your code here
  priority_queue<int,vector<int>,greater<int>> minHeap;
  while(!s.empty()){
      minHeap.push(s.top());
      s.pop();
  }
  while(!minHeap.empty()){
      s.push(minHeap.top());
      minHeap.pop();
  }
}
