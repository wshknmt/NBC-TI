#ifndef NBC_H
#define NBC_H

#include "Point.h"
#include <deque>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

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
	void findNeighbors();
	void findNeighborsOfPoint(int point);
	void countNdf();
	void putLabelsOn();
	double getDistanceNextPoint(int point);
	double getDistancePrevPoint(int point);
	double countRealDistanceToPoint(int point, int neigh);
	void countReverseNeighbors(int point);
	void incrementReverseCounter(int point);
	void printMaxLabel();
private:
	double minX = std::numeric_limits<double>::max(); 
	double minY = std::numeric_limits<double>::max();
	std::vector <Point> points;
	std::deque <int> seeds;
	int k;
	int groupIndex;
};

#endif // NBC_H

