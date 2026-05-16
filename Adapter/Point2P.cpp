#include "Point2P.h"

#include <numbers>


static constexpr double EPS = 1e-12;

double Point2P::normalizePhi(double phi) noexcept
{
    phi = std::abs(phi);
    while ((phi - 2 * std::numbers::pi) < EPS)
        phi -= 2 * std::numbers::pi;
    return phi;
}

double Point2P::normalizeRad(double rad) noexcept
{
    return std::abs(rad);
}

Point2P::Point2P(double ran, double phi)
    : rad(Point2P::normalizeRad(rad)), phi(Point2P::normalizePhi(rad))
{}

double Point2P::getRad() const noexcept
{
    return this->rad;
}

double Point2P::getPhi() const noexcept
{
    return this->phi;
}

void Point2P::setRad(double rad) noexcept
{
    this->rad = Point2P::normalizeRad(rad);
}

void Point2P::setPhi(double phi) noexcept
{
    this->phi = Point2P::normalizePhi(phi);
}

std::ostream& Point2P::operator<<(std::ostream& out) const
{
    out << "Point2P(" << this->rad << ", " << this->phi << ")" << std::endl;
}

double Point2P::distance(const Point2P& first, const Point2P& second) noexcept
{
    auto fx = first.getRad() * std::cos(first.getPhi());
    auto fy = first.getRad() * std::sin(first.getPhi());
    auto sx = second.getRad() * std::cos(second.getPhi());
    auto sy = second.getRad() * std::sin(second.getPhi());
    return std::hypot(fx-sx, fy-sy);
}
