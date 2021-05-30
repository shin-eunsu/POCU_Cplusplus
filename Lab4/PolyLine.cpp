#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mCnt(0)
	{
		mPoint = new Point[mCnt];
		//mPoint = new Point[MAXLENGTH];
		//memset(mPoint, NULL, sizeof(Point) * MAXLENGTH);
	}

	PolyLine::PolyLine(const PolyLine& other)
		: mCnt(other.mCnt)
	{
		mPoint = new Point[other.mCnt];
		memcpy(mPoint, other.mPoint, sizeof(Point) * other.mCnt);
		
		//mPoint = new Point[MAXLENGTH];
		//memcpy(mPoint, other.mPoint, sizeof(Point) * MAXLENGTH);
	}

	PolyLine& PolyLine::operator=(const PolyLine& rhs)
	{
		mCnt = rhs.mCnt;
		PolyLine* tmpPl = new PolyLine();
		memcpy(tmpPl->mPoint, rhs.mPoint, sizeof(Point) * rhs.mCnt);

		delete[] mPoint;
		mPoint = new Point[rhs.mCnt];
		memcpy(mPoint, tmpPl, sizeof(Point) * rhs.mCnt);

		return *this;
	}

	PolyLine::~PolyLine()
	{
		delete[] mPoint;
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mCnt < 10)
		{
			//mPoint[mCnt++] = Point(x, y);

			Point* tmpPoint = new Point[++mCnt];
			memcpy(tmpPoint, mPoint, sizeof(Point) * (mCnt - 1));
			tmpPoint[mCnt - 1] = Point(x, y);

			delete[] mPoint;
			mPoint = new Point[mCnt];
			memcpy(mPoint, tmpPoint, sizeof(Point) * mCnt);
			delete[] tmpPoint;

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
			//mPoint[mCnt++] = Point(point->GetX(), point->GetY());

			Point* tmpPoint = new Point[++mCnt];
			memcpy(tmpPoint, mPoint, sizeof(Point) * (mCnt - 1));
			tmpPoint[mCnt - 1] = Point(point->GetX(), point->GetY());

			delete[] mPoint;
			mPoint = new Point[mCnt];
			memcpy(mPoint, tmpPoint, sizeof(Point) * mCnt);
			delete[] tmpPoint;

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
					mPoint[cnt] = mPoint[cnt + 1];
				}
			}
			Point* tmpPoint = new Point[--mCnt];
			memcpy(tmpPoint, mPoint, sizeof(Point) * mCnt);
			memset(mPoint, (int)NULL, sizeof(Point) * (mCnt + 1));
			
			delete[] mPoint;
			mPoint = new Point[mCnt];
			memcpy(mPoint, tmpPoint, sizeof(Point) * mCnt);
			delete[] tmpPoint;

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
			float minX = mPoint[0].GetX();
			float maxX = mPoint[0].GetX();
			float minY = mPoint[0].GetY();
			float maxY = mPoint[0].GetY();

			for (unsigned int i = 0; i < mCnt; i++)
			{
				if (mPoint[i].GetX() < minX)
				{
					minX = mPoint[i].GetX();
				}
				if (mPoint[i].GetX() > maxX)
				{
					maxX = mPoint[i].GetX();
				}
				if (mPoint[i].GetY() < minY)
				{
					minY = mPoint[i].GetY();
				}
				if (mPoint[i].GetY() > maxY)
				{
					maxY = mPoint[i].GetY();
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
		float xVal = mPoint[i].GetX();
		float yVal = mPoint[i].GetY();

		return new Point(xVal, yVal);
	}

	
}