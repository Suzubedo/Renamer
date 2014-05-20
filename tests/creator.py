#! /usr/bin/env python

import sys
import commands

def main():
  if len(sys.argv) <= 1:
    limit = 10
  else:
    limit = sys.argv[1]

  for i in range(0, limit):
    a = "touch test_dir/test" + str(i) + ".mp4"
    b = "touch test_dir/different" + str(i) + ".srt"
    commands.getoutput(a)
    commands.getoutput(b)
    writer = open("test_dir/different" + str(i) + ".srt", 'w')
    writer.write("I'm " + str(i))
    


main()
