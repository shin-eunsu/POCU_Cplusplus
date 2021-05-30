#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mCnt(0)
	{
		for (int i = 0; i < 10; i++)
		{
			mPoint[i] = new Point();
		}
	}

	PolyLine::PolyLine(const PolyLine& other)
		: mCnt(other.mCnt)
	{
		for (unsigned int i = 0; i < 10; i++)
		{
			mPoint[i] = new Point();
			memcpy(mPoint[i], other.mPoint[i], sizeof(Point));
		}
	}

	PolyLine::~PolyLine()
	{
		for (int i = 0; i < 10; i++)
		{
			delete mPoint[i];
		}
	}

	PolyLine& PolyLine::operator=(const PolyLine& rhs)
	{
		mCnt = rhs.mCnt;
		PolyLine* tmpPl = new PolyLine();
		for (int i = 0; i < 10; i++)
		{
			memcpy(tmpPl->mPoint[i], rhs.mPoint[i], sizeof(Point));
			memcpy(mPoint[i], tmpPl->mPoint[i], sizeof(Point));
		}
		delete tmpPl;

		return *this;
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mCnt < 10)
		{
			Point* tPoint = new Point(x, y);
			memcpy(mPoint[mCnt++], tPoint, sizeof(Point));
			delete tPoint;

			return true;
		}
		else
		{
			return false;
		}
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mCnt < 10)
		{
			Point* p1 = new Point();
			memcpy(p1, point, sizeof(Point));
			memcpy(mPoint[mCnt++], p1, sizeof(Point));
			delete p1;

			return true;
		}
		else
		{
			return false;
		}
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i < mCnt)
		{
			if (i != mCnt - 1)
			{
				unsigned int cnt = 0;
				for (cnt = i; cnt < mCnt - 1; cnt++)
				{
					memcpy(mPoint[cnt], mPoint[cnt + 1], sizeof(Point));
				}
			}
			Point* tp = new Point();
			memcpy(mPoint[mCnt - 1], tp, sizeof(Point));
			delete tp;
			mCnt--;
			return true;
		}
		else
		{
			return false;
		}
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