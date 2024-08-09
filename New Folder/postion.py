#!/usr/bin/python3

import pyautogui
from time import sleep
import os

while True:
    x, y = pyautogui.position()
    print(x, y)