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

        private KillWeightMud _kwmModel;

        public KillWeightMudService()
        {
            if (_kwmModel == null)
            {
                _kwmModel = new KillWeightMud()
                {
                    MudWeightPpg = 9.5,
                    SIDPPPsi = 500,
                    TrueVerticalDepthFeet = 9000,
                    MudWeightKgM3 = 1140,
                    SIDPPkPa = 3450,
                    TrueVerticalDepthMeter = 2700
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

            double imperialKwm = ImperialKillWeightMudCalculation(kwmEngine, _kwmModel.MudWeightPpg, _kwmModel.SIDPPPsi, _kwmModel.TrueVerticalDepthFeet);

            Console.WriteLine($"Imperial Kill Weight Mud (KWM) result is {imperialKwm} ppg");

            DestroyKillWeightMud(kwmEngine);
        }

        public void MetricKillWeightMudResult()
        {
            IntPtr kwmEngine = CreateKillWeightMud();

            ObjectDisposedException.ThrowIf(kwmEngine == IntPtr.Zero, nameof(kwmEngine));

            double metricKwm = MetricKillWeightMudCalculation(kwmEngine, _kwmModel.MudWeightKgM3, _kwmModel.SIDPPkPa, _kwmModel.TrueVerticalDepthMeter);

            Console.WriteLine($"Metric Kill Weight Mud (KWM) result is {metricKwm} kg/m³ \n");

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