//Divide and Conquer
// A city's skyline is the outer contour of the silhouette 
// formed by all the buildings in that city when viewed from a distance.
// Now suppose you are given the locations and height of all the buildings
// as shown on a cityscape photo (Figure A), write a program to output the
// skyline formed by these buildings collectively (Figure B).


void append(vector<vector<int>> &arr, int x,int h){
        int n = arr.size();
        if(n > 0 && arr.back()[1] == h)
            return;
        if(n > 0 && arr.back()[0] == x){
            int maxh = arr.back()[1];
            while(arr.size() > 0 && arr.back()[0] == x){
                maxh = max(maxh, h);
                arr.pop_back();
            }
            arr.push_back({x, maxh});
            return;
        }
        arr.push_back({x,h});
    }
    vector<vector<int>> mergeSkylines(vector<vector<int>> left, vector<vector<int>> right){
        int m = left.size(), n = right.size();
        int i = 0 , j = 0;
        vector<vector<int>> skyline;
        int x1,x2, h1 = 0, h2 = 0, maxh = 0;
        while(i < m && j < n){
            if(left[i][0] < right[j][0]){
                x1 = left[i][0];
                h1 = left[i][1];
                maxh = max(h1,h2);
                append(skyline, x1, maxh);
                i++;
            }else if(left[i][0] > right[j][0]){
                x2 = right[j][0];
                h2 = right[j][1];
                maxh = max(h1,h2);
                append(skyline, x2, maxh);
                j++;
            }else{
                x1 = left[i][0];
                h1 = left[i][1];
                h2 = right[j][1];
                maxh = max(h1,h2);
                append(skyline, x1, maxh);
                i++;
                j++;
            }

        }

        while(i < m){
            append(skyline, left[i][0], left[i][1]);
            i++;
        }

        while(j < n){
            append(skyline, right[j][0], right[j][1]);
            j++;
        }

        return skyline;
    }
    vector<vector<int>> helper(vector<vector<int>>& buildings, int low, int high){
        vector<vector<int>> ans;
        if(low > high)
            return ans;
        if(low == high){
            int x = buildings[low][0], y = buildings[low][1], h = buildings[low][2];
            ans.push_back({x,h});
            ans.push_back({y,0});
            return ans;
        }
        int mid = (low + high)/2;
        vector<vector<int>> left = helper(buildings, low, mid);
        vector<vector<int>> right = helper(buildings, mid+1, high);
        ans = mergeSkylines(left,right);
        return ans;
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        return helper(buildings, 0, buildings.size()-1);
    }
