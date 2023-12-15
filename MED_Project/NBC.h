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
	double epsilon;
	int label;
	int minChecked;
	int maxChecked;
	std::vector <int> neighbors;

	bool operator<(const Point& other) const {
		return distance < other.distance;
	}
};

class NBC
{
public:
	NBC(std::string path, int k);
	void openDataset(std::string path);
	void getPoints();
	void countDistance();
	double distanceOfTwoPoints(double x1, double y1, double x2, double y2);
	void sortPoints();
	void setIndex();
	void findNeighbors(int point);
	double getDistanceNextPoint(int point);
	double getDistancePrevPoint(int point);
	void countEpsilon(int point);
	double countRealDistanceToPoint(int point, int neigh);
	double getPointX(int point);
	double getPointY(int point);
private:
	double minX = std::numeric_limits<double>::max(); 
	double minY = std::numeric_limits<double>::max();
	std::vector <Point> points;
	//std::vector <std::vector<int> > fields;
	int k;
};

#endif // NBC_H

