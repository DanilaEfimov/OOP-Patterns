#pragma once

#include <ostream>


class Point2D
{
	double x;
	double y;

public:

	Point2D(double x, double y);

	double getX() const noexcept;
	double getY() const noexcept;

	void setX(double x) noexcept;
	void setY(double y) noexcept;

	std::ostream& operator<<(std::ostream& out) const;

	static double distance(const Point2D& first, const Point2D& second) noexcept;
};
