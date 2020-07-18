
// A bus has n stops numbered from 0 to n - 1 that form a circle.
// We know the distance between all pairs of neighboring stops where distance[i]
// is the distance between the stops number i and (i + 1) % n.
//
// The bus goes along both directions i.e. clockwise and counterclockwise.
//
// Return the shortest distance between the given start and destination stops.

// Input: distance = [1,2,3,4], start = 0, destination = 2
// Output: 3
// Explanation: Distance between 0 and 2 is 3 or 7, minimum is 3.
//
// Input: distance = [1,2,3,4], start = 0, destination = 3
// Output: 4
// Explanation: Distance between 0 and 3 is 6 or 4, minimum is 4.

int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
    int clock = 0, anti = 0, n =distance.size();;
    int i = start;
    while(i != destination){
        clock += distance[i];
        i = (i+1)%n;
    }
    i = (start-1+n)%n;
    anti += distance[i];
    while(i != destination){
        i = (i-1+n)%n;
        anti += distance[i];
    }

    return min(anti,clock);
}
