#include <math.h>
#include "Inverse_kinematic.h"




Point A, B, C;
Point M1 = {0.0, 0.0};
Point M2 = {-35.5, 0.0};

Point Find_C(Point P)
{
    Point C;

    // Promienie dwóch okręgów
    const double r1 = L1;   // M1 -> C
    const double r2 = L1;   // P  -> C

    // Wektor M1 -> P
    double dx = P.x - M1.x;
    double dy = P.y - M1.y;

    // Odległość M1-P
    double d = sqrt(dx * dx + dy * dy);

    // Sprawdzenie, czy okręgi się przecinają
    if (d > r1 + r2 || d < fabs(r1 - r2) || d == 0.0) {
        return {NAN, NAN};
    }

    // Odległość od M1 do rzutu C na prostą M1-P
    double a =
        (r1 * r1 - r2 * r2 + d * d)
        / (2.0 * d);

    // Odległość C od prostej M1-P
    double h =
        sqrt(r1 * r1 - a * a);

    // Punkt leżący na prostej M1-P
    double x0 = M1.x + a * dx / d;
    double y0 = M1.y + a * dy / d;

    // Jedno z dwóch rozwiązań
    C.x = x0 - h * dy / d;
    C.y = y0 + h * dx / d;

    return C;
}

