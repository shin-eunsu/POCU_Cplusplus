#include <cmath>
#include "EquilateralTriangleLawn.h"

namespace lab5
{
	EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int width)
		: mWidth(width)
	{
	}

	EquilateralTriangleLawn::~EquilateralTriangleLawn()
	{
	}

	unsigned int EquilateralTriangleLawn::GetArea() const
	{
		return round((mWidth * mWidth) / 4 * sqrt(3));
	}

	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		return 3 * mWidth * 4;
	}

	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
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