#include "Triangle.h"

void main()
{
	Point a, b(0, 4), c(3, 0);
	Triangle tri(a, b, c, "Triangle", "tri");
	tri.printDetails();
}