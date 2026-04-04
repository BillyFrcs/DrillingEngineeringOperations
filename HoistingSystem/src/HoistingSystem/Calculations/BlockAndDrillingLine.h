#pragma once

#include <iomanip>

#ifndef BLOCK_AND_DRILLING_LINE_H
#define BLOCK_AND_DRILLING_LINE_H

namespace HoistingSystem
{
	class BlockAndDrillingLine
	{
	public:
		BlockAndDrillingLine() = default;

		~BlockAndDrillingLine() = default;

		long double RequiredTravelingBlockOutput();

        long double RequiredTravelingBlockInput();

        long double HorsePower();

        long double DrawWorksOutput();

        long double PowerDrawWorksOutput();

        long double PowerInput();

        long double HoistingEfficiency();

        long double FastLineVelocity();

        long double TravelingBlockVelocity();

        long double TravelingBlockSpeed();
	};
}

#endif // BLOCK_AND_DRILLING_LINE_H