#pragma once
#include "Lawn.h"
#include "IFenceable.h"
#include "eFenceType.h"

namespace lab5
{
	class CircleLawn: public Lawn, public IFenceable
	{
	public:
		CircleLawn(unsigned int radius);
		~CircleLawn();
		unsigned int GetArea() const;
		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;

	private:
		unsigned int mRadius;
		const double PI = 3.14;
	};
}