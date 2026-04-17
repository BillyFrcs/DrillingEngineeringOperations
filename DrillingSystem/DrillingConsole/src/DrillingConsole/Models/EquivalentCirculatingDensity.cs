using System;
using System.Collections.Generic;
using System.Text;

namespace DrillingSystem.DrillingConsole.Models
{
    internal class EquivalentCirculatingDensity
    {
        // Properties for Imperial Units
        public double MudWeightPpg { get; set; } // ppg
        public double PressureLossPsi { get; set; } // psi
        public double TrueVerticalDepthFeet { get; set; } // feet

        // Properties for Metric Units
        public double MudWeightKgM3 { get; set; } // kg/m³
        public double PressureLosskPa { get; set; } // kPa
        public double TrueVerticalDepthMeter { get; set; } // meter
    }
}