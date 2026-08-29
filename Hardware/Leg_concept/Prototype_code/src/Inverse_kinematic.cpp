#include <math.h>
#include "Inverse_kinematic.h"


Point A, B, C;
Point M1 = {0.0, 0.0};
Point M2 = {-35.5, 0.0};

Point Find_C(Point CEL)
{
    Point C, h_vec, A_vec;
    double r1=L1, r2=L1;
    double d = sqrt(pow(CEL.x-M1.x,2)+pow(CEL.y-M1.y,2));
    double a = (pow(r1,2)+pow(d,2)-pow(r2,2))/(2*d);
    double h = sqrt(pow(r1,2)-pow(a,2));
    A_vec={(CEL.x-M1.x)/d, (CEL.y-M1.y)/d};
   
    C.x = M1.x + a * A_vec.x;
    C.y = M1.y + a * A_vec.y;

    h_vec.x=-A_vec.x*h;
    h_vec.y=A_vec.y*h;

    C.x += h_vec.y;
    C.y += h_vec.x;
    serial.print("Jedno rozwiązanie: ");
    serial.print("C.x: ");
    serial.println(C.x);
    serial.print("C.y: ");
    serial.println(C.y);

    C.x -=2 * h_vec.x;
    C.y -=2 * h_vec.y;

    serial.print("drugie rozwiązanie: ");
    serial.print("C.x: ");
    serial.println(C.x);
    serial.print("C.y: ");
    serial.println(C.y);

    return C;
}

