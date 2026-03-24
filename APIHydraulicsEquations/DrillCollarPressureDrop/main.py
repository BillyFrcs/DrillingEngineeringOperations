import math
import sys
import os

current_dir = os.path.dirname(os.path.abspath(__file__))
parent_dir = os.path.dirname(current_dir)

sys.path.append(parent_dir)

from utils.conversions import feetToMeters, psiToBar

print("DRILL COLLAR PRESSURE DROP")

"""
3.32 * log (Θ600 / Θ300)
5.11 * log (Θ600) / 1022 np or 5.11 * Θ600 / 1022 np
"""
np = 3.32 * math.log10(34 / 53)
Kp = 5.11 * 53 / math.pow(1022, 0.64)

print('Pipe "n" and "K" values:')
print(f"Np = {abs(np)}")  # 0.64
print(f"Kp = {Kp}")  # 3.21

print("\n")

print("DRILL STRING INTERVAL #2 (DRILL COLLARS):")

"""
Velocity: Vp (ft/min)
= 24.48 x Q (gpm) / D2 (in.)
"""
velocity_vp_ft = 24.48 * 335 / math.pow(2.25, 2)
velocity_vp_m = feetToMeters(velocity_vp_ft)

print(f"Velocity = {velocity_vp_ft} ft/min {velocity_vp_m} m/min")

"""
Effective viscosity =
μep (cP) = 100 * Kp * {(1.6 * Vp)/D)}(np-1) * {(3np + 1)/(4 * np)}np
"""
Ev = (
    100
    * 3.21
    * ((math.pow((1.6 * 1619.91) / 2.25, 0.64 - 1)))
    * (math.pow((3 * 0.64 + 1) / (4 * 0.64), 0.64))
)

print(f"Effective viscosity = {Ev} cP")

"""27.60
Reynolds Number:
NRep = (15.467 * Vp*D*ρ) / μep
--> Reynolds number ? 2100;
"""
NRep = (15.467 * 1619.91 * 2.25 * 12.8) / 27.60

print(f"Reynolds Number = {NRep}")

""" 
Friction Factor:
fp = {(log n + 3.93)/50} / [NRep]{(1.75-log np)/7)}
"""
fp = ((math.log10(0.64) + 3.93) / 50) / math.pow(26144, (1.75 - math.log10(0.64)) / 7)

# fp = (((math.log10(0.64)) + 3.93) / 50) / 26144 ** ((1.75 - math.log10(0.64)) / 7)

print(f"Friction Factor = {fp}")

"""
Pressure loss:
Pp (psi) = ((fp * Vp2 * ρ) / (92916 * D)) * Lm
"""
Pp_psi = ((0.004434 * math.pow(1619.91, 2) * 12.8) / (92916 * 2.25)) * 390

# Pp_psi = ((0.006025 * math.pow(1619.91, 2) * 12.8) / (92916 * 2.25)) * 390

bar = psiToBar(Pp_psi)

print(f"Pressure Loss = {Pp_psi} psi {bar} bar")
