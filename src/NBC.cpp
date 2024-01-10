#include "NBC.h"

NBC::NBC(std::string path, char delimiter, int k) {
    this->k = k;
    openDataset(path, delimiter);
    countDistance();
    sortPoints();
    setIndex();
    findNeighbors();
    countNdf();
    putLabelsOn();
}

void NBC::openDataset(std::string path, char delimiter) {
    std::ifstream file(path);
    if (file.is_open()) {
        std::string line;

        while (getline(file, line)) {
            std::cout << line << std::endl;
            std::istringstream issLine(line);
            std::string x, y;
            std::getline(issLine, x, delimiter);
            std::getline(issLine, y, delimiter);
            Point point;
            point.setX(stod(x));
            point.setY(stod(y));
            if (point.getX() < minX) minX = point.getX();
            if (point.getY() < minY) minY = point.getY();
            if (point.getX() > maxX) maxX = point.getX();
            if (point.getY() > maxY) maxY = point.getY();
            points.push_back(point);
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open the file." << std::endl;
    }
}

void NBC::printPoints() {
    for (int i = 0; i < points.size(); i++) {
        points[i].print();
    }
}

void NBC::countDistance() {
    for (int i = 0; i < points.size(); i++) {
        points[i].setDistance(distanceOfTwoPoints(points[i].getX(), points[i].getY(), minX, minY));
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
        points[i].setIndex(i);
    }
}

void NBC::findNeighbors() {
    for (int i = 0; i < points.size(); i++) {
        findNeighborsOfPoint(i);
        points[i].countEpsilon();
        while (points[i].getMinChecked() - 1 >= 0) {
            double estimatedDist = fabs(points[i].getDistance() - points[points[i].getMinChecked() - 1].getDistance());
            if (estimatedDist < points[i].getEpsilon()) {
                Neighbor n;
                n.index = points[i].getMinChecked() - 1;
                n.realDistance = countRealDistanceToPoint(i, n.index);
                points[i].replaceNeighbor(n);
                points[i].decrementMinChecked();
                points[i].countEpsilon();
            }
            else {
                break;
            }
        }
        while (points[i].getMaxChecked() + 1 < points.size()) {
            double estimatedDist = fabs(points[i].getDistance() - points[points[i].getMaxChecked() + 1].getDistance());
            if (estimatedDist < points[i].getEpsilon()) {
                Neighbor n;
                n.index = points[i].getMaxChecked() + 1;
                n.realDistance = countRealDistanceToPoint(i, n.index);
                points[i].replaceNeighbor(n);
                points[i].incrementMaxChecked();
                points[i].countEpsilon();
            }
            else {
                break;
            }
        }
    }
}

void NBC::findNeighborsOfPoint(int point) {
    points[point].setMaxChecked(point);
    points[point].setMinChecked(point);

    for (int i = 0; i < k; i++) {
        double dist1 = getDistanceNextPoint(points[point].getMaxChecked() + 1);
        double dist2 = getDistancePrevPoint(points[point].getMinChecked() - 1);
        if (dist1 < dist2) {
            Neighbor n;
            n.index = points[point].getMaxChecked() + 1;
            n.realDistance = countRealDistanceToPoint(point, n.index);
            points[point].addNeighbor(n);
            points[point].incrementMaxChecked();
        }
        else {
            Neighbor n;
            n.index = points[point].getMinChecked() - 1;
            n.realDistance = countRealDistanceToPoint(point, n.index);
            points[point].addNeighbor(n);
            points[point].decrementMinChecked();
        }
    }
}

void NBC::countNdf() {
    for (int i = 0; i < points.size(); i++) {
        countReverseNeighbors(i);
        points[i].countNdf();
    }
}

void NBC::putLabelsOn() {
    groupIndex = 0;
    double minNdf = 0.9;
    for (int i = 0; i < points.size(); i++) {
        if (points[i].getLabel() != 0) continue;
        if (points[i].getNdf() < minNdf) {
            points[i].setLabel(-1);
            continue;
        }
        else {
            groupIndex++;
            seeds.push_back(i);
            while (!seeds.empty()) {
                points[seeds[0]].setLabel(groupIndex);
                for (int j = 0; j < points[seeds[0]].getNeighborsSize(); j++) {
                    int neighborIdx = points[seeds[0]].getNeighbor(j).index;
                    if (points[neighborIdx].getLabel() <= 0) {
                        points[neighborIdx].setLabel(groupIndex);
                        if (points[neighborIdx].getNdf() >= minNdf) {
                            seeds.push_back(neighborIdx);
                        }
                    }
                }
                seeds.pop_front();
            }
        }
    }
}

double NBC::getDistanceNextPoint(int point) {
    if (point < points.size())
        return points[point].getDistance();
    else
        return std::numeric_limits<double>::max();
}

double NBC::getDistancePrevPoint(int point) {
    if (point >= 0)
        return points[point].getDistance();
    else
        return std::numeric_limits<double>::max();
}

double NBC::countRealDistanceToPoint(int point, int neigh) {
    return distanceOfTwoPoints(points[point].getX(), points[point].getY(), points[neigh].getX(), points[neigh].getY());
}

void NBC::countReverseNeighbors(int point) {
    for (int j = 0; j < points[point].getNeighborsSize(); j++) {
        points[points[point].getNeighbor(j).index].incrementReverseCounter();
    }
}

void NBC::incrementReverseCounter(int point) {
    points[point].incrementReverseCounter();
}

void NBC::printMaxLabel() {
    std::cout << "maxIndex: " << groupIndex << std::endl;
}
std::vector <Point> NBC::getPoints() {
    return points;
}
int NBC::getGroupIndex() {
    return groupIndex;
}
double NBC::getMinX() {
    return minX;
}
double NBC::getMinY() {
    return minY;
}
double NBC::getMaxX() {
    return maxX;
}
double NBC::getMaxY() {
    return maxY;
}