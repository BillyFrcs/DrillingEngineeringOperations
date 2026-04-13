using System;
using System.Collections.Generic;
using System.Text;

namespace DrillingSystem.DrillingConsole.Models
{
    internal class HydrostaticPressure
    {
        // Properties for Imperial Units
        public double MudWeightPpg { get; set; } // ppg
        public double TrueVerticalDepthFeet { get; set; } // feet

        // Properties for Metric Units
        public double MudWeightSg { get; set; } // sg or kg/m^3
        public double TrueVerticalDepthMeter { get; set; } // meter
    }
}
