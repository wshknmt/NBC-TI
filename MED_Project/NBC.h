#ifndef NBC_H
#define NBC_H

#include "Point.h"
#include <deque>

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
	double countRealDistanceToPoint(int point, int neigh);
	double getPointX(int point);
	double getPointY(int point);
	double getPointDist(int point);
	void countReverseNeighbors(int point);
	void incrementReverseCounter(int point);
private:
	double minX = std::numeric_limits<double>::max(); 
	double minY = std::numeric_limits<double>::max();
	std::vector <Point> points;
	std::deque <int> seeds;
	//std::vector <int> allSeeds;
	int k;
};

#endif // NBC_H

