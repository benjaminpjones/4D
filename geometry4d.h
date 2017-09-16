/*
 *  Tessy - An Exploration in Four Dimensions
 *  geometry4d.h
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