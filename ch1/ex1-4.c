#include <stdio.h>
#include <math.h>
int main() {
	int n;
	const double pi = acos(-1.0);
	scanf("%d", &n);
	printf("%.3f %.3f\n", sin(n*pi/180.0), cos(n*pi/180.0));

	return 0;
}
