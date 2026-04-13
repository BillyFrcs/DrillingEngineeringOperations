using System;
using System.Collections.Generic;
using System.Text;

namespace DrillingSystem.DrillingConsole.Models
{
    internal class KillWeightMud
    {
        // Properties for Imperial Units
        public double MudWeightPpg { get; set; } // ppg
        public double SIDPPPsi { get; set; } // psi
        public double TrueVerticalDepthFeet { get; set; } // feet

        // Properties for Metric Units
        public double MudWeightKgM3 { get; set; } // kg/m^3
        public double SIDPPkPa { get; set; } // kPa
        public double TrueVerticalDepthMeter { get; set; } // meter
    }
}
