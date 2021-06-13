#pragma once

#include "Vehicle.h"

namespace assignment2
{
	class DeusExMachina
	{
	public:
		static DeusExMachina* GetInstance();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;

	private:
		DeusExMachina() = default;
		DeusExMachina(const DeusExMachina&) = delete;
		DeusExMachina& operator=(const DeusExMachina&) = delete;
		DeusExMachina(DeusExMachina&&) = delete;
		DeusExMachina& operator=(DeusExMachina&&) = delete;

		const unsigned int MAXCOUNT = 10;
		Vehicle* mVehicle[10] {nullptr};
		unsigned int deusCnt = 0;
	};
}