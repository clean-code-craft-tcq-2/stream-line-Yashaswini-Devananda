def streaming_sensor_data(A2D_value, temperature_value):
    current = map_adc_value_to_amps(A2D_value, ADC_12Bit)
    temperature = map_celsius_to_fahrenheit(temperature_value)
    # print ((current + "," + temperature))
    sys.stdout.write(current + "," + temperature)
    sys.stdout.write("\n")
