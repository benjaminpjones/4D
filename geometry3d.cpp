#include "geometry3d.h"
#include "graphics.h"
#include "color.h"
#include <iostream>

Point3D::Point3D(double x, double y, double z) {
  this -> x = x;
  this -> y = y;
  this -> z = z;
}

Pixel Point3D::Projection2D(const Graphics& graphics) {
  // TODO: figure out a good place to put the "scaling" constant
  // will depend on viewer distance from screen and screen size
  // eyeballing a good size for now
  return {static_cast<int>(100*(x/z) + graphics.screenWidth/2),
          static_cast<int>(100*(y/z) + graphics.screenHeight/2)};
}

LineSegment3D::LineSegment3D(Point3D startPt, Point3D endPt)
  :
  pt0(startPt),
  pt1(endPt)
{
}

void LineSegment3D::Draw(Graphics const& graphics) {
  Pixel px0 = pt0.Projection2D(graphics);
  Pixel px1 = pt1.Projection2D(graphics);
  graphics.DrawLine(px0, px1, Colors::Red);
}

Point3D& Point3D::operator+=(const Point3D& rhs) {
  this->x += rhs.x;
  this->y += rhs.y;
  this->z += rhs.z;
  return *this;
}

Point3D& Point3D::operator-=(const Point3D& rhs) {
  this->x -= rhs.x;
  this->y -= rhs.y;
  this->z -= rhs.z;
  return *this;
}

Point3D Point3D::operator+(const Point3D& rhs) {
  return Point3D(x+rhs.x, y+rhs.y, z+rhs.z);
}

Point3D Point3D::operator-(const Point3D& rhs) {
  return Point3D(x-rhs.x, y-rhs.y, z-rhs.z);
}

void Polyhedron::DrawWireFrame(Graphics& graphics) {
  for (int i = 0; i < edges.size(); i++) {
    LineSegment3D(vertices[edges[i][0]], vertices[edges[i][1]]).Draw(graphics);
  }
}


