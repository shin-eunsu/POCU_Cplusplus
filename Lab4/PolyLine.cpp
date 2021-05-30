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
			polyLinePoint[i] = new Point();
		}
	}

	PolyLine::PolyLine(const PolyLine& other)
		: mCnt(other.mCnt)
	{
		for (unsigned int i = 0; i < 10; i++)
		{
			polyLinePoint[i] = new Point();
			memcpy(polyLinePoint[i], other.polyLinePoint[i], sizeof(Point));
		}
	}

	PolyLine::~PolyLine()
	{
		for (int i = 0; i < 10; i++)
		{
			delete polyLinePoint[i];
		}
	}

	PolyLine& PolyLine::operator=(const PolyLine& rhs)
	{
		mCnt = rhs.mCnt;
		PolyLine* tmpPl = new PolyLine();
		for (int i = 0; i < 10; i++)
		{
			memcpy(tmpPl->polyLinePoint[i], rhs.polyLinePoint[i], sizeof(Point));
			memcpy(polyLinePoint[i], tmpPl->polyLinePoint[i], sizeof(Point));
		}
		delete tmpPl;

		return *this;
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mCnt < 10)
		{
			Point* tPoint = new Point(x, y);
			memcpy(polyLinePoint[mCnt++], tPoint, sizeof(Point));
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
			*polyLinePoint[mCnt++] = *point;

			//Point* p1 = new Point();
			//memcpy(p1, point, sizeof(Point));
			//memcpy(polyLinePoint[mCnt++], p1, sizeof(Point));
			//delete p1;

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
					memcpy(polyLinePoint[cnt], polyLinePoint[cnt + 1], sizeof(Point));
				}
			}
			//Point* tp = new Point();
			//memcpy(mPoint[mCnt - 1], tp, sizeof(Point));
			//delete tp;
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
			float minX = polyLinePoint[0]->GetX();
			float maxX = polyLinePoint[0]->GetX();
			float minY = polyLinePoint[0]->GetY();
			float maxY = polyLinePoint[0]->GetY();

			for (unsigned int i = 0; i < mCnt; i++)
			{
				if (polyLinePoint[i]->GetX() < minX)
				{
					minX = polyLinePoint[i]->GetX();
				}
				if (polyLinePoint[i]->GetX() > maxX)
				{
					maxX = polyLinePoint[i]->GetX();
				}
				if (polyLinePoint[i]->GetY() < minY)
				{
					minY = polyLinePoint[i]->GetY();
				}
				if (polyLinePoint[i]->GetY() > maxY)
				{
					maxY = polyLinePoint[i]->GetY();
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
		if (polyLinePoint[i] == nullptr || i >= mCnt)
		{
			return nullptr;
		}

		float xVal = polyLinePoint[i]->GetX();
		float yVal = polyLinePoint[i]->GetY();

		return new Point(xVal, yVal);
	}


}