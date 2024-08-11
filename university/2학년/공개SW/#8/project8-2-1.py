import os
import random, datetime
if not os.path.isdir("log") :
    os.mkdir("log")
if not os.path.exists("log/count_log.txt") :
    f = open("log/count_log.txt", "w")
    f.write("writting start\n")
    f.close()
with open("log/count_log.txt", "a") as f :
    for i in range(1, 11) :
        stamp = str(datetime.datetime.now())
        value = random.random() * 1000000
        log_line = stamp + "\t" + str(value) + "value created" + "\n"
        f.write(log_line)