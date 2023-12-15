#ifndef NBC_H
#define NBC_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>

struct Point {
	int index;
	double x;
	double y;
	double distance;
	int label;

	bool operator<(const Point& other) const {
		return distance < other.distance;
	}
};

class NBC
{
public:
	NBC(std::string path);
	void openDataset(std::string path);
	void getPoints();
	void countDistance();
	double distanceOfTwoPoints(double x1, double y1, double x2, double y2);
	void sortPoints();
private:
	double minX = std::numeric_limits<double>::max(); 
	double minY = std::numeric_limits<double>::max();
	std::vector <Point> points;


};

#endif // NBC_H

