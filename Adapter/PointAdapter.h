#pragma once

#include "Point2D.h"
#include "Point2P.h"


class PolarToDecartAdapter
{
	Point2P p;

public:
	PolarToDecartAdapter(Point2P point);

	Point2D get() const noexcept;
};

class DecartToPolarAdapter
{
	Point2D p;

public:
	DecartToPolarAdapter(Point2D point);

	Point2P get() const noexcept;
};

