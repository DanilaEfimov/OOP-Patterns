#include "PointAdapter.h"


PolarToDecartAdapter::PolarToDecartAdapter(Point2P point)
    : p(point)
{}

Point2D PolarToDecartAdapter::get() const noexcept
{
    const auto& rad = this->p.getRad();
    const auto& phi = this->p.getPhi();
    auto x = rad * std::cos(phi);
    auto y = rad * std::sin(phi);
    return Point2D(x, y);
}

DecartToPolarAdapter::DecartToPolarAdapter(Point2D point)
    : p(point)
{}

Point2P DecartToPolarAdapter::get() const noexcept
{
    const auto& x = this->p.getX();
    const auto& y = this->p.getY();
    auto rad = std::hypot(x, y);
    auto phi = std::atan2(y, x);
    return Point2P(rad, phi);
}
