#ifndef GEOMETRY4D_H
#define GEOMETRY4D_H

#include "geometry3d.h"
#include "graphics.h"
#include <vector>
#include <array>

class Point4D {
  public:
    Point4D(double x, double y, double z, double w);

    // Addition and Subtraction
    Point4D& operator+=(Point4D const& rhs);
    Point4D& operator-=(Point4D const& rhs);
    Point4D operator+(Point4D rhs);
    Point4D operator-(Point4D rhs);

    // Multiplication (member
    Point4D& operator*=(double scalar);
    Point4D& Transform(std::array<std::array<double,4>, 4> const& matrix);

    Point3D Flatten();

    double GetW();

  private:
    double x;
    double y;
    double z;
    double w;
};

Point4D operator*(double scalar, Point4D vector);
Point4D operator*(std::array<std::array<double,4>, 4> const& matrix,
                  Point4D const& vector);

class LineSegment4D {
  public:
    LineSegment4D(Point4D startPt, Point4D endPt);
    bool uniquelyIntersectsXYZ();
    Point3D Slice();
  private:
    Point4D pt0;
    Point4D pt1;
};

class Polychoron {
  public:
    void DrawWireFrame(Graphics const& graphics) const;
    Polychoron& Transform(std::array<std::array<double,4>, 4> const& matrix);
    Polychoron& Shift(Point4D const& offset);
  protected:
    std::vector<Point4D> vertices;
    std::vector<std::array<int, 2>> edges;
    std::vector<std::array<int, 2>> hyperedges;
};

#endif