using System;
using System.Collections.Generic;
using System.Text;

using DrillingSystem.Services;

namespace DrillingSystem
{
    internal class Application
    {
        public static void Run()
        {
            Application.EquivalentCirculatingDensity();
            Application.HydrostaticPressure();
        }

        public static void EquivalentCirculatingDensity()
        {
            EquivalentCirculatingDensityService ecdService = new();

            // IEquivalentCirculatingDensity ecd = new EquivalentCirculatingDensityService();

            ecdService.ImperialEquivalentCirculatingDensityResult();
            ecdService.MetricEquivalentCirculatingDensityResult();
        }

        public static void HydrostaticPressure()
        {
            HydrostaticPressureService hpService = new();

            hpService.ImperialHydrostaticPressureResult();
            hpService.MetricHydrostaticPressureResult();
        }
    }
}
