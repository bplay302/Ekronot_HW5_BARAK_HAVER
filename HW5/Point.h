#pragma once

class Point
{
public:

	// Constructors
	Point(); // initialize values to 0
	Point(const double x, const double y);
	
	// Operators    
	Point operator+(const Point& other) const;
	Point& operator+=(const Point& other);

	// Getters
	double getX() const;
	double getY() const;

	// Methods
	double distance(const Point& other);

private:
	double _x, _y;

};