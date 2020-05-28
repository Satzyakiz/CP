// Given n non-negative integers representing the histogram's
// bar height where the width of each bar is 1,
// find the area of largest rectangle in the histogram.
// Input: [2,1,5,6,2,3]
// Output: 10

// if n is the total index of elements, -1 and n+1 is the pseudo indexes

vector<int> nearestShortestLeft(vector<int> heights){
  vector<int> nsl;
  stack<int> s;
  int pseudo = -1;
  int n = heights.size();
  for(int i=0; i<n; i++){
    if(s.empty())
      nsl.emplace_back(pseudo);
    else if(!s.empty() && heights[s.top()] < heights[i])
      nsl.emplace_back(s.top());
    else if(!s.empty() && heights[s.top()] >= heights[i]){
      while(!s.empty() && heights[s.top()] >= heights[i])
        s.pop();
      if(s.size() == 0) nsl.emplace_back(pseudo);
      else nsl.emplace_back(s.top());
    }
    s.push(i);
  }
  return nsl;
}
vector<int> nearestShortestRight(vector<int> heights){
  vector<int> nsr;
  stack<int> s;
  int n = heights.size();
  int pseudo = n;
  for(int i=n-1; i>=0; i--){
    if(s.empty())
      nsr.emplace_back(pseudo);
    else if(!s.empty() && heights[s.top()] < heights[i])
      nsr.emplace_back(s.top());
    else if(!s.empty() && heights[s.top()] >= heights[i]){
      while(!s.empty() && heights[s.top()] >= heights[i])
        s.pop();
      if(s.size() == 0) nsr.emplace_back(pseudo);
      else nsr.emplace_back(s.top());
    }
    s.push(i);
  }
  reverse(nsr.begin(),nsr.end());
  return nsr;
}
int largestAreaInHistogram(vector<int> heights){
  if(heights.size() == 0) return 0;
  if(heights.size() == 1) return heights[0];
  vector<int> NSL, NSR;
  NSL = nearestShortestLeft(heights);
  NSR = nearestShortestRight(heights);
  int n = heights.size();
  vector<int> area(n);
  for(int i=0; i<n; i++){
    area[i] = (NSR[i]-NSL[i]-1)*heights[i];
  }
  return *max_element(area.begin(),area.end());
}
