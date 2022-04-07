import sys
import time
import sender
import unittest
import input_sensor_data


class input_sensor_data_test(unittest.TestCase):
  
  def test(self):
    for reading in range (sender.streaming_data_limit):
      self.assertEqual(sys.stdin.read(), input_sensor_data.data_sent_to_receiver[reading])
        
unittest.main()
  
