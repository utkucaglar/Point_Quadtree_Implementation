
// Utku Caglar \ 32579 CS300-A HW2 Quadtree.cpp

#include "Quadtree.h"
#include <cmath>
using namespace std;

// Function to insert a point into the Quadtree.
void Quadtree::insert(const Point& point) {
    if (!root) {
        // Create the root node if it doesn't exist.
        root = new Node(point, minX, minY, maxX, maxY);
        return;
    }
    // Insert the point into the appropriate location.
    insert(root, point);
}

// Helper function to insert a point into a specific node.
void Quadtree::insert(Node* node, const Point& point) {
    if (point.x >= node->point.x && point.y >= node->point.y) {  // NE quadrant.
        if (!node->NE) {
            node->NE = new Node(point, node->point.x, node->point.y, node->maxX, node->maxY);
        } else {
            insert(node->NE, point);
        }
    } else if (point.x < node->point.x && point.y >= node->point.y) {  // NW quadrant.
        if (!node->NW) {
            node->NW = new Node(point, node->minX, node->point.y, node->point.x, node->maxY);
        } else {
            insert(node->NW, point);
        }
    } else if (point.x >= node->point.x && point.y < node->point.y) {  // SE quadrant.
        if (!node->SE) {
            node->SE = new Node(point, node->point.x, node->minY, node->maxX, node->point.y);
        } else {
            insert(node->SE, point);
        }
    } else {  // SW quadrant.
        if (!node->SW) {
            node->SW = new Node(point, node->minX, node->minY, node->point.x, node->point.y);
        } else {
            insert(node->SW, point);
        }
    }
}

// Function to pretty print the Quadtree in order.
void Quadtree::pretty_print() const {
    pretty_print(root);
}

// Helper function to pretty print a node in the Quadtree.
void Quadtree::pretty_print(Node* node) const {
    if (!node) return;

    // Print the current city's name.
    cout << node->point.name << endl;

    // Traverse the quadrants in the order: SE, SW, NE, NW.
    pretty_print(node->SE);
    pretty_print(node->SW);
    pretty_print(node->NE);
    pretty_print(node->NW);
}

// Helper function to check if the query circle intersects a bounding box.
bool Quadtree::circleIntersectsBox(double cx, double cy, double radius, double minX, double minY, double maxX, double maxY) const {
    double closestX = max(minX, min(cx, maxX));
    double closestY = max(minY, min(cy, maxY));
    double distanceSquared = (cx - closestX) * (cx - closestX) + (cy - closestY) * (cy - closestY);
    return distanceSquared <= (radius * radius);
}

// Function to perform a query on the Quadtree.
void Quadtree::query(double x, double y, double radius, vector<string>& foundCities, vector<string>& visitedCities) const {
    query(root, x, y, radius, foundCities, visitedCities);
}

// Helper function to perform a query on a specific node.
void Quadtree::query(Node* node, double x, double y, double radius, vector<string>& foundCities, vector<string>& visitedCities) const {
    if (!node) return;

    // Mark the current city as visited.
    visitedCities.push_back(node->point.name);

    // Check if the current point is within the radius or not.
    double dist = sqrt(pow(node->point.x - x, 2) + pow(node->point.y - y, 2));
    if (dist <= radius) {
        foundCities.push_back(node->point.name);
    }

    // Use the circleIntersectsBox function to determine whether to visit each quadrant or not.
    if (node->SE && circleIntersectsBox(x, y, radius, node->point.x, node->minY, node->maxX, node->point.y)) {
        query(node->SE, x, y, radius, foundCities, visitedCities);
    }
    if (node->SW && circleIntersectsBox(x, y, radius, node->minX, node->minY, node->point.x, node->point.y)) {
        query(node->SW, x, y, radius, foundCities, visitedCities);
    }
    if (node->NE && circleIntersectsBox(x, y, radius, node->point.x, node->point.y, node->maxX, node->maxY)) {
        query(node->NE, x, y, radius, foundCities, visitedCities);
    }
    if (node->NW && circleIntersectsBox(x, y, radius, node->minX, node->point.y, node->point.x, node->maxY)) {
        query(node->NW, x, y, radius, foundCities, visitedCities);
    }
}
