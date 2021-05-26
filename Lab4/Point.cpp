#include "Point.h"

namespace lab4
{
	Point::Point(float x, float y)
		: mX(x)
		, mY(y)
	{
	}

	Point::~Point()
	{
	}

	Point Point::operator+(const Point& other) const
	{
		float xVal = mX + other.mX;
		float yVal = mY + other.mY;
		return Point(xVal, yVal);
	}

	Point Point::operator-(const Point& other) const
	{
		float xVal = mX - other.mX;
		float yVal = mY - other.mY;
		return Point(xVal, yVal);
	}

	float Point::Dot(const Point& other) const
	{
		float rVal = (mX * other.mX) + (mY * other.mY);
		return rVal;
	}

	Point Point::operator*(float operand) const
	{
		float xVal = mX * operand;
		float yVal = mY * operand;
		return Point(xVal, yVal);
	}

	Point operator*(float operand, const Point& rhs)
	{
		float xVal = operand * rhs.mX;
		float yVal = operand * rhs.mY;
		return Point(xVal, yVal);
	}

	float Point::GetX() const
	{
		return mX;
	}

	float Point::GetY() const
	{
		return mY;
	}
}