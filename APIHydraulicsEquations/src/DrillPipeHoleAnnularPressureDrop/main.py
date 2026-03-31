import math
import sys
import os

current_dir = os.path.dirname(os.path.abspath(__file__))
parent_dir = os.path.dirname(current_dir)

sys.path.append(parent_dir)

from utils.conversions import feetToMeters, psiToBar

print("DP – HOLE ANNULAR PRESSURE DROP")

"""
na = 0.657 * log (Θ100/Θ3)
Ka = (5.11 * Θ3) / 5.11na
"""
na = 0.657 * math.log10(21 / 8)
Ka = (5.11 * 8) / math.pow(5.11, 0.275)

print(f"na = {na}")
print(f"Ka = {Ka}")

print("\n")

print('ANNULAR INTERVAL #2 (8"5/8 HOLE - 4"1/2 DRILL PIPE):')

"""
Velocity: Va (ft/min) = 24.48 x Q (gpm) / (D22 - D12 (in.)
"""
velocity_va_ft = 24.48 * 335 / (math.pow(8.625, 2) - math.pow(4.5, 2))
velocity_va_m = feetToMeters(velocity_va_ft)

print(f"Velocity = {velocity_va_ft} ft/min {velocity_va_m} m/min")

"""
Effective viscosity =
μep (cP) = 100 * Ka * {(2.4 * Va)/(D2-D1)}(na-1) * {(2na + 1)/(3 * na)}na
"""
Ev_cP = (
    100
    * 26.1
    * ((math.pow((2.4 * 151.47) / (8.625 - 4.5), 0.275 - 1)))
    * (math.pow((2 * 0.275 + 1) / (3 * 0.275), 0.275))
)

print(f"Effective viscosity = {Ev_cP} cP")

"""
Reynolds number:
NRea = (15.467 * Va x (D2 – D1) x ρ) / μea
--> Reynolds number ? 2100; ……… Flow Type
"""
NRea = (15.467 * 322.99 * (8.625 - 7) * 12.8) / 35.48

print(f"Reynolds number = {NRea}")

"""
Friction factor:
fa = 24 / NRea
"""
fa = 24 / 1024.75

print(f"Friction factor = {fa}")

"""
Pressure loss:
Pa (psi) = ((fa * Vp2 * ρ) / (92916 * (D2-D1))) * Lm
"""
Pa_psi = ((0.02342 * math.pow(151.47, 2) * 12.8) / (92916 * (8.625 - 4.5))) * 855

bar = psiToBar(Pa_psi)

print(f"Pressure Loss = {Pa_psi} psi {bar} bar")
