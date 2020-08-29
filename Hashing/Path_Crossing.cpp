// Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing
// moving one unit north, south, east, or west, respectively. You start at the
// origin (0, 0) on a 2D plane and walk on the path specified by path.
//
// Return True if the path crosses itself at any point, that is, if at any
// time you are on a location you've previously visited. Return False otherwise.

// Input: path = "NES"
// Output: false
// Input: path = "NESWW"
// Output: true

bool isPathCrossing(string path) {
    unordered_map<int,unordered_map<int,bool>> um;
    int x = 0, y = 0;
    um[x][y] = true;
    for(char &c: path){
        if(c == 'N') y++;
        else if(c == 'S') y--;
        else if(c == 'E') x++;
        else if(c == 'W') x--;
        if(um[x][y])
            return true;
        else
            um[x][y] = true;
    }
    return false;
}
