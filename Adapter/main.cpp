#include "Point2D.h"
#include "Point2P.h"
#include "PointAdapter.h"

#include <iostream>

int main()
{
    Point2D d(3.0, 4.0);
    DecartToPolarAdapter d2p(d);
    Point2P polar = d2p.get();
    std::cout << "Decart (3, 4) -> Polar:" << std::endl;
    std::cout << "  rad = " << polar.getRad() << std::endl;
    std::cout << "  phi = " << polar.getPhi() << std::endl;

    std::cout << std::endl;

    PolarToDecartAdapter p2d(polar);
    Point2D decart = p2d.get();
    std::cout << "Polar back -> Decart:" << std::endl;
    std::cout << "  x = " << decart.getX() << std::endl;
    std::cout << "  y = " << decart.getY() << std::endl;

    return 0;
}