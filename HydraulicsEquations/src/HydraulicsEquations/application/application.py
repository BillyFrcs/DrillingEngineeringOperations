from HydraulicsEquations.calculations.surface_line_pressure_drop import SurfaceLinePressureDrop
from HydraulicsEquations.calculations.drill_pipe_pressure_drop import DrillPipePressureDrop
from HydraulicsEquations.calculations.drill_collar_pressure_drop import DrillCollarPressureDrop
from HydraulicsEquations.calculations.drill_collar_hole_annular_pressure_drop import DrillCollarHoleAnnularPressureDrop

class Application(object):
    def __init__(self):
        pass

    def run(self):
        Application.surface_line_pressure_drop()
        Application.drill_pipe_pressure_drop()
        Application.drill_collar_pressure_drop()
        Application.drill_collar_hole_annular_pressure_drop()
    
    @staticmethod
    def surface_line_pressure_drop():
        surface_line_pressure_drop = SurfaceLinePressureDrop(theta_600 = 34, theta_300 = 53, flow_rate = 335, inside_diameter = 3.826, mud_density = 12.8, length = 610)
        
        surface_line_pressure_drop.run_all_calculations()
        surface_line_pressure_drop.display_results()
    
    @staticmethod
    def drill_pipe_pressure_drop():
        drill_pipe_pressure_drop = DrillPipePressureDrop(theta_600 = 34, theta_300 = 53, flow_rate = 335, inside_diameter = 3.826, mud_density = 12.8, length = 11641)

        drill_pipe_pressure_drop.run_all_calculations()
        drill_pipe_pressure_drop.display_results()

    @staticmethod
    def drill_collar_pressure_drop():
        drill_collar_pressure_drop = DrillCollarPressureDrop(theta_600 = 34, theta_300 = 53, flow_rate = 335, inside_diameter = 2.25, mud_density = 12.8, length = 390)
        
        drill_collar_pressure_drop.run_all_calculations()
        drill_collar_pressure_drop.display_results()

    @staticmethod
    def drill_collar_hole_annular_pressure_drop():
        drill_collar_pressure_drop = DrillCollarHoleAnnularPressureDrop(theta_100 = 21, theta_03 = 8, flow_rate = 335, inside_diameter = 8.625, mud_density = 12.8, length = 390)
        
        drill_collar_pressure_drop.run_all_calculations()
        drill_collar_pressure_drop.display_results()