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
		return round(PI * mRadius * mRadius);
	}

	unsigned int CircleLawn::GetMinimumFencesCount() const
	{
		return 2 * PI * mRadius * 4;
	}

	unsigned int CircleLawn::GetFencePrice(eFenceType fenceType) const
	{
		double FenceUnitPrice = 0;

		switch (fenceType)
		{
		case lab5::RED_CEDAR:
			FenceUnitPrice = 6 * 0.25;
			break;
		case lab5::SPRUCE:
			FenceUnitPrice = 7 * 0.25;
			break;
		}

		return GetMinimumFencesCount() * FenceUnitPrice;
	}
}