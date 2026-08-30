#include <math.h>
#include "Inverse_kinematic.h"
#include <iostream>
#include <math.h>

bool debug_mode_on = false;
static float PI = 3.14159265359;


Point A, B, C;
Point M1 = {0.0, 0.0};
Point M2 = {-35.5, 0.0};

Point Find_tengent_points_cordinates(Point base, double r1, Point CEL, double r2)
{
    Point C, h_vec, A_vec;
    double d = sqrt(pow(CEL.x- base.x,2)+pow(CEL.y- base.y,2));
    double a = (pow(r1,2)+pow(d,2)-pow(r2,2))/(2*d);
    double h = sqrt(pow(r1,2)-pow(a,2));
    A_vec={(CEL.x- base.x)/d, (CEL.y- base.y)/d};
   
    C.x = base.x + a * A_vec.x;
    C.y = base.y + a * A_vec.y;

    h_vec.x=-A_vec.x*h;
    h_vec.y=A_vec.y*h;

    C.x += h_vec.y;
    C.y += h_vec.x;
    if (debug_mode_on == true) {
        printf("Pirewsze rozwianie %0.2f, %0.2f \n", C.x, C.y);
    }
    
   
   //TODO Weryfikacja wariantu
    return C;
}

Point Find_extended_point(Point start, Point end, double lenght) {
    Point B;
    double vector_lenght = sqrt(pow((end.x - start.x),2) + pow((end.y - start.y), 2));
    Point Vector = {(end.x - start.x)/vector_lenght,  (end.y - start.y)/ vector_lenght };
    B = { end.x+ Vector.x * lenght, end.y+Vector.y * lenght };
    if (debug_mode_on == true) {
        printf("pozycja = %0.2f, %0.2f\n\n", B.x, B.y);
    }
    return B;
}


float Find_angle_to_point(Point base, Point end) {
    double kat = atan2((end.y - base.y), (end.x - base.x)) * 180 / PI;
    if (debug_mode_on == true) {
        printf("kat %0.2f\n\n", kat );
    }
    return kat;

}

void Return_all_angles(float& Motor1_angle, float& Motor2_angle, Point Cel) {
    C = Find_tengent_points_cordinates(M1, L1, Cel, L1);
    B = Find_extended_point(Cel, C, L3);
    A = Find_tengent_points_cordinates(M2, L2, B, L1);
    float kat1 = Find_angle_to_point(M1, C);
    float kat2 = Find_angle_to_point(M2, A);
    if (debug_mode_on == true) {
        printf("First motor angle: %0.2f \n Secound motor angle %0.2f", kat1, kat2);
    }
    
    Motor1_angle = kat1;
    Motor2_angle = kat2;
}