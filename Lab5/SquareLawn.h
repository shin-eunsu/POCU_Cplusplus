#pragma once
#include "Lawn.h"
#include "RectangleLawn.h"
#include "IFenceable.h"
#include "eFenceType.h"

namespace lab5
{
	class SquareLawn: public RectangleLawn
	{
	public:
		SquareLawn();
		SquareLawn(unsigned int width);
		~SquareLawn();
		unsigned int GetArea() const;
		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;

	private:
		unsigned int mWidth;
	};
}