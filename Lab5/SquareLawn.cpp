#include "SquareLawn.h"

namespace lab5
{
	SquareLawn::SquareLawn()
		: mWidth(0)
	{
	}

	SquareLawn::SquareLawn(unsigned int width)
		: mWidth(width)
		, RectangleLawn(width, width)
	{
	}

	SquareLawn::~SquareLawn()
	{
	}

	unsigned int SquareLawn::GetArea() const
	{
		return mWidth * mWidth;
	}

	unsigned int SquareLawn::GetMinimumFencesCount() const
	{
		return (4 * mWidth) * 4;
	}

	unsigned int SquareLawn::GetFencePrice(eFenceType fenceType) const
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

		return GetMinimumFencesCount() * fenceUnitPrice;
	}

}