import sys
import time
import sender
import unittest
import input_sensor_data
import unittest

# # A2D_readings = [0,0]
# # temperature_sensor_readings = [0,0]
# # # data_received.append(sys.stdin.read())
# # data1 = sender.start_sending(A2D_readings,temperature_sensor_readings)
# # # print (sender.start_sending(A2D_readings,temperature_sensor_readings))
# # print (data1)
# # print ("----------------")
# A2D_readings = [0,2000]
# temperature_sensor_readings = [0,1]
# # data_received.append(sys.stdin.read())
# data1 = sender.start_sending(A2D_readings,temperature_sensor_readings)
# # print (sender.start_sending(A2D_readings,temperature_sensor_readings))
# # print (data1)
# # print ("----------------")
# # A2D_readings = [4000,4000]
# # temperature_sensor_readings = [1,1]
# # # data_received.append(sys.stdin.read())
# # data1 = sender.start_sending(A2D_readings,temperature_sensor_readings)
# # # print (sender.start_sending(A2D_readings,temperature_sensor_readings))
# # print (data1)

class sender_test(unittest.TestCase):
  
  def test(self):
    for test_data in range (len(test_A2D_readings)):
      self.assertEqual(sender.start_sending(input_sensor_data.test_A2D_readings[test_data],(input_sensor_data.test_temperature_readings[test_data]), input_sensor_data.result_data[test_data] , "not equal")
        
unittest.main()
  
  
  





