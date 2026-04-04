#pragma once

#ifndef OIL_WELL_BLOCK_AND_TACKLE_SYSTEM_H
#define OIL_WELL_BLOCK_AND_TACKLE_SYSTEM_H

namespace HoistingSystem
{
	class OilWellBlockAndTackleSystem
	{
		public:
			OilWellBlockAndTackleSystem() = default;

			~OilWellBlockAndTackleSystem() = default;

            long double HookLoadVelocity();

            long double PowerAtDrum();

            long double MotorPower();

            long double MarketDataMotorPower();

            long double MarketDataMotorSpeed();

            long double FastLineSpeed();

            long double DrumSpeed();

            long double GearRatio();
	};
}

#endif // OIL_WELL_BLOCK_AND_TACKLE_SYSTEM_H