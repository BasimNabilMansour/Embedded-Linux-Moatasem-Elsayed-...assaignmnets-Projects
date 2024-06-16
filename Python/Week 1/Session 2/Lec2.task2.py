
import time
import requests
time.sleep(2)

def menu():
    print("(1)GET Your Public IP"     )
    print("(2)GET Your Location"   )
    
menu()

while True:
 choice=input("Choose which Request do you want  : ")
 if choice == '1':
    url=requests.get("https://api.ipify.org/?format=json")
    print(url.text)
 elif choice == '2':
    url=requests.get("https://ipinfo.io")
    print(url.text)
 else:  
    print("try again")  
 

 
    


    

       

 
    


    

       
