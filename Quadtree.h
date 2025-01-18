
// Utku Caglar \ 32579 CS300-A HW2 Quadtree.h

#ifndef QUADTREE_H
#define QUADTREE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a point with a name and coordinates.
struct Point {
    string name;
    double x, y;
    Point(string name, double x, double y) : name(name), x(x), y(y) {}
};

// Class to represent a Quadtree.
class Quadtree {
public:
    // Nested class to represent a node in the Quadtree.
    struct Node {
        Point point; // The point contained in this node.
        double minX, minY, maxX, maxY; // Boundaries of the node.
        Node* SE; // Pointer to the SE child.
        Node* SW; // Pointer to the SW child.
        Node* NE; // Pointer to the NE child.
        Node* NW; // Pointer to the NW child.

        // Constructor for initializing a node.
        Node(Point p, double minX, double minY, double maxX, double maxY)
                : point(p), minX(minX), minY(minY), maxX(maxX), maxY(maxY),
                  SE(nullptr), SW(nullptr), NE(nullptr), NW(nullptr) {}
    };

    // Constructor to initialize the Quadtree with given boundaries.
    Quadtree(double minX, double minY, double maxX, double maxY)
            : root(nullptr), minX(minX), minY(minY), maxX(maxX), maxY(maxY) {}

    // Function to insert a point into the Quadtree.
    void insert(const Point& point);

    // Function to pretty print the Quadtree in order.
    void pretty_print() const;

    // Function to perform a query on the Quadtree.
    void query(double x, double y, double radius, vector<string>& foundCities, vector<string>& visitedCities) const;

private:
    Node* root; // Root of the Quadtree.
    double minX, minY, maxX, maxY; // Boundaries of the entire Quadtree.

    // Helper function to insert a point into a specific node.
    void insert(Node* node, const Point& point);

    // Helper function to pretty print a node in the Quadtree.
    void pretty_print(Node* node) const;

    // Helper function to perform a query on a specific node.
    void query(Node* node, double x, double y, double radius, vector<string>& foundCities, vector<string>& visitedCities) const;

    // Helper function to check if a circle intersects a bounding box.
    bool circleIntersectsBox(double cx, double cy, double radius, double minX, double minY, double maxX, double maxY) const;
};

#endif // QUADTREE_H
