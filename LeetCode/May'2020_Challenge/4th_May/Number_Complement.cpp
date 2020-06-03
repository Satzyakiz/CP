
// Example 1:
//
// Input: num = 5
// Output: 2
// Explanation: The binary representation of 5 is 101
// (no leading zero bits), and its complement is 010. So you need to output 2.
// Example 2:
//
// Input: num = 1
// Output: 0

int findComplement(int num) {
        vector<int> arr;
        while(num){
            arr.emplace_back(num % 2);
            num /= 2;
        }
        int no = 0;
        for(int i=0; i<arr.size(); i++){
            cout<<arr[i];
            if(arr[i] == 0){
                no += pow(2,i);
            }
        }
        return no;
    }
