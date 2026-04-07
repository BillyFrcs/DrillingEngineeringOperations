import math

from HydraulicsEquations.calculations.conversions import Conversions

class DrillCollarHoleAnnularPressureDrop(object):
    def __init__(self, theta_100, theta_03, flow_rate, inside_diameter, mud_density, length):
        # Initialize input parameters
        self.theta_100 = theta_100
        self.theta_03 = theta_03
        self.flow_rate = flow_rate
        self.inside_diameter = inside_diameter
        self.mud_density = mud_density
        self.length = length
        
        # Results storage
        self.na = 0
        self.ka = 0
        self.velocity_ft = 0
        self.velocity_m = 0
        self.effective_viscosity = 0
        self.reynolds_number = 0
        self.friction_factor = 0
        self.pressure_loss_psi = 0
        self.pressure_loss_bar = 0

    def calculate_n_k(self):
        """
        na = 0.657 * log (Θ100 / Θ3) = ...
        Ka = (5.11 * Θ3) / 5.11(na) = ...
        """
        self.na = 0.657 * math.log10(self.theta_100 / self.theta_03)

        self.ka = 5.11 * self.theta_03 / math.pow(5.11, 0.275)

        return self.na, self.ka

    def calculate_velocity(self):
        """
        Velocity: 
        Va (ft/min) = 24.48 x Q (gpm) / (D2(2) - D1(2) (in.) = ... ft/min ...m/min
        """
        self.velocity_ft = 24.48 * self.flow_rate / (math.pow(self.inside_diameter, 2) - math.pow(7, 2))

        conversions = Conversions()

        self.velocity_m = conversions.feet_to_meters(self.velocity_ft)

        return self.velocity_ft, self.velocity_m

    def calculate_effective_viscosity(self):
        """
        Effective viscosity:
        μep (cP) = 100 * Ka * {(2.4 * Va) / (D2 - D1)}(na - 1) * {(2na + 1) / (3 * na)}(na) = ... cP
        """
        self.effective_viscosity = (100 * self.ka * ((math.pow((2.4 * self.velocity_ft) / (self.inside_diameter - 7), 0.275 - 1))) * math.pow((2 * 0.275 + 1) / (3 * 0.275), 0.275)) 
        
        return self.effective_viscosity

    def calculate_reynolds_number(self):
        """
        Reynolds Number: 
        NRea = (15.467 * Va * (D2 - D1) * ρ) / μep --> Reynolds number ? 2100;
        """
        self.reynolds_number = (15.467 * self.velocity_ft * (self.inside_diameter - 7) * self.mud_density) / self.effective_viscosity
        
        return self.reynolds_number

    def calculate_friction_factor(self):
        """ 
        Friction Factor:
        fa = {(log n + 3.93) / 50} / [NRea]{(1.75 - log na) / 7)}
        """
        self.friction_factor = ((math.log10(0.275) + 3.93) / 50) / math.pow(self.reynolds_number, (1.75 - math.log10(0.275)) / 7)
        
        return self.friction_factor

    def calculate_pressure_loss(self):
        """
        Pressure loss:
        Pp (psi) = ((fa * Vp(2) * ρ) / (92916 * (D2 - D1)) * Lm
        """
        self.pressure_loss_psi = (self.friction_factor * math.pow(self.velocity_ft, 2) * self.mud_density) / (92916 * (self.inside_diameter - 7)) * self.length
        
        conversions = Conversions()

        self.pressure_loss_bar = conversions.psi_to_bar(self.pressure_loss_psi)
        
        return self.pressure_loss_psi, self.pressure_loss_bar

    def run_all_calculations(self):
        self.calculate_n_k()
        self.calculate_velocity()
        self.calculate_effective_viscosity()
        self.calculate_reynolds_number()
        self.calculate_friction_factor()
        self.calculate_pressure_loss()

    def display_results(self):
        print("\nDC – HOLE ANNULAR PRESSURE DROP")
        print("-" * 30)
        print('Pipe "n" and "K" values:')
        print(f"na = {self.na}")
        print(f"Ka = {self.ka}")

        print('\nANNULAR INTERVAL #1 (8"5/8 HOLE - 7" DRILL COLLARS):')
        print(f"Velocity = {self.velocity_ft} ft/min {self.velocity_m} m/min")
        print(f"Effective Viscosity = {self.effective_viscosity} cP")
        print(f"Reynolds Number = {self.reynolds_number}")
        print(f"Friction Factor = {self.friction_factor}")
        print(f"Pressure Loss = {self.pressure_loss_psi:} psi {self.pressure_loss_bar} bar")