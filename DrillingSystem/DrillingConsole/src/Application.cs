using System;
using System.Collections.Generic;
using System.Text;

using DrillingSystem.DrillingConsole.Services;
using DrillingSystem.DrillingConsole.Utils;

namespace DrillingSystem.DrillingConsole
{
    internal class Application
    {
        public static void Run()
        {
            bool isRunning = true;

            while (isRunning)
            {
                Console.Clear();

                Console.WriteLine("=== Drilling System: Well Control Operations === \n");

                Console.WriteLine("--- Main Menu ---");
                Console.WriteLine("1. Hydrostatic Pressure (HP)");
                Console.WriteLine("2. Equivalent Circulating Density (ECD)");
                Console.WriteLine("3. Kill Weight Mud (KWM)");
                Console.WriteLine("4. Exit");
                
                Console.Write("\nEnter your choice (1 - 4): ");

                string userChoice = Console.ReadLine() ?? string.Empty;

                Console.WriteLine();

                switch (userChoice)
                {
                    case "1":
                        HydrostaticPressureMenu();

                        break;

                    case "2":
                        EquivalentCirculatingDensityMenu();

                        break;

                    case "3":
                        KillWeightMudMenu();

                        break;

                    case "4":
                        Console.WriteLine("Shutting down simulator. Safe operations.");
                        
                        isRunning = false;
                        
                        break;

                    default:
                        Console.WriteLine("ERROR: Invalid selection. Please choose a number between 1 and 4.");

                        Pause();

                        break;
                }
            }
        }

        private static int UnitChoice()
        {
            Console.WriteLine("Choose Unit:");
            Console.WriteLine("1. Imperial");
            Console.WriteLine("2. Metric");
            
            Console.Write("\nChoose: ");

            return Validations.ParseNumericLine();
        }

        private static void Pause()
        {
            Console.WriteLine("\nPress any key...");

            Console.ReadKey();
        }

        private static void HydrostaticPressureMenu()
        {
            HydrostaticPressureService hpService = new();

            int unitChoice = UnitChoice();

            if (unitChoice == 1)
            {
                hpService.ImperialHydrostaticPressureResult();
            }
            else if (unitChoice == 2) 
            {
                hpService.MetricHydrostaticPressureResult();
            }
            else
            {
                Console.WriteLine("ERROR: Invalid unit selection. Please choose 1 for Imperial or 2 for Metric.");
            }

            Pause();
        }

        private static void EquivalentCirculatingDensityMenu()
        {
            EquivalentCirculatingDensityService ecdService = new();

            int unitChoice = UnitChoice();

            if (unitChoice == 1)
            {
                ecdService.ImperialEquivalentCirculatingDensityResult();
            }
            else if (unitChoice == 2)
            {
                ecdService.MetricEquivalentCirculatingDensityResult();
            }
            else
            {
                Console.WriteLine("ERROR: Invalid unit selection. Please choose 1 for Imperial or 2 for Metric.");
            }

            Pause();
        }

        private static void KillWeightMudMenu()
        {
            KillWeightMudService kwmService = new();

            int unitChoice = UnitChoice();

            if (unitChoice == 1)
            {
                kwmService.ImperialKillWeightMudResult();
            }
            else if (unitChoice == 2)
            {
                kwmService.MetricKillWeightMudResult();
            }
            else
            {
                Console.WriteLine("ERROR: Invalid unit selection. Please choose 1 for Imperial or 2 for Metric.");
            }

            Pause();
        }
    }
}