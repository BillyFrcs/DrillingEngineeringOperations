using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

using DrillingSystem.DrillingConsole.Interfaces;
using DrillingSystem.DrillingConsole.Models;

namespace DrillingSystem.DrillingConsole.Services
{
    internal class KillWeightMudService : IKillWeightMud
    {
        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr CreateDrillingEngine();

        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern double ImperialKillWeightMudCalculation(IntPtr drillingEngine, double currentMudWeight_ppg, double SIDPP_psi, double trueVerticalDepth_feet);

        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern double MetricKillWeightMudCalculation(IntPtr drillingEngine, double currentMudWeight_kg_m3, double SIDPP_KPa, double trueVerticalDepth_meter);

        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void DestroyDrillingEngine(IntPtr drillingEngine);

        private KillWeightMud _killWeightMudModel;

        public KillWeightMudService()
        {
            if (_killWeightMudModel == null)
            {
                _killWeightMudModel = new KillWeightMud()
                {
                    MudWeightPpg = 0,
                    SIDPPPsi = 0,
                    TrueVerticalDepthFeet = 0,
                    MudWeightKgM3 = 0,
                    SIDPPkPa = 0,
                    TrueVerticalDepthMeter = 0
                };
            }
            else
            {
                throw new InvalidOperationException("KillWeightMud model is already initialized.");
            }
        }

        ~KillWeightMudService()
        {
        }

        public void ImperialKillWeightMudResult()
        {
            IntPtr kwmEngine = CreateKillWeightMud();

            ObjectDisposedException.ThrowIf(kwmEngine == IntPtr.Zero, nameof(kwmEngine));

            Console.Write("\nEnter Mud Weight (ppg): ");

            double mudWeight = double.Parse(Console.ReadLine() ?? string.Empty);

            Console.Write("Enter SIDPP (psi): ");

            double SIDPP = double.Parse(Console.ReadLine() ?? string.Empty);

            Console.Write("Enter TVD (ft): ");

            double trueVerticalDepth = double.Parse(Console.ReadLine() ?? string.Empty);

            _killWeightMudModel.MudWeightPpg = mudWeight;
            _killWeightMudModel.SIDPPPsi = SIDPP;
            _killWeightMudModel.TrueVerticalDepthFeet = trueVerticalDepth;

            double imperialKwm = ImperialKillWeightMudCalculation(kwmEngine, _killWeightMudModel.MudWeightPpg, _killWeightMudModel.SIDPPPsi, _killWeightMudModel.TrueVerticalDepthFeet);

            Console.WriteLine($"\nImperial Kill Weight Mud (KWM) result is {imperialKwm} ppg");

            DestroyKillWeightMud(kwmEngine);
        }

        public void MetricKillWeightMudResult()
        {
            IntPtr kwmEngine = CreateKillWeightMud();

            ObjectDisposedException.ThrowIf(kwmEngine == IntPtr.Zero, nameof(kwmEngine));

            Console.Write("\nEnter Mud Weight (kg/m³): ");

            double mudWeight = double.Parse(Console.ReadLine() ?? string.Empty);

            Console.Write("Enter SIDPP (kPa): ");

            double SIDPP = double.Parse(Console.ReadLine() ?? string.Empty);

            Console.Write("Enter TVD (m): ");

            double trueVerticalDepth = double.Parse(Console.ReadLine() ?? string.Empty);

            _killWeightMudModel.MudWeightKgM3 = mudWeight;
            _killWeightMudModel.SIDPPkPa = SIDPP;
            _killWeightMudModel.TrueVerticalDepthMeter = trueVerticalDepth;

            double metricKwm = MetricKillWeightMudCalculation(kwmEngine, _killWeightMudModel.MudWeightKgM3, _killWeightMudModel.SIDPPkPa, _killWeightMudModel.TrueVerticalDepthMeter);

            Console.WriteLine($"\nMetric Kill Weight Mud (KWM) result is {metricKwm} kg/m³");

            DestroyKillWeightMud(kwmEngine);
        }

        private static IntPtr CreateKillWeightMud()
        {
            return CreateDrillingEngine();
        }

        private static void DestroyKillWeightMud(IntPtr kwmEngine)
        {
            DestroyDrillingEngine(kwmEngine);
        }
    }
}