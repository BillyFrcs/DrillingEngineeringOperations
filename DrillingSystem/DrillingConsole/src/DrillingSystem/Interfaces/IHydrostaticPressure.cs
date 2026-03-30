using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace DrillingSystem.Interfaces
{
    internal interface IHydrostaticPressure
    {
        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr CreateDrillingEngine();

        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern double ImperialHydrostaticPressureCalculation(IntPtr drillingEngine, double mudWeight_ppg, double trueVerticalDepth_feet);

        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern double MetricHydrostaticPressureCalculation(IntPtr drillingEngine, double mudWeight_ppg, double trueVerticalDepth_feet);

        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void DestroyDrillingEngine(IntPtr drillingEngine);

        public void ImperialHydrostaticPressureResult();

        public void MetricHydrostaticPressureResult();
    }
}
