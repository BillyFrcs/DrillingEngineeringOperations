using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

using DrillingSystem.Interfaces;
using DrillingSystem.Models;

namespace DrillingSystem.Services
{
    internal class HydrostaticPressureService : IHydrostaticPressure
    {
        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr CreateDrillingEngine();

        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern double ImperialHydrostaticPressureCalculation(IntPtr drillingEngine, double mudWeight_ppg, double trueVerticalDepth_feet);

        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern double MetricHydrostaticPressureCalculation(IntPtr drillingEngine, double mudWeight_ppg, double trueVerticalDepth_feet);

        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void DestroyDrillingEngine(IntPtr drillingEngine);

        private HydrostaticPressure _hydrostaticPressureModel;

        public HydrostaticPressureService()
        {
            if (_hydrostaticPressureModel == null)
            {
                _hydrostaticPressureModel = new HydrostaticPressure
                {
                    MudWeightPpg = 12.2,
                    TrueVerticalDepthFeet = 12000,
                    MudWeightSg = 1200,
                    TrueVerticalDepthMeter = 2440
                };
            }
            else
            {
                throw new InvalidOperationException("HydrostaticPressure model is already initialized.");
            }
        }

        ~HydrostaticPressureService()
        {
        }

        public void ImperialHydrostaticPressureResult()
        {
            IntPtr hpEngine = CreateHydrostaticPressure();

            ObjectDisposedException.ThrowIf(hpEngine == IntPtr.Zero, nameof(hpEngine));

            double imperialHP = ImperialHydrostaticPressureCalculation(hpEngine, _hydrostaticPressureModel.MudWeightPpg,  _hydrostaticPressureModel.TrueVerticalDepthFeet);

            Console.WriteLine($"Imperial Hydrostatic Pressure result = {imperialHP} psi");

            DestroyHydrostaticPressure(hpEngine);
        }

        public void MetricHydrostaticPressureResult()
        {
            IntPtr hpEngine = CreateHydrostaticPressure();

            ObjectDisposedException.ThrowIf(hpEngine == IntPtr.Zero, nameof(hpEngine));

            double metricHP = MetricHydrostaticPressureCalculation(hpEngine, _hydrostaticPressureModel.MudWeightSg, _hydrostaticPressureModel.TrueVerticalDepthMeter);

            Console.WriteLine($"Metric Hydrostatic Pressure result = {metricHP} bar \n");

            DestroyHydrostaticPressure(hpEngine);
        }

        private static IntPtr CreateHydrostaticPressure()
        {
            return CreateDrillingEngine();
        }

        private static void DestroyHydrostaticPressure(IntPtr hpEngine)
        {
            DestroyDrillingEngine(hpEngine);
        }
    }
}
