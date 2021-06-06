#include "RectangleLawn.h"

using namespace std;

namespace lab5
{
	RectangleLawn::RectangleLawn()
		: mWidth(0)
		, mHeight(0)
	{
	}

	RectangleLawn::RectangleLawn(int width, int height)
		: mWidth(width)
		, mHeight(height)
	{
	}

	RectangleLawn::~RectangleLawn()
	{

	}

	unsigned int RectangleLawn::GetArea() const
	{
		return mWidth * mHeight;
	}

	unsigned int RectangleLawn::GetMinimumFencesCount() const
	{
		return ((2 * mWidth) + (2 * mHeight)) * 4;
	}

	unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const
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