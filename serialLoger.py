import serial
import time
from datetime import datetime
from datetime import timedelta

baudRate = 9600

def main():
    port = '/dev/ttyACM0'
    # port = '/dev/tty.usbmodemfa131'
    ser = serial.Serial(port, baudRate, timeout=None)
    fileName = 'Massangeana-' + str(datetime.now().strftime('%Y%m%d-%H%M%S')) +'.csv'
    logCSV = open(fileName, 'a+')
    startTime = datetime.now()
    fileDuration = timedelta(days=1)

    while True:
        dataRow = datetime.now().strftime('%Y-%m-%d %H:%M:%S')+','+ser.readline()
        logCSV.write(dataRow)
        print dataRow

        # if the process takes longer than fileduration, make a new file.
        if(datetime.now() - startTime > fileDuration):
            logCSV.close()
            fileName = 'Massangeana-' + str(datetime.now().strftime('%Y%m%d-%H%M%S')) +'.csv'
            logCSV = open(fileName, 'a+')
            startTime = datetime.now()
    
    logCSV.close()

if __name__ == '__main__':
    main()