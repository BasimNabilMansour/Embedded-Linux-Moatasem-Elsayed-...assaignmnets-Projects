#!/usr/bin/python

from tkinter import *
import threading



root=Tk()
v=IntVar()

Radiobutton(root,text='GPT-3',variable=v,value=1).pack()
Radiobutton(root,text='GPT-4',variable=v,value=2).pack()

def show():
    global t
    print(v.get())
    if v.get()==1:
        print("GPT-3")
    elif v.get()==2:
        print("GPT-4")
    else:
        print("None")    
    t=threading.Timer(1,show)
    t.start()
threading.Timer(1,show).start()

try:
    root.mainloop()
    t.cancel()
except:
    print("Exiting")
    exit()        
