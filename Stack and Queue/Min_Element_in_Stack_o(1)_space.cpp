//Solution in O(1) space

//Whenever we get a new minElement, we insert :
  // 2  * newElement - minElement
// When we pop the minElement, we change minElement to:
  // minElemnt = 2 * minElement - s.top();
// Example:
// 1) Insert 5
//     Min : 5
// 2) Insert 1:
//     stack-> insert: 2*1-5: -3 //2  * newElement - minElement
//     Min: 1
// 3) Pop():
//     t=s.top(); s.pop();
//     Min: 2 * 1 - (-3): 5 //minElemnt = 2 * minElement - s.top();

int minElement;
stack<int> s;
MinStack::MinStack() {
    while(!s.empty())
        s.pop();
    minElement = 0;
}

void MinStack::push(int x) {
    if(s.empty()){
        minElement = x;
        s.push(x);
        return;
    }
    if(x < minElement){
        s.push(2*x - minElement);
        minElement = x;
    }
    else{
        s.push(x);
    }
}

void MinStack::pop() {
    if(s.empty())
        return;
    int t = s.top();
    s.pop();
    if(t < minElement){
        minElement = 2 * minElement - t;
    }
}

int MinStack::top() {
    if(s.empty())
        return -1;
    if(s.top() < minElement)
        return minElement;
    else
        return s.top();
}

int MinStack::getMin() {
    if(s.empty())
        return -1;
    return minElement;
}
