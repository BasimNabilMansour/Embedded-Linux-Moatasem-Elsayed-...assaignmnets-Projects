import webbrowser
import time
time.sleep(2)

def menu():
    print("(1)YOUTUBE"  ,   "(3)GOOGLE"     )
    print("(2)FACEBOOK" ,   "(4)LINKEDIN"   )
    
menu()
while True:
 choice=input("Choose which site do you want to open : ")
 if choice == '1':
    webbrowser.get('firefox').open('https://www.youtube.com')
 elif choice == '2':
    webbrowser.get('firefox').open('https://www.facebook.com')
 elif choice == '3':
    webbrowser.get('firefox').open('https://www.google.com')
 elif choice == '4':
    webbrowser.get('firefox').open('https://www.linkedin.com')
 else:
    print("try again")  
 

 
    


    

       