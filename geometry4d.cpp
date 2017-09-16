/*
 *  Tessy - An Exploration in Four Dimensions
 *  geometry4d.cpp
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

#include "geometry4d.h"
#include "geometry3d.h"
#include "graphics.h"
#include <cmath>         // std::signbit
#include <assert.h>
#include <vector>
#include <array>
#include <iostream>

Point4D::Point4D(double x, double y, double z, double w)
{
  this->x = x;
  this->y = y;
  this->z = z;
  this->w = w;
}

Point4D& Point4D::operator+=(Point4D const& rhs)
{
  x += rhs.x;
  y += rhs.y;
  z += rhs.z;
  w += rhs.w;
  return *this;
}

Point4D& Point4D::operator-=(Point4D const& rhs)
{
  x -= rhs.x;
  y -= rhs.y;
  z -= rhs.z;
  w -= rhs.w;
  return *this;
}

Point4D Point4D::operator+(Point4D rhs)
{
  rhs += *this;
  return rhs;
}

Point4D Point4D::operator-(Point4D rhs)
{
  rhs -= *this;
  return rhs;
}

Point4D& Point4D::operator*=(double scalar)
{
  x *= scalar;
  y *= scalar;
  z *= scalar;
  w *= scalar;
  return *this;
}

Point4D& Point4D::Transform(std::array<std::array<double,4>, 4> const& matrix)
{
  x = matrix[0][0] * x
      + matrix[0][1] * y
      + matrix[0][2] * z
      + matrix[0][3] * w;
  y = matrix[1][0] * x
      + matrix[1][1] * y
      + matrix[1][2] * z
      + matrix[1][3] * w;
  z = matrix[2][0] * x
      + matrix[2][1] * y
      + matrix[2][2] * z
      + matrix[2][3] * w;
  w = matrix[3][0] * x
      + matrix[3][1] * y
      + matrix[3][2] * z
      + matrix[3][3] * w;

  return *this;
}

Point3D Point4D::Flatten()
{
  return Point3D(x, y, z);
}

double Point4D::GetW()
{
  return w;
}

Point4D operator*(double scalar, Point4D vector)
{
  vector *= scalar;
  return vector;
}

Point4D operator*(std::array<std::array<double,4>, 4> const& matrix,
                  Point4D vector)
{
  vector.Transform(matrix);
  return vector;
}

bool LineSegment4D::uniquelyIntersectsXYZ()
{
  if (pt0.GetW() < 0 && pt1.GetW() > 0) return true;
  if (pt0.GetW() > 0 && pt1.GetW() < 0) return true;
  return false;
}

LineSegment4D::LineSegment4D(Point4D startPt, Point4D endPt)
  :
  pt0(startPt),
  pt1(endPt)
{
}

Point3D LineSegment4D::Slice()
{
  // In order for a return type of Point4D to make sense,
  // The w=0 hyperplane should intersect the segment at a unique point.
  // This uniqueness check should occur outside of this function.

  assert(uniquelyIntersectsXYZ());

  double dw = std::abs(pt1.GetW() - pt0.GetW());

  double weight0 = std::abs(pt0.GetW()/dw);
  double weight1 = std::abs(pt1.GetW()/dw);

  return (weight0 * pt0 + weight1 * pt1).Flatten();
}

void Polychoron::DrawWireFrame(Graphics const& graphics) const {

  Point3D pt0(0,0,0);
  Point3D pt1(0,0,0);

  for (int i=0; i < hyperedges.size(); ++i) {
    
    LineSegment4D edge0(vertices[edges[hyperedges[i][0]][0]],
                        vertices[edges[hyperedges[i][0]][1]]);
    LineSegment4D edge1(vertices[edges[hyperedges[i][1]][0]],
                        vertices[edges[hyperedges[i][1]][1]]);

    if (edge0.uniquelyIntersectsXYZ()) {
      pt0 = edge0.Slice();
    } else {
      continue;
    }

    if (edge1.uniquelyIntersectsXYZ()) {
      pt1 = edge1.Slice();
    } else {
      continue;
    }

    LineSegment3D(pt0, pt1).Draw(graphics);
  }
}

Polychoron& Polychoron::Transform(
    std::array<std::array<double,4>, 4> const& matrix)
{
  for (int i=0; i < vertices.size(); ++i) {
    vertices[i].Transform(matrix);
  }
  
  return *this;
}

Polychoron& Polychoron::Shift(Point4D const& offset) {
  for (int i=0; i < vertices.size(); ++i) {
    vertices[i] += offset;
  }
  
  return *this;
}
