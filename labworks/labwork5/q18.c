#include <stdio.h>
#include <math.h>

int main()
{
	float v, t;
	printf("Enter the speed of wind in miles per hour:-\n");
	scanf("%f", &v);
	printf("Enter the temperature in fahreneit:-\n");
	scanf("%f", &t);
	float wind_chill_index;
	if ((0.00 <= v) && (v <= 4.00))
	{
		wind_chill_index = t;
	}
	else if ((4.00 < v) && (v <= 45.00))
	{
		wind_chill_index = (1.6 * t) - 55;
	}
	else
	{
		wind_chill_index = 91.4 + (91.4 - t) * ((0.0203 * v) - (0.152 * v) - 0.474);
	}

	printf("The wind chill index is %f.\n", wind_chill_index);
	return 0;
}
