import cv2
import time
import serial

#Conveyer Arduino
Ard1Ser = None

#Arm Arduino
Ard2Ser = None


ser0 = serial.Serial('/dev/ttyACM0', 115200, timeout=1)
ser0.reset_input_buffer()

ser1 = serial.Serial('/dev/ttyACM1', 115200, timeout=1)
ser1.reset_input_buffer()

ser0.writelines(['who\n'.encode('utf-8')])
while True:
    if ser0.in_waiting > 0:
        line = ser0.readline().decode('utf-8').rstrip()
        if line == 'Ard1':
            Ard1Ser = ser0
            break
        elif line == 'Ard2':
            Ard2Ser = ser0
            break

ser1.writelines(['who\n'.encode('utf-8')])
while True:
    if ser1.in_waiting > 0:
        line = ser1.readline().decode('utf-8').rstrip()
        if line == 'Ard1':
            Ard1Ser = ser1
            break
        elif line == 'Ard2':
            Ard2Ser = ser1
            break

inventory = {'Red':0, 'Green':0, 'Yellow':0, 'Blue':0}

def feeding():
    while True:
        Ard1Ser.writelines(['StartFeeding\n'.encode('utf-8')])
        if Ard1Ser.in_waiting > 0:
            line = Ard1Ser.readline().decode('utf-8').rstrip()
            if line == 'DoneFeeding':
                break

def sorting():
    cap = cv2.VideoCapture(2)

    _, frame = cap.read()

    hsv_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    height, width, _ = frame.shape
    cx = int(width / 2)
    cy = int(height / 2)

    center = hsv_frame[cy, cx] / 5
    right = hsv_frame[cy, cx + 10] / 5
    left = hsv_frame[cy, cx - 10] / 5
    up = hsv_frame[cy + 10, cx] / 5
    down = hsv_frame[cy - 10, cx] / 5
    hue_value = center[0] + right[0] + left[0] + up[0] + down[0]

    color = 'Undefined'
    if hue_value < 5:
        color = 'Red'
    elif hue_value < 33:
        color = 'Yellow'
    elif hue_value < 78:
        color = 'Green'
    elif hue_value < 131:
        color = 'Blue'
    else:
        color = 'Red'

    print(color)

    inventory[color] = inventory[color] + 1

    while True:
        Ard1Ser.writelines([f'{color}\n'.encode('utf-8')])
        if Ard1Ser.in_waiting > 0:
            line = Ard1Ser.readline().decode('utf-8').rstrip()
            if line == 'DoneSorting':
                break
    
def assembly():
    assembly_no = 0
    high_part = 0
    if (inventory['Red'] > 0) and (inventory['Green'] > 0):
        assembly_no = 1
        if inventory['Red'] > inventory['Green']:
            high_part = 1
        elif inventory['Red'] < inventory['Green']:
            high_part = 2
        inventory['Red'] = inventory['Red'] - 1
        inventory['Green'] = inventory['Green'] - 1
    
    if (inventory['Yellow'] > 0) and (inventory['Blue'] > 0):
        assembly_no = 2
        if inventory['Yellow'] > inventory['Blue']:
            high_part = 3
        elif inventory['Yellow'] < inventory['Blue']:
            high_part = 4
        inventory['Yellow'] = inventory['Yellow'] - 1
        inventory['Blue'] = inventory['Blue'] - 1

    
    while True:
        Ard1Ser.writelines([f'StartAss{assembly_no}{high_part}\n'.encode('utf-8')])
        if Ard1Ser.in_waiting > 0:
            line = Ard1Ser.readline().decode('utf-8').rstrip()
            if line == 'DoneAss':
                break


for i in range(8):
    feeding()

    sorting()

    assembly()