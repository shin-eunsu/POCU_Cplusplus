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
		double grassCount = GetArea() / 0.3;
		double grassUnitPrice = 0;
		unsigned int totalPrice = 0;

		switch (grassType)
		{
		case lab5::BERMUDA:
			grassUnitPrice = 800 * 0.003;
			break;
		case lab5::BAHIA:
			grassUnitPrice = 500 * 0.003;
			break;
		case lab5::BENTGRASS:
			grassUnitPrice = 300 * 0.003;
			break;
		case lab5::PERENNIAL_RYEGRASS:
			grassUnitPrice = 250 * 0.003;
			break;
		case lab5::ST_AUGUSTINE:
			grassUnitPrice = 450 * 0.003;
			break;
		}

		totalPrice = round(grassCount * grassUnitPrice);
		
		return totalPrice;
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{		
		double grassCount = GetArea() / 0.3;
		return static_cast<unsigned int>(ceil(grassCount));
	}
}