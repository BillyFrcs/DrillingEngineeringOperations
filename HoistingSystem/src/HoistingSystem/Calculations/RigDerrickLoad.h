#pragma once

#include <iomanip>

#ifndef RIG_DERRICK_LOAD_H
#define RIG_DERRICK_LOAD_H

namespace HoistingSystem
{
	class RigDerrickLoad
	{
	public:
		RigDerrickLoad() = default;

		~RigDerrickLoad() = default;

        long double HookLoad();

        long double FastLineTension();

        long double DeadLineTension();

		long double DerrickLoadUnderDynamicConditions();
	};
}

#endif // RIG_DERRICK_LOAD_H