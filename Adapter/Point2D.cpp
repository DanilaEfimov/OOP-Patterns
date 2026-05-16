#include "Point2D.h"

#include <cmath>


Point2D::Point2D(double x, double y)
	: x(x), y(y)
{}

double Point2D::getX() const noexcept
{
	return this->x;
}

double Point2D::getY() const noexcept
{
	return this->y;
}

void Point2D::setX(double x) noexcept
{
	this->x = x;
}

void Point2D::setY(double y) noexcept
{
	this->y = y;
}

std::ostream& Point2D::operator<<(std::ostream& out) const
{
	out << "Point(" << this->x << ", " << this->y << ")" << std::endl;
}

double Point2D::distance(const Point2D& first, const Point2D& second) noexcept
{
	return std::hypot(first.getX() - second.getX(), first.getY() - second.getY());
}
