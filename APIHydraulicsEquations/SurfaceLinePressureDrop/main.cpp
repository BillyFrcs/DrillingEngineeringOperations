#include <iostream>
#include <cmath>

#include "../utils/conversions.hpp"

int main()
{
    std::cout << "SURFACE LINE PRESSURE DROP" << std::endl;

    // np and Kp
    double np = 3.32 * std::log10(34.0 / 53.0);
    double Kp = (5.11 * 53) / std::pow(1022, 0.64);

    std::cout << "Pipe \"n\" and \"K\" values:" << std::endl;

    std::cout << "np = " << std::abs(np) << std::endl;
    std::cout << "Kp = " << Kp << std::endl;

    std::cout << "\n" << std::endl;

    std::cout << "Surface Connection:" << std::endl;

    // Velocity
    double velocity_vp_ft = 24.48 * 335 / std::pow(3.826, 2);

    double velocity_vp_m = feetToMeters(velocity_vp_ft);

    std::cout << "Velocity = " << velocity_vp_ft << " ft/min " << velocity_vp_m << " m/min" << std::endl;

    // Effective Viscosity
    double Ev = 100 * 3.21 * ((std::pow((1.6 * 560.23) / 3.826, 0.64 - 1))) * std::pow((3 * 0.64 + 1) / (4 * 0.64), 0.64);

    std::cout << "Effective Viscosity = " << Ev << " cP" << std::endl;

    // Reynolds Number
    double NRep = (15.467 * 560.23 * 3.826 * 12.8) / 48.97;

    std::cout << "Reynolds Number = " << NRep << std::endl;

    // Friction Factor
    double fp = ((std::log10(0.64) + 3.93) / 50) / std::pow(8667, (1.75 - std::log10(0.64)) / 7);

    std::cout << "Friction Factor = " << fp << std::endl;

    //  Pressure Loss
    double pp_psi = ((0.006025 * std::pow(560.23, 2) * 12.8) / (92916 * 3.826)) * 610;

    double bar = psiToBar(pp_psi);

    std::cout << "Pressure Lost = " << pp_psi << " psi " << bar << " bar" << std::endl;

    return 0;
}