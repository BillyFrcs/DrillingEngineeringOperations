using System;
using System.Runtime.InteropServices;

using DrillingSystem.Services;
using DrillingSystem.Interfaces;

namespace DrillingSystem
{
    class Program
    {
        static void Main(string[] args)
        {
            EquivalentCirculatingDensityService EcdService = new();

            // IEquivalentCirculatingDensity ecd = new EquivalentCirculatingDensityService();

            EcdService.ImperialEquivalentCirculatingDensityResult();

            EcdService.MetricEquivalentCirculatingDensityResult();
        }
    }
}