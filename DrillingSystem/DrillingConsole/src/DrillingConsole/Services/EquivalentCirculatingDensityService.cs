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

        private EquivalentCirculatingDensity _equivalentCirculatingDensityModel;

        public EquivalentCirculatingDensityService()
        {
            if (_equivalentCirculatingDensityModel == null)
            {
                // EcdModel = new();

                _equivalentCirculatingDensityModel = new EquivalentCirculatingDensity
                {
                    MudWeightPpg = 0,
                    PressureLossPsi = 0,
                    TrueVerticalDepthFeet = 0,
                    MudWeightKgM3 = 0,
                    PressureLosskPa = 0,
                    TrueVerticalDepthMeter = 0
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

            double mudWeight = Validations.ReadNumericLine("\nEnter Mud Weight (ppg): ");

            double pressureLoss = Validations.ReadNumericLine("Enter Pressure Loss (psi): ");

            double trueVerticalDepth = Validations.ReadNumericLine("Enter TVD (ft): ");

            _equivalentCirculatingDensityModel.MudWeightPpg = mudWeight;
            _equivalentCirculatingDensityModel.PressureLossPsi = pressureLoss;
            _equivalentCirculatingDensityModel.TrueVerticalDepthFeet = trueVerticalDepth;

            double imperialEcd = ImperialEquivalentCirculatingDensityCalculation(ecdEngine, _equivalentCirculatingDensityModel.MudWeightPpg, _equivalentCirculatingDensityModel.PressureLossPsi, _equivalentCirculatingDensityModel.TrueVerticalDepthFeet);

            Console.WriteLine($"\nImperial Equivalent Circulating Density (ECD) result is {imperialEcd} ppg");

            DestroyEquivalentCirculatingDensity(ecdEngine);
        }

        public void MetricEquivalentCirculatingDensityResult()
        {
            IntPtr ecdEngine = CreateEquivalentCirculatingDensity();

            ObjectDisposedException.ThrowIf(ecdEngine == IntPtr.Zero, nameof(ecdEngine));

            double mudWeight = Validations.ReadNumericLine("\nEnter Mud Weight (kg/m³): ");

            double pressureLoss = Validations.ReadNumericLine("Enter Pressure Loss (kPa): ");

            double trueVerticalDepth = Validations.ReadNumericLine("Enter TVD (m): ");

            _equivalentCirculatingDensityModel.MudWeightKgM3 = mudWeight;
            _equivalentCirculatingDensityModel.PressureLosskPa = pressureLoss;
            _equivalentCirculatingDensityModel.TrueVerticalDepthMeter = trueVerticalDepth;

            double metricEcd = MetricEquivalentCirculatingDensityCalculation(ecdEngine, _equivalentCirculatingDensityModel.MudWeightKgM3, _equivalentCirculatingDensityModel.PressureLosskPa, _equivalentCirculatingDensityModel.TrueVerticalDepthMeter);

            Console.WriteLine($"\nMetric Equivalent Circulating Density (ECD) result is {metricEcd} kg/m³ \n");

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