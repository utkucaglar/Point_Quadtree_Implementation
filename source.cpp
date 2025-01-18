
// Utku Caglar \ 32579 CS300-A HW2 source.cpp

#include "Quadtree.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

// Function to read the cities from the file and store them in the Quadtree.
void readCitiesFile(const string& filename, Quadtree& quadtree) {
    ifstream file(filename);
    if (!file.is_open()) { // Check if the file is opened.
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    double maxX, maxY;
    file >> maxX >> maxY;
    quadtree = Quadtree(0, 0, maxX, maxY); // Initializing the map.

    string name;
    double x, y;
    while (file >> name >> x >> y) {
        // Insert each city into the Quadtree.
        quadtree.insert(Point(name, x, y));
    }
}

// Function to read and process the queries from the file.
void readQueriesFile(const string& filename, Quadtree& quadtree) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    cout << "Then, given the following queries.txt file:" << endl;
    string line;
    vector<string> queries;

    // Collect and print all queries.
    while (getline(file, line)) {
        queries.push_back(line);
        cout << line << endl;
    }
    cout << endl;

    // Process each query using a traditional for loop.
    for (int i = 0; i < queries.size(); i++) {
        stringstream ss(queries[i]);
        double x, y, radius;
        char comma;
        ss >> x >> comma >> y >> comma >> radius;

        vector<string> foundCities;
        vector<string> visitedCities;
        // Perform the query on the Quadtree.
        quadtree.query(x, y, radius, foundCities, visitedCities);

        // Output found cities.
        if (foundCities.empty()) {
            cout << "<None>" << endl;
        } else {
            for (int j = 0; j < foundCities.size(); j++) {
                if (j > 0) cout << ", ";
                cout << foundCities[j];
            }
            cout << endl;
        }

        // Output visited cities.
        for (int j = 0; j < visitedCities.size(); j++) {
            if (j > 0) cout << ", ";
            cout << visitedCities[j];
        }
        cout << endl << endl;
    }
}

// Main function.
int main() {
    Quadtree quadtree(0, 0, 0, 0);
    // Read and insert cities from the file.
    readCitiesFile("cities.txt", quadtree);
    // Print the cities in the Quadtree in order.
    quadtree.pretty_print();
    cout << endl;
    // Read and process queries from the file.
    readQueriesFile("queries0.txt", quadtree);
    return 0;
}
