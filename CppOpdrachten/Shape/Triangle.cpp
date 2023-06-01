#include "Triangle.h"
#include <cmath>

Triangle::Triangle() : side1(1.0), side2(1.0), side3(1.0)
{
	
}

Triangle::Triangle(double side1, double side2, double side3) : side1(side1), side2(side2), side3(side3)
{
	
}

double Triangle::getSide1() const
{
	return side1;
}

double Triangle::getSide2() const
{
	return side2;
}

double Triangle::getSide3() const
{
	return side3;
}

double Triangle::getArea() const
{
	// √(1/2 Omtrek*(1/2 Omtrek-Zijde 1)*(1/2Omtrek-Zijde 2)*(1/2Omtrek-Zijde 3))
	double periHalf = 0.5 * getPerimeter();
	return std::sqrt(periHalf * (periHalf - side1) * (periHalf - side2) * (periHalf - side3));
}

double Triangle::getPerimeter() const
{
	return side1 + side2 + side3;
}
