#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

// Structure to represent a point
struct Point {
    int x, y;
};

// Function to calculate the cross product of three points
int cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// Function to find the distance between two points
double distance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

// Function to find the point with the minimum x-coordinate
Point find_min_x(vector<Point>& points) {
    Point min_point = points[0];
    for (int i = 1; i < points.size(); i++) {
        if (points[i].x < min_point.x) {
            min_point = points[i];
        }
    }
    return min_point;
}

// Function to find the point with the maximum x-coordinate
Point find_max_x(vector<Point>& points) {
    Point max_point = points[0];
    for (int i = 1; i < points.size(); i++) {
        if (points[i].x > max_point.x) {
            max_point = points[i];
        }
    }
    return max_point;
}

// Recursive function to find the convex hull
void quick_hull_recursive(vector<Point>& points, Point p1, Point p2, vector<Point>& hull) {
    if (points.empty()) return;

    int max_dist_index = -1;
    double max_dist = 0;

    for (int i = 0; i < points.size(); i++) {
        double dist = abs(cross_product(p1, p2, points[i]));
        if (dist > max_dist) {
            max_dist = dist;
            max_dist_index = i;
        }
    }

    if (max_dist_index == -1) return; // No points on this side

    Point p_max = points[max_dist_index];

    vector<Point> left_points;
    vector<Point> right_points;

    for (int i = 0; i < points.size(); i++) {
        if (cross_product(p1, p_max, points[i]) > 0) {
            left_points.push_back(points[i]);
        }
        if (cross_product(p_max, p2, points[i]) > 0) {
            right_points.push_back(points[i]);
        }
    }

    quick_hull_recursive(left_points, p1, p_max, hull);
    hull.push_back(p_max); // Add p_max to the hull
    quick_hull_recursive(right_points, p_max, p2, hull);
}

// Function to find the convex hull of a set of points
vector<Point> quick_hull(vector<Point>& points) {
    if (points.size() < 3) return points; // Handle cases with less than 3 points

    Point p_min = find_min_x(points);
    Point p_max = find_max_x(points);

    vector<Point> hull;
    hull.push_back(p_min);
    hull.push_back(p_max);

    vector<Point> left_points;
    vector<Point> right_points;

    for (int i = 0; i < points.size(); i++) {
        if (cross_product(p_min, p_max, points[i]) > 0) {
            left_points.push_back(points[i]);
        } else if (cross_product(p_min, p_max, points[i]) < 0) {
            right_points.push_back(points[i]);
        }
    }

    quick_hull_recursive(left_points, p_min, p_max, hull);
    quick_hull_recursive(right_points, p_max, p_min, hull);

    return hull;
}

int main() {
    srand(time(0));

    vector<Point> points;
    int num_points = 100;

    for (int i = 0; i < num_points; ++i) {
        Point p;
        p.x = rand() % 101;
        p.y = rand() % 101;
        points.push_back(p);
    }

    vector<Point> hull = quick_hull(points);

    // --- CSV Output for all points ---
    string all_points_filename = "all_points_data.csv";
    ofstream all_points_outfile(all_points_filename);

    if (all_points_outfile.is_open()) {
        all_points_outfile << "x,y" << endl; // Header
        for (const auto& p : points) {
            all_points_outfile << p.x << "," << p.y << endl;
        }
        all_points_outfile.close();
        cout << "All points data written to " << all_points_filename << endl;
    } else {
        cerr << "Unable to open file for writing (all points)." << endl;
        return 1;
    }


    // --- CSV Output for convex hull points ---
    string convex_hull_filename = "convex_hull_data.csv";
    ofstream convex_hull_outfile(convex_hull_filename);

    if (convex_hull_outfile.is_open()) {
        convex_hull_outfile << "x,y,hull" << endl;
        for (const auto& p : points) {
            bool is_hull_point = false;
            for (const auto& h : hull) {
                if (p.x == h.x && p.y == h.y) {
                    is_hull_point = true;
                    break;
                }
            }
            convex_hull_outfile << p.x << "," << p.y << "," << is_hull_point << endl;
        }
        convex_hull_outfile.close();
        cout << "Convex hull data written to " << convex_hull_filename << endl;
    } else {
        cerr << "Unable to open file for writing (convex hull)." << endl;
        return 1;
    }


    cout << "Convex Hull Points:" << endl;
    for (const auto& p : hull) {
        cout << "(" << p.x << ", " << p.y << ")" << endl;
    }

    return 0;
}