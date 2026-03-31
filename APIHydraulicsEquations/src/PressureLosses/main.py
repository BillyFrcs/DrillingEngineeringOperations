"""
Pressure Losses Calculations in PSI and BAR
"""
surface_line_pressure_drop_psi = 41.53
surface_line_pressure_drop_bar = 2.86

drill_string_interval1_drill_pipe_psi = 792.60
drill_string_interval1_drill_pipe_bar = 54.64

drill_string_interval2_drill_collar_psi = 277.52
drill_string_interval2_drill_collar_bar = 19.15

annular_interval1_drill_collar_psi = 16.65
annular_interval1_drill_collar_bar = 1.14

annular_interval2_drill_pipe_psi = 15.34
annular_interval2_drill_pipe_bar = 1.05

annular_interval3_casing_drill_pipe_psi = 178.44
annular_interval3_casing_drill_pipe_bar = 12.30

psi = (
    surface_line_pressure_drop_psi
    + drill_string_interval1_drill_pipe_psi
    + drill_string_interval2_drill_collar_psi
    + annular_interval1_drill_collar_psi
    + annular_interval2_drill_pipe_psi
    + annular_interval3_casing_drill_pipe_psi
)

bar = (
    surface_line_pressure_drop_bar
    + drill_string_interval1_drill_pipe_bar
    + drill_string_interval2_drill_collar_bar
    + annular_interval1_drill_collar_bar
    + annular_interval2_drill_pipe_bar
    + annular_interval3_casing_drill_pipe_bar
)

bit_pressure_drop = 3000.00 - psi

print(f"Total Pressure Lost = {psi} psi {bar} bar")
print(f"Bit Pressure Drop = {bit_pressure_drop} psi")
