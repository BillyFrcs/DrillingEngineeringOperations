using System;
using System.Runtime.InteropServices;

using DrillingSystem.Core.Interfaces;
using DrillingSystem.Core.Services;

namespace DrillingSystem
{
    class Program
    {
        static void Main(string[] args)
        {
            EquivalentCirculatingDensityService ecdService = new();

            // IEquivalentCirculatingDensity ecd = new EquivalentCirculatingDensityService();

            ecdService.ImperialEquivalentCirculatingDensityResult();

            ecdService.MetricEquivalentCirculatingDensityResult();
        }
    }
}