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
			PolyLinePoint[i] = nullptr;
		}
	}

	PolyLine::PolyLine(const PolyLine& other)
		: mCnt(other.mCnt)
	{
		for (unsigned int i = 0; i < other.mCnt; i++)
		{
			PolyLinePoint[i] = new Point();
			memcpy(PolyLinePoint[i], other.PolyLinePoint[i], sizeof(Point));
		}
	}

	PolyLine::~PolyLine()
	{
		for (int i = 0; i < mCnt; i++)
		{
			delete PolyLinePoint[i];
		}
	}

	PolyLine& PolyLine::operator=(const PolyLine& rhs)
	{
		mCnt = rhs.mCnt;
		//PolyLine* tmpPl = new PolyLine();
		for (int i = 0; i < rhs.mCnt; i++)
		{
			PolyLinePoint[i] = new Point();
			PolyLinePoint[i] = rhs.PolyLinePoint[i];
			//memcpy(tmpPl->PolyLinePoint[i], rhs.PolyLinePoint[i], sizeof(Point));
			//memcpy(PolyLinePoint[i], tmpPl->PolyLinePoint[i], sizeof(Point));
		}
		//delete tmpPl;

		return *this;
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mCnt < 10)
		{
			PolyLinePoint[mCnt] = new Point(x, y);
			mCnt++;
			//Point* tPoint = new Point(x, y);
			//memcpy(PolyLinePoint[mCnt++], tPoint, sizeof(Point));
			//delete tPoint;

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
			PolyLinePoint[mCnt] = new Point();
			*PolyLinePoint[mCnt++] = *point;
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
					memcpy(PolyLinePoint[cnt], PolyLinePoint[cnt + 1], sizeof(Point));
				}
			}
			PolyLinePoint[mCnt - 1] = nullptr;
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
			float minX = PolyLinePoint[0]->GetX();
			float maxX = PolyLinePoint[0]->GetX();
			float minY = PolyLinePoint[0]->GetY();
			float maxY = PolyLinePoint[0]->GetY();

			for (unsigned int i = 0; i < mCnt; i++)
			{
				if (PolyLinePoint[i]->GetX() < minX)
				{
					minX = PolyLinePoint[i]->GetX();
				}
				if (PolyLinePoint[i]->GetX() > maxX)
				{
					maxX = PolyLinePoint[i]->GetX();
				}
				if (PolyLinePoint[i]->GetY() < minY)
				{
					minY = PolyLinePoint[i]->GetY();
				}
				if (PolyLinePoint[i]->GetY() > maxY)
				{
					maxY = PolyLinePoint[i]->GetY();
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
		if (PolyLinePoint[i] == nullptr || i >= mCnt)
		{
			return nullptr;
		}

		float xVal = PolyLinePoint[i]->GetX();
		float yVal = PolyLinePoint[i]->GetY();

		return new Point(xVal, yVal);
	}


}