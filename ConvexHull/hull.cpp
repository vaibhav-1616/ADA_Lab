#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Point {
    int x, y;

    // Needed to store Points in a set (ensures uniqueness)
    bool operator<(const Point& p) const {
        return (x < p.x) || (x == p.x && y < p.y);
    }
};

// Function to find the leftmost and rightmost points
void findExtremePoints(const vector<Point>& points, Point& leftmost, Point& rightmost) {
    leftmost = points[0];
    rightmost = points[0];

    for (const Point& p : points) {
        if (p.x < leftmost.x) leftmost = p;
        if (p.x > rightmost.x) rightmost = p;
    }
}

// Function to calculate the perpendicular distance of a point from a line
int distanceFromLine(Point A, Point B, Point P) {
    return abs((B.y - A.y) * P.x - (B.x - A.x) * P.y + B.x * A.y - B.y * A.x);
}

// Function to find the farthest point from a given line
Point findFarthestPoint(Point A, Point B, const vector<Point>& points) {
    int maxDist = -1;
    Point farthest = A; // Default in case no point is found

    for (const Point& P : points) {
        int dist = distanceFromLine(A, B, P);
        if (dist > maxDist) {
            maxDist = dist;
            farthest = P;
        }
    }
    return farthest;
}

// Function to determine if a point is on the left side of a line
bool isLeft(Point A, Point B, Point P) {
    return ((B.x - A.x) * (P.y - A.y) - (B.y - A.y) * (P.x - A.x)) > 0;
}

// Function to partition points based on their position relative to a line
vector<Point> partitionPoints(Point A, Point B, const vector<Point>& points) {
    vector<Point> subset;
    for (const Point& P : points) {
        if (isLeft(A, B, P)) {
            subset.push_back(P);
        }
    }
    return subset;
}

// Recursive function to compute the convex hull
void quickHullRecursive(Point A, Point B, vector<Point>& points, set<Point>& hull) {
    if (points.empty()) return;

    Point C = findFarthestPoint(A, B, points);
    hull.insert(C);

    vector<Point> leftSetAC = partitionPoints(A, C, points);
    vector<Point> leftSetCB = partitionPoints(C, B, points);

    quickHullRecursive(A, C, leftSetAC, hull);
    quickHullRecursive(C, B, leftSetCB, hull);
}

// Main function to compute QuickHull
vector<Point> quickHull(vector<Point>& points) {
    if (points.size() < 3) return points;  // Convex hull not possible

    set<Point> hull;
    Point leftmost, rightmost;
    findExtremePoints(points, leftmost, rightmost);

    hull.insert(leftmost);
    hull.insert(rightmost);

    vector<Point> leftSet = partitionPoints(leftmost, rightmost, points);
    vector<Point> rightSet = partitionPoints(rightmost, leftmost, points);

    quickHullRecursive(leftmost, rightmost, leftSet, hull);
    quickHullRecursive(rightmost, leftmost, rightSet, hull);

    return vector<Point>(hull.begin(), hull.end());
}

// Function to generate random points
vector<Point> generateRandomPoints(int numPoints, int minVal, int maxVal) {
    vector<Point> points;
    srand(time(0));

    for (int i = 0; i < numPoints; i++) {
        int x = minVal + rand() % (maxVal - minVal + 1);
        int y = minVal + rand() % (maxVal - minVal + 1);
        points.push_back({x, y});
    }

    return points;
}

// Function to write points to a CSV file
void writeToCSV(const string& filename, const vector<Point>& points, const vector<Point>& hull) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file!\n";
        return;
    }

    file << "x,y,type\n";  // Header
    for (const Point& p : points) {
        file << p.x << "," << p.y << ",point\n";
    }
    for (const Point& p : hull) {
        file << p.x << "," << p.y << ",hull\n";
    }

    file.close();
    cout << "Data written to " << filename << endl;
}

// Driver function
int main() {
    int numPoints = 100;
    vector<Point> points = generateRandomPoints(numPoints, 1, 100);

    vector<Point> hull = quickHull(points);

    writeToCSV("convex_hull.csv", points, hull);

    cout << "Convex Hull Points:\n";
    for (const Point& p : hull) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    return 0;
}
