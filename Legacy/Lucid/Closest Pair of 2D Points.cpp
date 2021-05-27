#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

#define COORDINATE_RANGE 100.0

struct point {
    double x;
    double y;
};

double getDistance(point& p1, point& p2) {
    double disX = p1.x - p2.x;
    double disY = p1.y - p2.y;
    return sqrt(disX*disX + disY*disY);
}

bool sortByX(point& p1, point& p2) {
    return p1.x < p2.x;
}

bool sortByY(point& p1, point& p2) {
    return p1.y < p2.y;
}

// vec应该按照x大小排好序
double findClosestTwoPoints(vector<point>& vec, int left, int right, point& a, point& b) {
    if (right - left < 1) {
        return INT_MAX * 1.1;
    }
    else if (right - left == 1) {
        a = vec[left]; b = vec[right];
        return getDistance(vec[left], vec[right]);
    }
    else {
        int mid = (left+right) / 2;
        point a1, b1, a2, b2;
        double d1 = findClosestTwoPoints(vec, left, mid, a1, b1);
        double d2 = findClosestTwoPoints(vec, mid+1, right, a2, b2);
        double d = min(d1, d2);
        if (d1 < d2) { a = a1; b = b1; }
        else { a = a2; b = b2; }

        vector<point> points;
        for (int i = left; i <= right; i++) {
            if (fabs(vec[i].x - vec[mid].x) < d) {
                points.push_back(vec[i]);
            }
        }

        sort(points.begin(), points.end(), sortByY);

        for (int i = 0; i < points.size(); i++) {
            for (int j = 1; j <= 6; j++) {
                if (i+j >= points.size()) break;
                double dis = getDistance(points[i], points[i+j]);
                if (dis < d) {
                    a = points[i];
                    b = points[i+j];
                    d = dis;
                }
            }
        }
        return d;
    }
}

double findClosestTwoPointsBruteForce(vector<point>& vec, point& a, point& b) {
    double d = INT_MAX * 1.1;
    for (int i = 0; i < vec.size(); i++) {
        for (int j = i+1; j < vec.size(); j++) {
            double dis = getDistance(vec[i], vec[j]);
            if (dis < d) {
                d = dis;
                a = vec[i];
                b = vec[j];
            }
        }
    }
    return d;
}

void generatePoints(vector<point>& points, int length) {
    srand(unsigned(time(NULL)));
    for (int i = 0; i < length; i++)
    {
        point p;
        p.x = (rand() % int(COORDINATE_RANGE * 200)) / COORDINATE_RANGE - COORDINATE_RANGE;
        p.y = (rand() % int(COORDINATE_RANGE * 200)) / COORDINATE_RANGE - COORDINATE_RANGE;
        points.push_back(p);
    }
}

int main() {
    int num;
    double distance;

    cout << "Input number of points: ";
    cin >> num;
    if (num < 2)
        cout << "Please input a number not smaller than 2!!" << endl;
    else
    {
        cout << endl << num << " random 2D points:" << endl;
        vector<point> points;

        generatePoints(points, num);
        for (int i = 0; i < num; i++)
            cout << "(" << points[i].x << "," << points[i].y << ")" << " ";
        cout << endl;
        sort(points.begin(), points.end(), sortByX);
        point a, b;
        distance = findClosestTwoPoints(points, 0, points.size(), a, b);
        cout << endl << endl << "Points sorted by X:" << endl;
        for (int i = 0; i < num; i++)
            cout << "(" << points[i].x << "," << points[i].y << ")" << " ";
        cout << endl;
        cout << endl << "Closest two points: " << "(" << a.x << "," << a.y << ") and " << "(" << b.x << "," << b.y << ")" << endl << "Closest distance: " << distance << endl;
        cout << endl << "Answer calculated by brute force solution: ";
        point c, d;
        double distanceBF = findClosestTwoPointsBruteForce(points, c, d);
        cout << endl << "Closest two points: " << "(" << a.x << "," << a.y << ") and " << "(" << b.x << "," << b.y << ")" << endl << "Closest distance: " << distanceBF << endl;
    }
    return 0;
}