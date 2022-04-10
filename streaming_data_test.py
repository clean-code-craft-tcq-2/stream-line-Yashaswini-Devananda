import sys
import time
import sender
import unittest
import input_sensor_data
import unittest

# A2D_readings = [0,0]
# temperature_sensor_readings = [0,0]
# # data_received.append(sys.stdin.read())
# data1 = sender.start_sending(A2D_readings,temperature_sensor_readings)
# # print (sender.start_sending(A2D_readings,temperature_sensor_readings))
# print (data1)
# print ("----------------")
# A2D_readings = [0,4000]
# temperature_sensor_readings = [0,1]
# # data_received.append(sys.stdin.read())
# data1 = sender.start_sending(A2D_readings,temperature_sensor_readings)
# # print (sender.start_sending(A2D_readings,temperature_sensor_readings))
# print (data1)
print ("----------------")
A2D_readings = [4000,4000]
temperature_sensor_readings = [1,1]
# data_received.append(sys.stdin.read())
data1 = sender.start_sending(A2D_readings,temperature_sensor_readings)
# print (sender.start_sending(A2D_readings,temperature_sensor_readings))
print (data1)
# class sender_test(unittest.TestCase):
  
#   def test(self):
#     self.assertEqual(sender.start_sending(A2D_readings,temperature_sensor_readings), "0,32\n10,34\n" , "not equal")
        
# unittest.main()
  
  
  





