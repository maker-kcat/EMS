# -*- coding: utf-8 -*-
from __future__ import print_function
import socket
import time

from contextlib import closing

def main():
  host = '133.10.79.170'
  port = 61000
  count = 0
  message = 'Send scene Number to '+ host
  print(message) 

  sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
  with closing(sock):
    for i in range(1,2):
      message = bytearray(['1',1,0,0,0, count+i])
      print(str(message)+':Scene ' + str(count+i) ) # print mes to view
      sock.sendto(message, (host, port)) # send packet
      time.sleep(1)                      # wait for 1 second
  return

if __name__ == '__main__':
  main()

