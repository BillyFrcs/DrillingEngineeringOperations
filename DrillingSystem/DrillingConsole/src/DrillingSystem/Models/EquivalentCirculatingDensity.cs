using System;
using System.Collections.Generic;
using System.Text;
using DrillingSystem.Interfaces;

namespace DrillingSystem.Models
{
    internal class EquivalentCirculatingDensity
    {
        // Properties for Imperial Units
        public double MudWeightPpg { get; set; } // ppg
        public double PressureLossPsi { get; set; } // psi
        public double TrueVerticalDepthFeet { get; set; } // feet

        // Properties for Metric Units
        public double MudWeightSg { get; set; } // sg or kg/m^3
        public double PressureLossBar { get; set; } // bar or kPa
        public double TrueVerticalDepthMeter { get; set; } // meter
    }
}
