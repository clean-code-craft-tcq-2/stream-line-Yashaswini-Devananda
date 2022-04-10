import sys
import time
import data_conversion
import input_sensor_data
streaming_data_limit = 2

def send_data_to_receiver(data):
#     sys.stdout.write(data)
    return data

def process_sensor_data(A2D_value, temperature_value):
    current = data_conversion.map_adc_value_to_amps(A2D_value, data_conversion.ADC_12Bit)
    temperature = data_conversion.map_celsius_to_fahrenheit(temperature_value)
    data = current + "," + temperature + "\n"
    return data
    
def start_sending(A2D_readings,temperature_readings):
    data = ""
    for reading in range (len(A2D_readings)):
        data = process_sensor_data(A2D_readings[reading], temperature_readings[reading])
        data_sent = send_data_to_receiver(data)
        time.sleep(0.5)
        data = data + data_sent
    return data

    



    

    
    


