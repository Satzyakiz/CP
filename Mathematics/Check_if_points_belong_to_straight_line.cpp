// Problem:
// Check If It Is a Straight Line
// You are given an array coordinates, coordinates[i] = [x, y], where [x, y]
// represents the coordinate of a point. Check if these points make a straight line in the XY plane.
//
// Approach
// The target is to find whether a set of points belong to a straight line.
// We will use the concept of slope.
// we know, slope = (y2-y1)/(x2-x1).
// But if x1 = x2, then there would be DivisionByZero exception.
// So we will try to find using multiplication property.
//
// Slope1 = Slope2
// => (y2-y1)1/(x2-x1)1 = (y2-y1)2/(x2-x1)2; //1 and 2 indicates slope no
// => (y2-y1)1 * (x2-x1)2 =  (y2-y1)2 * (x2-x1)1; //This property would hold.

// function:
bool checkStraightLine(vector<vector<int>>& coord) {
    if(coord.size() < 2) return true; // If one point is there, it must be a part of straight line
    double yDiff = (coord[1][1] - coord[0][1]);
    double xDiff = (coord[1][0] - coord[0][0]);

    for(int i=2; i<coord.size(); i++){

        double temp_yDiff = (coord[i][1] - coord[i-1][1]);
        double temp_xDiff = (coord[i][0] - coord[i-1][0]);

        if(xDiff * temp_yDiff  != yDiff * temp_xDiff)
            return false;
    }
    return true;
}
