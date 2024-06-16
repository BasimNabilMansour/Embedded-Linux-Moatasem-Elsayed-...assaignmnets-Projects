import webbrowser
import time

time.sleep(2)

def menu():
    print("(1)GET Your Public IP"     )
    print("(2)GET Your Location"   )
    
menu()

while True:
 choice=input("Choose which Request do you want  : ")
 if choice == '1':
    webbrowser.get('firefox').open('https://api.ipify.org/?format=json')
 elif choice == '2':
    webbrowser.get('firefox').open('https://whatismyipaddress.com')
    print("try again")  
 

 
    


    

       