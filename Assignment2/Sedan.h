#pragma once
#include "Vehicle.h"
#include "IDrivable.h"
#include "Trailer.h"

namespace assignment2
{
	class Trailer;

	class Sedan : public Vehicle, public IDrivable
	{
	public:
		Sedan();
		~Sedan();

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();
		unsigned int GetDriveSpeed() const;
		unsigned int GetMaxSpeed() const;

	private:
		const Trailer* mTrailer {nullptr};
	};
}