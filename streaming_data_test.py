import sys
import time
import sender
import unittest
import input_sensor_data


class input_sensor_data_test(unittest.TestCase):
  
  def test(self):
    for reading in range (sender.streaming_data_limit):
      received_data = sys.stdin.read()
      print (received_data)
      print (input_sensor_data.data_sent_to_receiver[reading])
      self.assertTrue(input_sensor_data.data_sent_to_receiver[reading] == received_data)
        
unittest.main()
  
