#ifndef GEOMETRY3D_H
#define GEOMETRY3D_H

#include "graphics.h"
#include <vector>
#include <array>

class Point3D {
  public:
    Point3D(double x, double y, double z);
    Pixel Projection2D(Graphics const& graphics);

    Point3D& operator+=(const Point3D& rhs);
    Point3D& operator-=(const Point3D& rhs);
    Point3D operator+(const Point3D& rhs);
    Point3D operator-(const Point3D& rhs);

  private:
    double x;
    double y;
    double z;
};

class LineSegment3D {
  public:
    LineSegment3D(Point3D startPt, Point3D endPt);
    void Draw(Graphics const& graphics);
  private:
    Point3D pt0;
    Point3D pt1;
};

class Polyhedron {
  public:
    void DrawWireFrame(Graphics& graphics);
    int AddCorner(Point3D newCorner);
    int AddEdge(int pt0, int pt1);
  protected:
    std::vector<Point3D> vertices;
    std::vector<std::array<int,2> > edges;
};

#endif
