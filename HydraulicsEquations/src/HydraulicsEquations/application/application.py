from HydraulicsEquations.calculations import drill_pipe_pressure_drop
from HydraulicsEquations.calculations.surface_line_pressure_drop import SurfaceLinePressureDrop
from HydraulicsEquations.calculations.drill_pipe_pressure_drop import DrillPipePressureDrop

class Application(object):
    def run(self):
        Application.surface_line_pressure_drop()
        Application.drill_pipe_pressure_drop()
    
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
