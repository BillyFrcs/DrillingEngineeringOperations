using System;
using System.Collections.Generic;
using System.Globalization;
using System.Runtime.InteropServices;
using System.Text;

using DrillingSystem.DrillingConsole.Interfaces;
using DrillingSystem.DrillingConsole.Models;
using DrillingSystem.DrillingConsole.Utils;

namespace DrillingSystem.DrillingConsole.Services
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
                    MudWeightPpg = 0,
                    TrueVerticalDepthFeet = 0,
                    MudWeightKgM3 = 0,
                    TrueVerticalDepthMeter = 0
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

            double mudWeight = Validations.ReadNumericLine("\nEnter Mud Weight (ppg): ");

            double trueVerticalDepth = Validations.ReadNumericLine("Enter TVD (ft): ");

            _hydrostaticPressureModel.MudWeightPpg = mudWeight;
            _hydrostaticPressureModel.TrueVerticalDepthFeet = trueVerticalDepth;

            double imperialHP = ImperialHydrostaticPressureCalculation(hpEngine, _hydrostaticPressureModel.MudWeightPpg,  _hydrostaticPressureModel.TrueVerticalDepthFeet);

            Console.WriteLine($"\nImperial Hydrostatic Pressure (HP) result is {imperialHP} psi");

            DestroyHydrostaticPressure(hpEngine);
        }

        public void MetricHydrostaticPressureResult()
        {
            IntPtr hpEngine = CreateHydrostaticPressure();

            ObjectDisposedException.ThrowIf(hpEngine == IntPtr.Zero, nameof(hpEngine));

            double mudWeight = Validations.ReadNumericLine("\nEnter Mud Weight (kg/m³): ");

            double trueVerticalDepth = Validations.ReadNumericLine("Enter TVD (m): ");

            _hydrostaticPressureModel.MudWeightKgM3 = mudWeight;
            _hydrostaticPressureModel.TrueVerticalDepthMeter = trueVerticalDepth;

            double metricHP = MetricHydrostaticPressureCalculation(hpEngine, _hydrostaticPressureModel.MudWeightKgM3, _hydrostaticPressureModel.TrueVerticalDepthMeter);

            Console.WriteLine($"\nMetric Hydrostatic Pressure (HP) result is {metricHP} bar");

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