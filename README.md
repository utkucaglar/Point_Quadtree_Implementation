# Point Quadtree Implementation

## Overview
This project implements a **Point Quadtree**, a spatial data structure for storing and querying 2D points efficiently. The program constructs a quadtree for a given list of cities and processes queries to find all cities within a specified radius of a given point. This project demonstrates fundamental concepts of data structures and recursive algorithms for spatial querying and efficient data management.

---

## Features
- **Quadtree Construction**:
  - Builds a quadtree from a list of cities specified in `cities.txt`.
  - Each city is stored as a 2D point with coordinates and a name.
- **Pretty Printing**:
  - Recursively traverses the quadtree and prints the cities in quadrant order: SE, SW, NE, NW.
- **Query Processing**:
  - Processes queries from `queries.txt` to find cities within a specified radius of a point.
  - Outputs visited cities during the query process, showing the traversal path.

---

## Code Files

### **Quadtree.h**
This header file defines the `Quadtree` class and its supporting structures, including:
- The `Point` struct to store city data (name, x-coordinate, y-coordinate).
- The `Node` struct representing individual nodes in the quadtree, each containing a `Point` and pointers to child nodes (SE, SW, NE, NW).
- The `Quadtree` class, which includes public methods for:
  - Inserting points into the quadtree.
  - Pretty printing the quadtree structure.
  - Querying points within a specified radius.

### **Quadtree.cpp**
This file contains the implementation of the `Quadtree` class:
- **Insertion**:
  - Adds points to the correct quadrant based on their coordinates relative to the current node.
  - Dynamically allocates child nodes when necessary.
- **Pretty Printing**:
  - Recursively traverses the tree in quadrant order (SE, SW, NE, NW) and prints the names of cities stored in the nodes.
- **Querying**:
  - Searches for points within a given radius by checking node boundaries and traversing relevant quadrants.
  - Uses helper methods like `circleIntersectsBox` to optimize search performance.

### **source.cpp**
The main program file that integrates all functionality:
- **Reading Input Files**:
  - Parses `cities.txt` to construct the quadtree by inserting cities.
  - Reads `queries.txt` to process spatial queries on the quadtree.
- **Program Flow**:
  - Constructs the quadtree and prints its structure.
  - Processes each query and outputs the cities found within the radius as well as the traversal path.

---

## Input Files
### `cities.txt`
This file defines the 2D space and lists the cities to be inserted into the quadtree.
```
<maxX> <maxY>
<city name> <x coordinate> <y coordinate>
```
Example:
```
100 100
Chicago 35 42
Mobile 52 10
Toronto 62 77
Buffalo 82 65
Denver 5 45
Omaha 27 35
Atlanta 85 15
Miami 90 5
Seattle 34 0
Houston 62 67
Austin 73 72
Memphis 35 23
Columbia 86 15
Richmond 87 15
Detroit 42 42
Tucson 35 35
Nowhere 98 99
```

### `queries0.txt`
This file contains queries in the format:
```
<x coordinate>, <y coordinate>, <radius>
```
Example:
```
83, 10, 8
25, 33, 11
42, 83, 2
82, 35, 34
62, 77, 24
```

---

## Sample Execution

### Quadtree Construction
Given the following `cities.txt` file:
```
100 100
Chicago 35 42
Mobile 52 10
Toronto 62 77
Buffalo 82 65
Denver 5 45
Omaha 27 35
Atlanta 85 15
Miami 90 5
Seattle 34 0
Houston 62 67
Austin 73 72
Memphis 35 23
Columbia 86 15
Richmond 87 15
Detroit 42 42
Tucson 35 35
Nowhere 98 99
```

The program constructs a quadtree and outputs its contents in quadrant order:
```
Chicago
Mobile
Miami
Atlanta
Columbia
Richmond
Memphis
Tucson
Omaha
Seattle
Toronto
Buffalo
Houston
Austin
Detroit
Nowhere
Denver
```

### Query Processing
Given the following `queries0.txt` file:
```
83, 10, 8
25, 33, 11
42, 83, 2
82, 35, 34
62, 77, 24
```

The program processes each query and produces the following output:

1. **Query**: `83, 10, 8`
   - **Found Cities**: `Atlanta, Columbia, Richmond`
   - **Visited Cities**: `Chicago, Mobile, Miami, Atlanta, Columbia, Richmond`

2. **Query**: `25, 33, 11`
   - **Found Cities**: `Tucson, Omaha`
   - **Visited Cities**: `Chicago, Mobile, Memphis, Tucson, Omaha, Seattle, Denver`

3. **Query**: `42, 83, 2`
   - **Found Cities**: `<None>`
   - **Visited Cities**: `Chicago, Toronto`

4. **Query**: `82, 35, 34`
   - **Found Cities**: `Miami, Atlanta, Columbia, Richmond, Buffalo`
   - **Visited Cities**: `Chicago, Mobile, Miami, Atlanta, Columbia, Richmond, Memphis, Tucson, Toronto, Buffalo, Houston, Austin, Detroit`

5. **Query**: `62, 77, 24`
   - **Found Cities**: `Toronto, Buffalo, Houston, Austin`
   - **Visited Cities**: `Chicago, Toronto, Buffalo, Houston, Austin, Detroit, Nowhere`

---

## How to Run
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/point-quadtree.git
   ```
2. Compile the program:
   ```bash
   g++ -o main source.cpp Quadtree.cpp
   ```
3. Run the executable:
   ```bash
   ./main
   ```
4. Ensure the `cities.txt` and `queries0.txt` files are in the same directory as the executable.

---

## Technologies Used
- **Programming Language**: C++
- **Data Structures**: Point Quadtree
- **Algorithms**: Recursive traversal, spatial querying

---

## License
This project is licensed under the MIT License.
