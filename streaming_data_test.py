import sys
import time
import sender
import unittest
import input_sensor_data

A2D_readings = [0, 4000]
temperature_sensor_readings = [0,1]
# data_received.append(sys.stdin.read())
data1 = sender.start_sending(A2D_readings,temperature_sensor_readings)
# print (sender.start_sending(A2D_readings,temperature_sensor_readings))
 print (data1)


