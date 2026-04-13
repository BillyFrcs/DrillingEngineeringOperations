using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace DrillingSystem.DrillingConsole.Interfaces
{
    internal interface IEquivalentCirculatingDensity
    {
        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr CreateDrillingEngine();

        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern double ImperialEquivalentCirculatingDensityCalculation(IntPtr drillingEngine, double mudWeight_ppg, double pressureLoss_psi, double trueVerticalDepth_feet);

        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern double MetricEquivalentCirculatingDensityCalculation(IntPtr drillingEngine, double mudWeight_ppg, double pressureLoss_psi, double trueVerticalDepth_feet);

        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void DestroyDrillingEngine(IntPtr drillingEngine);

        public void ImperialEquivalentCirculatingDensityResult();

        public void MetricEquivalentCirculatingDensityResult();
    }
}