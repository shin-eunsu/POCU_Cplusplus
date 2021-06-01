#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mCnt(0)
	{
	}

	PolyLine::PolyLine(const PolyLine& other)
		: mCnt(other.mCnt)
	{
		for (unsigned int i = 0; i < mCnt; i++)
		{
			mPoint[i] = new Point(other[i]->GetX(), other[i]->GetY());
		}
	}

	PolyLine::~PolyLine()
	{
		for (unsigned int i = 0; i < mCnt; i++)
		{
			mPoint[i] = nullptr;
			delete mPoint[i];
		}
	}

	PolyLine& PolyLine::operator=(const PolyLine& rhs)
	{
		mCnt = rhs.mCnt;
		for (unsigned int i = 0; i < mCnt; i++)
		{
			mPoint[i] = new Point(rhs[i]->GetX(), rhs[i]->GetY());
		}

		return *this;
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mCnt < MAXLENGTH)
		{
			mPoint[mCnt++] = new Point(x, y);
			return true;
		}

		return false;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mCnt < 10 && point != nullptr)
		{
			mPoint[mCnt++] = point;
			return true;
		}

		return false;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i < mCnt)
		{
			if (i != mCnt - 1)
			{

				for (int cnt = i; cnt < mCnt - 1; cnt++)
				{
					mPoint[cnt] = mPoint[cnt + 1];
				}
			}
			mPoint[--mCnt] = nullptr;
			return true;
		}

		return false;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		if (mCnt > 0)
		{
			float minX = mPoint[0]->GetX();
			float maxX = mPoint[0]->GetX();
			float minY = mPoint[0]->GetY();
			float maxY = mPoint[0]->GetY();

			for (unsigned int i = 0; i < mCnt; i++)
			{
				if (mPoint[i]->GetX() < minX)
				{
					minX = mPoint[i]->GetX();
				}
				if (mPoint[i]->GetX() > maxX)
				{
					maxX = mPoint[i]->GetX();
				}
				if (mPoint[i]->GetY() < minY)
				{
					minY = mPoint[i]->GetY();
				}
				if (mPoint[i]->GetY() > maxY)
				{
					maxY = mPoint[i]->GetY();
				}
			}

			*outMin = Point(minX, minY);
			*outMax = Point(maxX, maxY);

			return true;
		}
		else
		{
			return false;
		}
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (mPoint[i] == nullptr || i >= mCnt)
		{
			return nullptr;
		}

		float xVal = mPoint[i]->GetX();
		float yVal = mPoint[i]->GetY();

		return new Point(xVal, yVal);
	}
}