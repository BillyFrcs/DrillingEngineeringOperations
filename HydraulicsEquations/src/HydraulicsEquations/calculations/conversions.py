class Conversions(object):
    def feet_to_meters(self, feet):
        return feet * 0.3048

    def inches_to_feet(self, inches):
        return inches / 12.0

    def psi_to_bar(self, psi):
        return psi / 14.5038