#include <cmath>
#include "CircleLawn.h"

namespace lab5
{
	CircleLawn::CircleLawn(unsigned int radius)
		: mRadius(radius)
	{
	}

	CircleLawn::~CircleLawn()
	{
	}

	unsigned int CircleLawn::GetArea() const
	{
		return static_cast<unsigned int>(round(PI * mRadius * mRadius));
	}

	unsigned int CircleLawn::GetMinimumFencesCount() const
	{
		return static_cast <unsigned int>(2 * PI * mRadius * 4);
	}

	unsigned int CircleLawn::GetFencePrice(eFenceType fenceType) const
	{
		double fenceUnitPrice = 0;

		switch (fenceType)
		{
		case lab5::RED_CEDAR:
			fenceUnitPrice = 6 * 0.25;
			break;
		case lab5::SPRUCE:
			fenceUnitPrice = 7 * 0.25;
			break;
		}

		return static_cast <unsigned int>(GetMinimumFencesCount() * fenceUnitPrice);
	}
}