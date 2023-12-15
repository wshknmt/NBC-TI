#include "NBC.h"

NBC::NBC(std::string path) {
    openDataset(path);
    countDistance();
    sortPoints();
 
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
            point.index = index;
            if (point.x < minX) minX = point.x;
            if (point.y < minY) minY = point.y;
            points.push_back(point);

            index++;
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
