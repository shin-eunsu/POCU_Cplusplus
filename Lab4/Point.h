#pragma once

namespace lab4
{
	class Point
	{
	public:
		Point();
		Point(float x, float y);
		Point(const Point& other);

		~Point();

		Point operator+(const Point& other) const;
		Point operator-(const Point& other) const;
		Point operator=(const Point& other);
		float Dot(const Point& other) const;
		Point operator*(float operand) const;
		friend Point operator*(float operand, const Point& rhs);

		float GetX() const;
		float GetY() const;

	private:
		float mX;
		float mY;
	};

}