using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace DrillingSystem.DrillingConsole.Interfaces
{
    internal interface IKillWeightMud
    {
        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr CreateDrillingEngine();

        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern double ImperialKillWeightMudCalculation(IntPtr drillingEngine, double currentMudWeight_ppg, double SIDPP_psi, double trueVerticalDepth_feet);

        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern double MetricKillWeightMudCalculation(IntPtr drillingEngine, double currentMudWeight_kg_m3, double SIDPP_KPa, double trueVerticalDepth_meter);

        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void DestroyDrillingEngine(IntPtr drillingEngine);

        public void ImperialKillWeightMudResult();

        public void MetricKillWeightMudResult();
    }
}