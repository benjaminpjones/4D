/*
 *  Tessy - An Exploration in Four Dimensions
 *  geometry3d.h
 *  Copyright (C) 2017  Benjamin P. Jones
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
