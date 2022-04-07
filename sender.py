import sys
import time
import data_conversion
streaming_data_limit = 5

def send_sensor_data(A2D_value, temperature_value):
    current = data_conversion.map_adc_value_to_amps(A2D_value, data_conversion.ADC_12Bit)
    temperature = data_conversion.map_celsius_to_fahrenheit(temperature_value)
    sys.stdout.write(current + "," + temperature + "\n")
#     sys.stdout.write("\n")
    
for reading in range (streaming_data_limit):
    send_sensor_data(A2D_value, temperature)
    time.sleep(1)
    
    

    
    



    

    
    


