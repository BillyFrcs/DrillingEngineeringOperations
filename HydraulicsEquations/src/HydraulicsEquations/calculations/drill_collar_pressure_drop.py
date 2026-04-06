import math

from HydraulicsEquations.calculations.conversions import Conversions

class DrillCollarPressureDrop(object):
    def __init__(self, theta_600, theta_300, flow_rate, inside_diameter, mud_density, length):
        # Initialize input parameters
        self.theta_600 = theta_600
        self.theta_300 = theta_300
        self.flow_rate = flow_rate
        self.inside_diameter = inside_diameter
        self.mud_density = mud_density
        self.length = length
        
        # Results storage
        self.np = 0
        self.kp = 0
        self.velocity_ft = 0
        self.velocity_m = 0
        self.effective_viscosity = 0
        self.reynolds_number = 0
        self.friction_factor = 0
        self.pressure_loss_psi = 0
        self.pressure_loss_bar = 0

    def calculate_n_k(self):
        """
        Pipe "n" and "K" values:
        np = 3.32 * log (Θ600 / Θ300) = ...
        Kp = 5.11 * Θ600 / 1022 (0.64) np = ...
        """
        self.np = abs(3.32 * math.log10(self.theta_600 / self.theta_300))

        self.kp = 5.11 * self.theta_300 / math.pow(1022, 0.64)

        return self.np, self.kp

    def calculate_velocity(self):
        """
        Velocity: 
        Vp (ft/min) = 24.48 * Q (gpm) / D(2) (in.) = ... ft/min ...m/min
        """
        self.velocity_ft = 24.48 * self.flow_rate / math.pow(self.inside_diameter, 2)

        conversions = Conversions()

        self.velocity_m = conversions.feet_to_meters(self.velocity_ft)

        return self.velocity_ft, self.velocity_m

    def calculate_effective_viscosity(self):
        """
        Effective viscosity:
        μep (cP) = 100 * Kp * {(1.6 * Vp) / D)}(np-1) * {(3np + 1)/(4 * np)}(np) = ... cP
        """
        self.effective_viscosity = (100 * 3.21 * ((math.pow((1.6 * self.velocity_ft) / self.inside_diameter, 0.64 - 1))) * math.pow((3 * 0.64 + 1) / (4 * 0.64), 0.64)) 
        
        return self.effective_viscosity

    def calculate_reynolds_number(self):
        """
        Reynolds Number: 
        NRep = (15.467 * Vp * D * ρ) / μep --> Reynolds number ? 2100;
        """
        self.reynolds_number = (15.467 * self.velocity_ft * self.inside_diameter * self.mud_density) / self.effective_viscosity
        
        return self.reynolds_number

    def calculate_friction_factor(self):
        """ 
        Friction Factor:
        fp = {(log n + 3.93) / 50} / [NRep]{(1.75 - log np)/7)}
        """
        self.friction_factor = ((math.log10(0.64) + 3.93) / 50) / math.pow(self.reynolds_number, (1.75 - math.log10(0.64)) / 7)
        
        return self.friction_factor

    def calculate_pressure_loss(self):
        """
        Pressure loss:
        Pp (psi) = ((fp * Vp(2) * ρ) / (92916 * D)) * Lm
        """
        self.pressure_loss_psi = ((self.friction_factor * math.pow(self.velocity_ft, 2) * self.mud_density) / (92916 * self.inside_diameter)) * self.length
        
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
        print("\nDRILL COLLAR PRESSURE DROP")
        print("-" * 30)
        print('Pipe "n" and "K" values:')
        print(f"np = {self.np}")
        print(f"Kp = {self.kp}")

        print("\nDRILL STRING INTERVAL #2 (DRILL COLLARS):")
        print(f"Velocity = {self.velocity_ft} ft/min {self.velocity_m} m/min")
        print(f"Effective Viscosity = {self.effective_viscosity} cP")
        print(f"Reynolds Number = {self.reynolds_number}")
        print(f"Friction Factor = {self.friction_factor}")
        print(f"Pressure Loss = {self.pressure_loss_psi:} psi {self.pressure_loss_bar} bar")