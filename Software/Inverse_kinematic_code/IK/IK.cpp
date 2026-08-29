#include "Inverse_kinematic.h"
#include <iostream>
Point Cel;
float Motor1_angle;
float Motor2_angle;
int main(){
	std::cin >> Cel.x;
	std::cin >> Cel.y;
	Return_all_angles(Motor1_angle, Motor2_angle, Cel);

	printf("katy: %0.2f, %0.2f", Motor1_angle, Motor2_angle);
return 0;
}