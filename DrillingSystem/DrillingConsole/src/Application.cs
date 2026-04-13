using System;
using System.Collections.Generic;
using System.Text;

using DrillingSystem.DrillingConsole.Services;

namespace DrillingSystem.DrillingConsole
{
    internal class Application
    {
        public static void Run()
        {
            Application.EquivalentCirculatingDensity();

            Application.HydrostaticPressure();
            
            Application.KillWeightMud();
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

        public static void KillWeightMud()
        {
            KillWeightMudService kwmService = new();

            kwmService.ImperialKillWeightMudResult();

            kwmService.MetricKillWeightMudResult();
        }
    }
}