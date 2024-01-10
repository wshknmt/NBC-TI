#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <vector>
#include <algorithm>

struct Neighbor {
    int index;
    double realDistance;

    bool operator<(const Neighbor& other) const {
        return realDistance < other.realDistance;
    }
};

class Point
{
public:
    void setX(double x);
    double getX();
    void setY(double y);
    double getY();
    void setDistance(double dist);
    double getDistance();
    void setEpsilon(double eps);
    double getEpsilon();
    void setLabel(int label);
    int getLabel();
    void setIndex(int index);
    int getIndex();
    void setMinChecked(int value);
    int getMinChecked();
    void setMaxChecked(int value);
    int getMaxChecked();
    int getReverseCounter();
    void setNdf(double ndf);
    double getNdf();
    void incrementMaxChecked();
    void decrementMinChecked();
    void incrementReverseCounter();
    Neighbor getNeighbor(int idx);
    void addNeighbor(Neighbor point);
    std::vector <Neighbor> getNeighbors();
    int getNeighborsSize();
    void print();
    void countEpsilon();
    void replaceNeighbor(Neighbor neigh);
    void countNdf();

    bool operator<(const Point& other) const;

private:
    int index;
    double x;
    double y;
    double distance;
    double epsilon;
    int label = 0;
    int minChecked;
    int maxChecked;
    std::vector <Neighbor> neighbors;
    int reverseCounter = 0;
    double ndf;


};

#endif // POINT_H

