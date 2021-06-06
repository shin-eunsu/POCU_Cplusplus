#include "Lawn.h"
#include <cmath>

namespace lab5
{
	Lawn::Lawn()
	{
	}

	Lawn::~Lawn()
	{
	}

	unsigned int GetArea()
	{
		return 0;
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		double GrassCount = GetArea() / 0.3;
		double GrassUnitPrice = 0;
		unsigned int TotalPrice = 0;

		switch (grassType)
		{
		case lab5::BERMUDA:
			GrassUnitPrice = 800 * 0.003;
			break;
		case lab5::BAHIA:
			GrassUnitPrice = 500 * 0.003;
			break;
		case lab5::BENTGRASS:
			GrassUnitPrice = 300 * 0.003;
			break;
		case lab5::PERENNIAL_RYEGRASS:
			GrassUnitPrice = 250 * 0.003;
			break;
		case lab5::ST_AUGUSTINE:
			GrassUnitPrice = 450 * 0.003;
			break;
		}

		TotalPrice = round(GrassCount * GrassUnitPrice);
		
		return TotalPrice;
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{		
		double GrassCount = GetArea() / 0.3;
		return static_cast<unsigned int>(ceil(GrassCount));
	}
}