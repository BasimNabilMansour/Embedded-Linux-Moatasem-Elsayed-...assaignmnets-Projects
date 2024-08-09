#!/usr/bin/python

import threading


def task1(num):
    for _ in range(0,num):
        print("Task1")
        
def task2(num):
    for _ in range(0,num):
        print("Task2")


if __name__=="__main__":
    t1=threading.Thread(target=task1,args=(6,))  
    t2=threading.Thread(target=task2,args=(3,))    
    
    t1.start()
    t2.start()
    t1.join()
    t2.join() 
    print("Done!")          