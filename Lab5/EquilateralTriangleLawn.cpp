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
		return static_cast <unsigned int>(round((mWidth * mWidth) / 4 * sqrt(3)));
	}

	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		return 3 * mWidth * 4;
	}

	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
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