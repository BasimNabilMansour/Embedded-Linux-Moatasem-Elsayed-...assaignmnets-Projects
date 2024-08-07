#!/usr/bin/python3
import speech_recognition as sr 
import pyttsx3
import pyaudio
import datetime
from gtts import gTTS
from playsound import playsound
import webbrowser
from time import ctime
import os
import random
import calendar
import sys
sys.tracebacklimit=0


def respond(voice_data):
    global alexa
def get_voice_command():
    recognizer = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening for your command...")
        audio = recognizer.listen(source)
        try:
            command = recognizer.recognize_google(audio)
            print(f"You said: {command}")
            return command.lower()
        except sr.UnknownValueError:
            print("Sorry, I could not understand your command.")
            return ""
        except sr.RequestError:
            print("Could not request results from Google Speech Recognition service.")
            return ""

def tell_time():
    now = datetime.datetime.now()
    current_time = now.strftime("%Y-%m-%d  %H:%M:%S")
    return current_time

def respond_with_voice(response):
    engine = pyttsx3.init()
    engine.say(response)
    engine.runAndWait()

def main():
    while True:
        command = get_voice_command()

        if 'time' in command:
            current_time = tell_time()
            response = f"The current time is {current_time}."
            print(response)
            respond_with_voice(response)

        elif 'google' in command:
            webbrowser.open("https://www.google.com")
            response = "Opening Google."
            print(response)
            respond_with_voice(response)
            
        elif 'youtube' in command:
            webbrowser.open("https://www.youtube.com")
            response = "Opening YOUTUBE."
            print(response)
            respond_with_voice(response)    

        elif 'exit' in command:
            print("Exiting the system.")
            respond_with_voice("Exiting the system.")
            break

        else:
            response = "I did not understand that command."
            print(response)
            respond_with_voice(response)

if __name__ == "__main__":
    main()
 
