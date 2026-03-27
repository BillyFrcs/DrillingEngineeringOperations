using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

using DrillingSystem.Interfaces;
using DrillingSystem.Models;

namespace DrillingSystem.Services
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

        private EquivalentCirculatingDensity EcdModel;

        public EquivalentCirculatingDensityService()
        {
            if (EcdModel == null)
            {
                // EcdModel = new();

                EcdModel = new EquivalentCirculatingDensity
                {
                    MudWeightPpg = 12.2,
                    PressureLossPsi = 400,
                    TrueVerticalDepthFeet = 12000,
                    MudWeightSg = 1200,
                    PressureLossBar = 2760,
                    TrueVerticalDepthMeter = 2440
                };
            }
            else
            {
                throw new InvalidOperationException("EquivalentCirculatingDensity model is already initialized.");
            }
        }

        public void ImperialEquivalentCirculatingDensityResult()
        {
            IntPtr ecdEngine = CreateEquivalentCirculatingDensity();

            ObjectDisposedException.ThrowIf(ecdEngine == IntPtr.Zero, nameof(ecdEngine));

            double imperialEcd = ImperialEquivalentCirculatingDensityCalculation(ecdEngine, EcdModel.MudWeightPpg, EcdModel.PressureLossPsi, EcdModel.TrueVerticalDepthFeet);

            Console.WriteLine($"Imperial ECD Result: {imperialEcd} ppg");

            DestroyEquivalentCirculatingDensity(ecdEngine);
        }

        public void MetricEquivalentCirculatingDensityResult()
        {
            IntPtr ecdEngine = CreateEquivalentCirculatingDensity();

            ObjectDisposedException.ThrowIf(ecdEngine == IntPtr.Zero, nameof(ecdEngine));

            double metricEcd = MetricEquivalentCirculatingDensityCalculation(ecdEngine, EcdModel.MudWeightSg, EcdModel.PressureLossBar, EcdModel.TrueVerticalDepthMeter);

            Console.WriteLine($"Metric ECD Result: {metricEcd} sg");

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
