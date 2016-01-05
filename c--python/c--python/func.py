# -*- coding: utf-8 -*-
import datetime
import os

def writeTime():
    today = datetime.datetime.today()

    print (today)

    f = open("time.txt","a")
    s = str(today)
    s += os.linesep
    f.write(s)

    f.close()
    #return "python"
def printTest():
    print("test OK")

#writeTime()
