#pragma once
static const double L1 = 120.0;
static const double L2 = 48.5;
static const double L3 = 84.0;
struct Point {
  double x;
  double y;
};
extern Point Cel;
extern Point A, B, C;
extern Point M1, M2;

Point Find_tengent_points_cordinates(Point base, double r1, Point CEL, double r2);
Point Find_extended_point(Point base, Point end, double lenght);
float Find_angle_to_point(Point base, Point End);
void Return_all_angles(float& Motor1_angle, float& Motor2_angle, Point Cel);
