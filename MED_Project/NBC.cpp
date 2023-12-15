#include "NBC.h"

NBC::NBC(std::string path, int k) {
    this->k = k;
    openDataset(path);
    countDistance();
    sortPoints();
    setIndex();
    for (int i = 0; i < points.size(); i++) {
        findNeighbors(i);
        countEpsilon(i);
    }
}

void NBC::openDataset(std::string path) {
	std::ifstream file(path);
    if (file.is_open()) {
        std::string line;
        int index = 0;

        while (getline(file, line)) {
            std::cout << line << std::endl;
            std::istringstream issLine(line);
            std::string x, y;
            std::getline(issLine, x, ':');
            std::getline(issLine, y, ':');
            Point point;
            point.x = stod(x);
            point.y = stod(y);
            //point.index = index;
            if (point.x < minX) minX = point.x;
            if (point.y < minY) minY = point.y;
            points.push_back(point);

            //index++;
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open the file." << std::endl;
    }
}

void NBC::getPoints() {
    for (int i = 0; i < points.size(); i++) {
        std::cout << "index: " << points[i].index << " , x: " << points[i].x << " , y: " << points[i].y <<" , distance: " << points[i].distance << std::endl;
        std::cout << "neigbours of point: " << i << " are: ";
        for (int j = 0; j < points[i].neighbors.size(); j++) {
            std::cout << points[i].neighbors[j] << " , ";
        }
        std::cout << std::endl;
    }
}

void NBC::countDistance() {
    for (int i = 0; i < points.size(); i++) {
        points[i].distance = distanceOfTwoPoints(points[i].x, points[i].y, minX, minY);
    }
}

double NBC::distanceOfTwoPoints(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

void NBC::sortPoints() {
    std::sort(points.begin(), points.end());
}

void NBC::setIndex() {
    for (int i = 0; i < points.size(); i++) {
        points[i].index = i;
    }
}

void NBC::findNeighbors(int point) {
    points[point].maxChecked = point;
    points[point].minChecked = point;
    for (int i = 0; i < k; i++) {
        double dist1 = getDistanceNextPoint(points[point].maxChecked + 1);
        double dist2 = getDistancePrevPoint(points[point].minChecked - 1);
        if (dist1 < dist2) {
            points[point].neighbors.push_back(points[point].maxChecked + 1);
            points[point].maxChecked++;
        }
        else {
            points[point].neighbors.push_back(points[point].minChecked - 1);
            points[point].minChecked--;
        }
    }
}

double NBC::getDistanceNextPoint(int point) {
    if (point < points.size())
        return points[point].distance;
    else
        return std::numeric_limits<double>::max();
}

double NBC::getDistancePrevPoint(int point) {
    if (point >= 0)
        return points[point].distance;
    else
        return std::numeric_limits<double>::max();
}

void NBC::countEpsilon(int point) {
    //std::vector <double> realD
    for (int i = 0; i < points[point].neighbors.size(); i++) {
        double realDist = countRealDistanceToPoint(point, i);
        /*if()*/
    }
}

double NBC::countRealDistanceToPoint(int point, int neigh) {
    return distanceOfTwoPoints(points[point].x, points[point].y, getPointX(points[point].neighbors[neigh]), getPointY(points[point].neighbors[neigh]));
}

double NBC::getPointX(int point) {
    return points[point].x;
}

double NBC::getPointY(int point) {
    return points[point].y;
}