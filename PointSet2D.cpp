#include <iostream>
#include <vector>

using namespace std;

class Point2D {
    double x_, y_;
public:
    Point2D() : x_(0.0), y_(0.0) {}
    Point2D(double x, double y) : x_(x), y_(y) {}

    double getX() const {
        return this->x_;
    }

    void setX(double x) {
        this->x_ = x;
    }

    double getY() const {
        return this->y_;
    }

    void setY(double y) {
        this->y_ = y;
    }
};

class PointSet2D {
    vector<Point2D> points;
    
    bool member(Point2D point2D) {
        for (Point2D point2D1: points) {
            if (point2D.getX() == point2D1.getX() && point2D1.getY() == point2D.getY()) {
                return true;
            }
        }
        return false;
    }
public:
    PointSet2D(vector<Point2D> points) {
        this->points = points;
    }

    const vector<Point2D> &getPoints() const {
        return points;
    }

    void setPoints(const vector<Point2D> &points) {
        this->points = points;
    }

    PointSet2D &operator+=(const Point2D &point) {
        *this = *this + point;
        return *this;
    }

    PointSet2D &operator+=(const PointSet2D &other) {
        *this = *this + other;
        return *this;
    }
    
    friend PointSet2D operator+(const PointSet2D& lhs, const Point2D &point) {
        vector<Point2D> concatPoints = lhs.points;
        concatPoints.push_back(point);
        PointSet2D result(concatPoints);
        return result;
    }

    friend PointSet2D operator+(const PointSet2D& lhs, const PointSet2D& rhs) {
        vector<Point2D> concatPoints = lhs.points;
        concatPoints.insert(concatPoints.end(), rhs.points.begin(), rhs.points.end());
        PointSet2D concatPointSet(concatPoints);
        return concatPointSet;
    }

    template<class T>
    void const map(T &f) {
        for (const Point2D &p : points)
            f(p);
    }

    Point2D getPoint(size_t index) const {
        if (index < points.size())
            return points[index];
        return Point2D();
    }

    Point2D &operator[](size_t index) {
        if (index < points.size())
            return points[index];
        throw "Out of range";
    }

    const Point2D &operator[](size_t index) const {
        if (index < points.size())
            return points[index];
        throw "Out of range";
    }

    friend ostream& operator<<(ostream& os, const PointSet2D& pointSet) {
        for (auto i = pointSet.points.begin(); i != pointSet.points.end(); ++i)
            os << "(" << i->getX() << ", " << i->getY() << ")" << ' ';
        os << endl;
        return os;
    }
};

bool isIn(const Point2D &point, const Point2D &center, double rad) {
    return (point.getX() - center.getX()) * (point.getX() - center.getY()) +
           (point.getY() - center.getY()) * (point.getY() - center.getY())
           - rad * rad < 0.0f;
}

bool within(const PointSet2D &points, const Point2D &center, double R) {

    if (R <= 0.0) return false;

    for (Point2D p : points.getPoints()) {
        if (!isIn(p, center, R)) {
            return false;
        }
        return true;
    }
}

int main() {
    cout << "Hello World" << endl;
    
    Point2D p1(1, 2);
    Point2D p2(4, 3);
    vector<Point2D> points;
    points.push_back(p1);
    points.push_back(p2);

    PointSet2D pointSet(points);
    
    Point2D p3(0.5, 1.2);
    Point2D p4(1.8, 5.9);
    vector<Point2D> points2;
    points2.push_back(p3);
    points2.push_back(p4);
    
    PointSet2D pointSet2(points2);
    
    cout << pointSet; // (1, 2) (4, 3)
    cout << pointSet2; // (0.5, 1.2) (1.8, 5.9)
    
    cout << pointSet + pointSet2; // (1, 2) (4, 3) (0.5, 1.2) (1.8, 5.9)
    cout << pointSet; // (1, 2) (4, 3)
    
    pointSet += pointSet2;
    cout << pointSet; // (1, 2) (4, 3) (0.5, 1.2) (1.8, 5.9)
    pointSet += p1;
    cout << pointSet; // (1, 2) (4, 3) (0.5, 1.2) (1.8, 5.9) (1, 2)

    return 0;
}
