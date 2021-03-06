/*
 *  Tessy - An Exploration in Four Dimensions
 *  polychora.cpp
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

#include "polychora.h"

Tesseract::Tesseract() {
  vertices =
    {
      {-1.0, -1.0, 1.0, -1.0},
      {-1.0, -1.0, 1.0, 1.0},
      {-1.0, -1.0, 3.0, -1.0},
      {-1.0, -1.0, 3.0, 1.0},
      {-1.0, 1.0, 1.0, -1.0},
      {-1.0, 1.0, 1.0, 1.0},
      {-1.0, 1.0, 3.0, -1.0},
      {-1.0, 1.0, 3.0, 1.0},
      {1.0, -1.0, 1.0, -1.0},
      {1.0, -1.0, 1.0, 1.0},
      {1.0, -1.0, 3.0, -1.0},
      {1.0, -1.0, 3.0, 1.0},
      {1.0, 1.0, 1.0, -1.0},
      {1.0, 1.0, 1.0, 1.0},
      {1.0, 1.0, 3.0, -1.0},
      {1.0, 1.0, 3.0, 1.0}
    };
  edges =
    {
      {0, 1},
      {0, 2},
      {0, 4},
      {0, 8},
      {1, 3},
      {1, 5},
      {1, 9},
      {2, 3},
      {2, 6},
      {2, 10},
      {3, 7},
      {3, 11},
      {4, 5},
      {4, 6},
      {4, 12},
      {5, 7},
      {5, 13},
      {6, 7},
      {6, 14},
      {7, 15},
      {8, 9},
      {8, 10},
      {8, 12},
      {9, 11},
      {9, 13},
      {10, 11},
      {10, 14},
      {11, 15},
      {12, 13},
      {12, 14},
      {13, 15},
      {14, 15},
    };
  hyperedges =
    {
      {0, 1},
      {0, 2},
      {0, 3},
      {0, 4},
      {0, 5},
      {0, 6},
      {0, 7},
      {0, 12},
      {0, 20},
      {1, 2},
      {1, 3},
      {1, 4},
      {1, 7},
      {1, 8},
      {1, 9},
      {1, 13},
      {1, 21},
      {2, 3},
      {2, 5},
      {2, 8},
      {2, 12},
      {2, 13},
      {2, 14},
      {2, 22},
      {3, 6},
      {3, 9},
      {3, 14},
      {3, 20},
      {3, 21},
      {3, 22},
      {4, 5},
      {4, 6},
      {4, 7},
      {4, 10},
      {4, 11},
      {4, 15},
      {4, 23},
      {5, 6},
      {5, 10},
      {5, 12},
      {5, 15},
      {5, 16},
      {5, 24},
      {6, 11},
      {6, 16},
      {6, 20},
      {6, 23},
      {6, 24},
      {7, 8},
      {7, 9},
      {7, 10},
      {7, 11},
      {7, 17},
      {7, 25},
      {8, 9},
      {8, 10},
      {8, 13},
      {8, 17},
      {8, 18},
      {8, 26},
      {9, 11},
      {9, 18},
      {9, 21},
      {9, 25},
      {9, 26},
      {10, 11},
      {10, 15},
      {10, 17},
      {10, 19},
      {10, 27},
      {11, 19},
      {11, 23},
      {11, 25},
      {11, 27},
      {12, 13},
      {12, 14},
      {12, 15},
      {12, 16},
      {12, 17},
      {12, 28},
      {13, 14},
      {13, 15},
      {13, 17},
      {13, 18},
      {13, 29},
      {14, 16},
      {14, 18},
      {14, 22},
      {14, 28},
      {14, 29},
      {15, 16},
      {15, 17},
      {15, 19},
      {15, 30},
      {16, 19},
      {16, 24},
      {16, 28},
      {16, 30},
      {17, 18},
      {17, 19},
      {17, 31},
      {18, 19},
      {18, 26},
      {18, 29},
      {18, 31},
      {19, 27},
      {19, 30},
      {19, 31},
      {20, 21},
      {20, 22},
      {20, 23},
      {20, 24},
      {20, 25},
      {20, 28},
      {21, 22},
      {21, 23},
      {21, 25},
      {21, 26},
      {21, 29},
      {22, 24},
      {22, 26},
      {22, 28},
      {22, 29},
      {23, 24},
      {23, 25},
      {23, 27},
      {23, 30},
      {24, 27},
      {24, 28},
      {24, 30},
      {25, 26},
      {25, 27},
      {25, 31},
      {26, 27},
      {26, 29},
      {26, 31},
      {27, 30},
      {27, 31},
      {28, 29},
      {28, 30},
      {28, 31},
      {29, 30},
      {29, 31},
      {30, 31},
    };
}
