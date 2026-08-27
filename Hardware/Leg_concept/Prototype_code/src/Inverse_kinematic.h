#pragma once
//static
static const double L1 = 120.0;
static const double L2 = 48.5;
static const double L3 = 84.0;

struct Point {
  double x;
  double y;
};

extern Point A, B, C;
extern Point M1, M2;

Point Find_C(Point P);