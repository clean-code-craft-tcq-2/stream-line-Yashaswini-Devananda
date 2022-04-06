import sys
import data_conversion

def streaming_sensor_data(A2D_value, temperature_value):
    current = data_conversion.map_adc_value_to_amps(A2D_value, data_conversion.ADC_12Bit)
    temperature = data_conversion.map_celsius_to_fahrenheit(temperature_value)
    sys.stdout.write(current + "," + temperature)
    sys.stdout.write("\n")
