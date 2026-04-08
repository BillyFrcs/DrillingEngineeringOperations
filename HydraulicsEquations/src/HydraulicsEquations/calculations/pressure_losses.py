from HydraulicsEquations.calculations.surface_line_pressure_drop import SurfaceLinePressureDrop
from HydraulicsEquations.calculations.drill_pipe_pressure_drop import DrillPipePressureDrop
from HydraulicsEquations.calculations.drill_collar_pressure_drop import DrillCollarPressureDrop
from HydraulicsEquations.calculations.drill_collar_hole_annular_pressure_drop import DrillCollarHoleAnnularPressureDrop
from HydraulicsEquations.calculations.drill_pipe_hole_annular_pressure_drop import DrillPipeHoleAnnularPressureDrop
from HydraulicsEquations.calculations.drill_pipe_casing_annular_pressure_drop import DrillPipeCasingAnnularPressureDrop

class PressureLosses(object):
    def __init__(self):
        pass

    def display_pressure_losses_psi(self):
        surface_line_pressure_drop = SurfaceLinePressureDrop(theta_600 = 34, theta_300 = 53, flow_rate = 335, inside_diameter = 3.826, mud_density = 12.8, length = 610)

        surface_line_pressure_drop.run_all_calculations()

        drill_pipe_pressure_drop = DrillPipePressureDrop(theta_600 = 34, theta_300 = 53, flow_rate = 335, inside_diameter = 3.826, mud_density = 12.8, length = 11641)

        drill_pipe_pressure_drop.run_all_calculations()

        drill_collar_pressure_drop = DrillCollarPressureDrop(theta_600 = 34, theta_300 = 53, flow_rate = 335, inside_diameter = 2.25, mud_density = 12.8, length = 390)
        
        drill_collar_pressure_drop.run_all_calculations()

        drill_collar_hole_annular_pressure_drop = DrillCollarHoleAnnularPressureDrop(theta_100 = 21, theta_03 = 8, flow_rate = 335, inside_diameter = 8.625, mud_density = 12.8, length = 390)
        
        drill_collar_hole_annular_pressure_drop.run_all_calculations()

        drill_pipe_hole_annular_pressure_drop = DrillPipeHoleAnnularPressureDrop(theta_100 = 21, theta_03 = 8, flow_rate = 335, inside_diameter = 8.625, mud_density = 12.8, length = 855)
        
        drill_pipe_hole_annular_pressure_drop.run_all_calculations()

        drill_pipe_casing_annular_pressure_drop = DrillPipeCasingAnnularPressureDrop(theta_100 = 21, theta_03 = 8, flow_rate = 335, inside_diameter = 8.835, mud_density = 12.8, length = 10786)
        
        drill_pipe_casing_annular_pressure_drop.run_all_calculations()

        calculate_pressure_loss_psi = surface_line_pressure_drop.get_pressure_loss_psi() + drill_pipe_pressure_drop.get_pressure_loss_psi() + drill_collar_pressure_drop.get_pressure_loss_psi() + drill_collar_hole_annular_pressure_drop.get_pressure_loss_psi() + drill_pipe_hole_annular_pressure_drop.get_pressure_loss_psi() + drill_pipe_casing_annular_pressure_drop.get_pressure_loss_psi()

        calculate_pressure_loss_bar = surface_line_pressure_drop.get_pressure_loss_bar() + drill_pipe_pressure_drop.get_pressure_loss_bar() + drill_collar_pressure_drop.get_pressure_loss_bar() + drill_collar_hole_annular_pressure_drop.get_pressure_loss_bar() + drill_pipe_hole_annular_pressure_drop.get_pressure_loss_bar() + drill_pipe_casing_annular_pressure_drop.get_pressure_loss_bar()

        bit_pressure_drop_psi = 3000.00 - calculate_pressure_loss_psi
        bit_pressure_drop_bar = 206.8427 - calculate_pressure_loss_bar

        print("\nPRESSURE LOSSES")
        print("-" * 30)

        print(f"Total Pressure Loss = {calculate_pressure_loss_psi} psi {calculate_pressure_loss_bar} bar")
        print(f"Bit Pressure Drop = {bit_pressure_drop_psi} psi {bit_pressure_drop_bar} bar")