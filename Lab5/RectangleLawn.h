#pragma once
#include "Lawn.h"
#include "IFenceable.h"
#include "eFenceType.h"

namespace lab5
{
	class RectangleLawn: public Lawn, public IFenceable
	{
	public:
		RectangleLawn();
		RectangleLawn(int width, int height);
		~RectangleLawn();
		unsigned int GetArea() const;
		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;

	private:
		unsigned int mWidth;
		unsigned int mHeight;

	};
}