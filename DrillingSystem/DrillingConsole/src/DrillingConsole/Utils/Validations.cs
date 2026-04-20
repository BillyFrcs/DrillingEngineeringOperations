using System;
using System.Collections.Generic;
using System.Text;

namespace DrillingSystem.DrillingConsole.Utils
{
    internal class Validations
    {
        public Validations() 
        { 
        }

        ~Validations() 
        { 
        }

        public static double ReadNumericLine(string label)
        {
            Console.Write(label);

            StringBuilder input = new StringBuilder();
            
            bool hasDot = false;

            while (true)
            {
                ConsoleKeyInfo key = Console.ReadKey(true);

                // Enter key = finish input
                if (key.Key == ConsoleKey.Enter)
                {
                    // Prevent blank input
                    if (input.Length == 0 || input.ToString() == ".")
                    {
                        Console.Beep();
                        
                        continue;
                    }

                    Console.WriteLine();
                    
                    break;
                }

                // Backspace
                if (key.Key == ConsoleKey.Backspace && input.Length > 0)
                {
                    // Default -> (input[input.Length - 1] == '.')
                    if (input[^1] == '.')
                        hasDot = false;

                    input.Remove(input.Length - 1, 1);

                    Console.Write("\b \b");
                    
                    continue;
                }

                char ch = key.KeyChar;

                // Number
                if (char.IsDigit(ch))
                {
                    input.Append(ch);

                    Console.Write(ch);
                }

                // Dot only once
                else if (ch == '.' && !hasDot)
                {
                    input.Append(ch);
                    
                    Console.Write(ch);

                    hasDot = true;
                }
            }

            return double.Parse(input.ToString());
        }

        public static int ParseNumericLine()
        {
            StringBuilder input = new();

            while (true)
            {
                ConsoleKeyInfo key = Console.ReadKey(true);

                // Enter key = finish input
                if (key.Key == ConsoleKey.Enter)
                {
                    // Prevent blank input
                    if (input.Length == 0 || input.ToString() == ".")
                    {
                        Console.Beep();

                        continue;
                    }

                    Console.WriteLine();

                    break;
                }

                // Backspace
                if (key.Key == ConsoleKey.Backspace && input.Length > 0)
                {
                    input.Remove(input.Length - 1, 1);

                    Console.Write("\b \b");

                    continue;
                }

                char ch = key.KeyChar;

                // Number
                if (char.IsDigit(ch))
                {
                    input.Append(ch);

                    Console.Write(ch);
                }
            }

            return int.Parse(input.ToString());
        }
    }
}