import sys
import time
import random
import data_conversion

streaming_data_limit = 50
max_temp_value = 110.0
min_temp_value = 0.0
max_A2D_value = 4094.0
min_A2D_value =  0.0
ADC_12Bit = {"max_permissible_value" : 4094 , "intercept" : 0 , "max_current_range" : 10}

def generate_sensor_readings(min_value, max_value):
    return(round(random.randint(min_value, max_value)))

def send_data_to_receiver(data):
    sys.stdout.write(data)
    sys.stdout.write("\n")
    return (sys.stdout.write(data))
    
def send_sensor_data(A2D_value, temperature_value):
    current = data_conversion.map_adc_value_to_amps(A2D_value, ADC_12Bit)
    temperature = data_conversion.map_celsius_to_fahrenheit(temperature_value)
    data = "current in amps : " + current + "," + "temperature in Fahrenheit : " + temperature
    return 
    
for reading in range (streaming_data_limit):
    A2D_value = generate_sensor_readings(min_A2D_value, max_A2D_value)
    temperature = generate_sensor_readings(min_temp_value, max_temp_value)
    send_sensor_data(A2D_value, temperature)
    time.sleep(1)
    
    

    
    


