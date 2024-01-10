#include "Point.h"

void Point::setX(double x) {
    this->x = x;
}

double Point::getX() {
    return x;
}

void Point::setY(double y) {
    this->y = y;
}

double Point::getY() {
    return y;
}

void Point::setDistance(double dist) {
    this->distance = dist;
}

double Point::getDistance() {
    return distance;
}

double Point::getEpsilon() {
    return epsilon;
}

void Point::setLabel(int label) {
    this->label = label;
}

int Point::getLabel() {
    return label;
}

void Point::setIndex(int index) {
    this->index = index;
}

void Point::setMinChecked(int value) {
    minChecked = value;
}

int Point::getMinChecked() {
    return minChecked;
}

void Point::setMaxChecked(int value) {
    maxChecked = value;
}

int Point::getMaxChecked() {
    return maxChecked;
}

double Point::getNdf() {
    return ndf;
}

void Point::incrementMaxChecked() {
    maxChecked++;
}

void Point::decrementMinChecked() {
    minChecked--;
}

void Point::incrementReverseCounter() {
    reverseCounter++;
}

Neighbor Point::getNeighbor(int idx) {
    return neighbors[idx];
}

void Point::addNeighbor(Neighbor neigh) {
    neighbors.push_back(neigh);
}

int Point::getNeighborsSize() {
    return neighbors.size();
}

void Point::print() {
    std::cout << "index: " << index << " , x: " << x << " , y: " << y << " , distance: " << distance <<" , label: "<<label << " ndf: "<<ndf <<std::endl;
    std::cout << "neigbours of point are: ";
    for (int j = 0; j < neighbors.size(); j++) {
        std::cout << neighbors[j].index << " , ";
    }
    std::cout << std::endl;
}

void Point::countEpsilon() {
    std::vector <double> values;
    for (int i = 0; i < neighbors.size(); i++)
        values.push_back(neighbors[i].realDistance);
    auto maxIter = std::max_element(values.begin(), values.end());
    epsilon = *maxIter;
}

void Point::replaceNeighbor(Neighbor neigh) {
    std::sort(neighbors.begin(), neighbors.end());
    neighbors.pop_back();
    neighbors.push_back(neigh);
}

void Point::countNdf() {
    ndf = 1.0 * reverseCounter / neighbors.size();
}

bool Point::operator<(const Point& other) const {
    return distance < other.distance;
}
