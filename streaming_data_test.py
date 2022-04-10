import sys
import time
import sender
import unittest
import input_sensor_data

A2D_readings = [4000, 4000]
temperature_sensor_readings = [1,1]
# data_received.append(sys.stdin.read())

print (sender.start_sending(A2D_readings,temperature_sensor_readings))



