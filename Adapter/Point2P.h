#pragma once

#include <ostream>


class Point2P
{
	double rad;
	double phi;

	static double normalizePhi(double phi) noexcept;
	static double normalizeRad(double rad) noexcept;

public:

	Point2P(double rad, double phi);

	double getRad() const noexcept;
	double getPhi() const noexcept;

	void setRad(double x) noexcept;
	void setPhi(double y) noexcept;

	std::ostream& operator<<(std::ostream& out) const;

	static double distance(const Point2P& first, const Point2P& second) noexcept;
};

