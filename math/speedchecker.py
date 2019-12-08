#!/usr/bin/env python
#-*- using:utf-8 -*-
import time
import math

start = time.time()
n = 1
while n < 1000000:
  a = 2
  b = 0
  while a < math.sqrt(n):
    if n % a == 0:
      b = a
      break;
    a+=1
  if b <> 0:
    print str(n) +"is calced by"+str(b)
  else:
    print str(n) + "isn't calced"
  n+=1
elapsed_time = time.time()-start
print ("elapsed_time:{0}".format(elapsed_time)) + "[sec]"
