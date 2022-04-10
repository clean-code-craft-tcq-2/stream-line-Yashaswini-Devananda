import sys
import time
import sender
import unittest
import input_sensor_data

data_received = []

data_received.append(sys.stdin.read())

print (data_received)

# received_data = []
# received_data.append(sys.stdin.read())
# print ("Data_received")
# print (received_data)

# class input_sensor_data_test(unittest.TestCase):
  
#   def test(self):
#     data_to_be_sent = ""
#     for x in input_sensor_data.data_sent_to_receiver:
#       data_to_be_sent = data_to_be_sent + x
#       print ("data_to_be_sent")
#       print (data_to_be_sent)
#       print ("Data_received")
#       print (received_data[0])
#     self.assertTrue(received_data[0] == data_to_be_sent)
        
# unittest.main()
  
