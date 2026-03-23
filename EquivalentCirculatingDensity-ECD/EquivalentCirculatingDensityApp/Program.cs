using System;
using System.Runtime.InteropServices;

class Program
{
    [DllImport("ECDCalculation/EquivalentCirculatingDensityCalculation.dll", CallingConvention = CallingConvention.Cdecl)]
    public static extern double CalculateECD(double mudWeight, double pressureLoss, double trueVerticalDepth);

    public static void ECDResult()
    {
        double mudWeight = 12.2; // ppg
        double pressureLoss = 400; // psi
        double trueVerticalDepth = 12000; // ft

        double ecd = CalculateECD(mudWeight, pressureLoss, trueVerticalDepth);

        Console.WriteLine($"ECD Result: {ecd} ppg");
    }

    public static void ECDForwardCirculation()
    {
        double fludWeight = 12; // ppg
        double frictionPressure = 1000; // psi
        double measurementDepth = 10000; // ft

        double ecd = CalculateECD(fludWeight, frictionPressure, measurementDepth);

        Console.WriteLine($"ECD Forward Circulation: {ecd} ppg");
    }

    static void Main()
    {
        Program.ECDResult();

        Program.ECDForwardCirculation();
    }
}