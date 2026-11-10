#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int arc, char* argv[])
{
	/* GET THE AREA OF THE CIRCLE */
	
	// Prompt the user to get the radius
	printf("Enter the value of radius: ");
	double input; scanf("%lf", &input);

	const double radius = input;
	const double PI = 3.14159;
	
	double area = pow(radius, 2);
	area *= PI;
	
	// display output
	printf("The area of the circle radius (radius = %lf) is %lf\n", radius, area);
	return EXIT_SUCCESS;
}
