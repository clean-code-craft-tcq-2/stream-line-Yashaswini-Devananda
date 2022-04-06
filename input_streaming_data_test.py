import sys
import time
import sender

A2D_values = [0,4000,0,56,4025,9,900,2500,3000,]
temperature_value = [2,10,2,15,25,35,5,63,45]

for x in range (len(A2D_values)):
    sender.send_sensor_data(A2D_values[x], temperature_value[x])
    time.sleep(1)
