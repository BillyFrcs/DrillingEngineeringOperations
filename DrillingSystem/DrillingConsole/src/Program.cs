using System;
using System.Runtime.InteropServices;

namespace DrillingConsole
{
    class Program
    {
        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr CreateDrillingEngine();

        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern double ImperialEquivalentCirculatingDensityCalculation(IntPtr drillingEngine, double mudWeight_ppg, double pressureLoss_psi, double trueVerticalDepth_feet);

        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern double MetricEquivalentCirculatingDensityCalculation(IntPtr drillingEngine, double mudWeight_ppg, double pressureLoss_psi, double trueVerticalDepth_feet);

        [DllImport("DrillingEngine.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void DestroyDrillingEngine(IntPtr drillingEngine);

        public static void ImperialEquivalentCirculatingDensityResult()
        {
            IntPtr drillingEngine = CreateDrillingEngine();

            double mudWeight_ppg = 12.2; // ppg
            double pressureLoss_psi = 400; // psi
            double trueVerticalDepth_feet = 12000; // feet

            double ecd = ImperialEquivalentCirculatingDensityCalculation(drillingEngine, mudWeight_ppg, pressureLoss_psi, trueVerticalDepth_feet);

            Console.WriteLine($"Imperial ECD Result: {ecd} ppg");
        }

        public static void MetricEquivalentCirculatingDensityResult()
        {
            IntPtr drillingEngine = CreateDrillingEngine();

            double mudWeight_sg = 1200; // sg or kg/m^3
            double pressureLoss_bar = 2760; // bar or kPa
            double trueVerticalDepth_meter = 2440; // meter

            double ecd = MetricEquivalentCirculatingDensityCalculation(drillingEngine, mudWeight_sg, pressureLoss_bar, trueVerticalDepth_meter);

            Console.WriteLine($"Metric ECD Result: {ecd} sg");
        }

        static void Main()
        {
            Program.ImperialEquivalentCirculatingDensityResult();

            Program.MetricEquivalentCirculatingDensityResult();
        }
    }
}