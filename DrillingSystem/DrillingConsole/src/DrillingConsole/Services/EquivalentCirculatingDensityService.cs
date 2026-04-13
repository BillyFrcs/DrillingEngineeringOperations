using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

using DrillingSystem.DrillingConsole.Interfaces;
using DrillingSystem.DrillingConsole.Models;

namespace DrillingSystem.DrillingConsole.Services
{
    internal class EquivalentCirculatingDensityService : IEquivalentCirculatingDensity
    {
        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr CreateDrillingEngine();

        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern double ImperialEquivalentCirculatingDensityCalculation(IntPtr drillingEngine, double mudWeight_ppg, double pressureLoss_psi, double trueVerticalDepth_feet);

        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern double MetricEquivalentCirculatingDensityCalculation(IntPtr drillingEngine, double mudWeight_ppg, double pressureLoss_psi, double trueVerticalDepth_feet);

        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void DestroyDrillingEngine(IntPtr drillingEngine);

        private EquivalentCirculatingDensity _ecdModel;

        public EquivalentCirculatingDensityService()
        {
            if (_ecdModel == null)
            {
                // EcdModel = new();

                _ecdModel = new EquivalentCirculatingDensity
                {
                    MudWeightPpg = 12.2,
                    PressureLossPsi = 400,
                    TrueVerticalDepthFeet = 12000,
                    MudWeightKgM3 = 1200,
                    PressureLosskPa = 2760,
                    TrueVerticalDepthMeter = 2440
                };
            }
            else
            {
                throw new InvalidOperationException("EquivalentCirculatingDensity model is already initialized.");
            }
        }

        ~EquivalentCirculatingDensityService()
        {
        }

        public void ImperialEquivalentCirculatingDensityResult()
        {
            IntPtr ecdEngine = CreateEquivalentCirculatingDensity();

            ObjectDisposedException.ThrowIf(ecdEngine == IntPtr.Zero, nameof(ecdEngine));
                                                                                                                                             
            double imperialEcd = ImperialEquivalentCirculatingDensityCalculation(ecdEngine, _ecdModel.MudWeightPpg, _ecdModel.PressureLossPsi, _ecdModel.TrueVerticalDepthFeet);

            Console.WriteLine($"Imperial Equivalent Circulating Density result = {imperialEcd} ppg");

            DestroyEquivalentCirculatingDensity(ecdEngine);
        }

        public void MetricEquivalentCirculatingDensityResult()
        {
            IntPtr ecdEngine = CreateEquivalentCirculatingDensity();

            ObjectDisposedException.ThrowIf(ecdEngine == IntPtr.Zero, nameof(ecdEngine));

            double metricEcd = MetricEquivalentCirculatingDensityCalculation(ecdEngine, _ecdModel.MudWeightKgM3, _ecdModel.PressureLosskPa, _ecdModel.TrueVerticalDepthMeter);

            Console.WriteLine($"Metric Equivalent Circulating Density result = {metricEcd} kg/m^3 \n");

            DestroyEquivalentCirculatingDensity(ecdEngine);
        }

        private static IntPtr CreateEquivalentCirculatingDensity()
        {
            return CreateDrillingEngine();
        }

        private static void DestroyEquivalentCirculatingDensity(IntPtr ecdEngine)
        {
            DestroyDrillingEngine(ecdEngine);
        }
    }
}