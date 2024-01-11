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
    NBC(std::string path, char delimiter, int k, bool TIEnabled);
    void openDataset(std::string path, char delimiter);
    void printPoints();
    void countDistance();
    double distanceOfTwoPoints(double x1, double y1, double x2, double y2);
    void sortPoints();
    void setIndex();
    void findNeighbors();
    void findNeighborsOfPoint(int point);
    void findNeighborsWithoutTI();
    void countNdf();
    void putLabelsOn();
    double getDistanceNextPoint(int point);
    double getDistancePrevPoint(int point);
    double countRealDistanceToPoint(int point, int neigh);
    void countReverseNeighbors(int point);
    void incrementReverseCounter(int point);
    std::vector <Point> getPoints();
    int getGroupIndex();
    double getMinX();
    double getMinY();
    double getMaxX();
    double getMaxY();
    double getQualityMeasureDaviesBouldin();
    double calculateAverageDistanceToCluster(int point, int groupNum);
    double getQualityMeasureSilhouette();
private:
    double minX = std::numeric_limits<double>::max();
    double minY = std::numeric_limits<double>::max();
    double maxX = 0;
    double maxY = 0;
    double NBCthreshold = 0.5;
    std::vector <Point> points;
    std::deque <int> seeds;
    int k;
    int groupIndex;
};

#endif // NBC_H

