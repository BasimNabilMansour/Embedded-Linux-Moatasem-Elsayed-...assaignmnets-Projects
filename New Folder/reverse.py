#!/usr/bin/python3

import tkinter as tk

def reverse_word():
    word = entry.get()
    reversed_word = word[::-1]
    result_label.config(text=(f"Reversed word: {reversed_word}"))
    

# Create the main tkinter window
root = tk.Tk()

# Create a label for instructions
label = tk.Label(root, text="Enter a word:")
label.pack()

# Create an entry widget for user input
entry = tk.Entry(root, width=30)
entry.pack()

# Create a button to trigger word reversal
reverse_button = tk.Button(root, text="Reverse", command=reverse_word)
reverse_button.pack()

# Create a label to display the reversed word
result_label = tk.Label(root, text="")
result_label.pack()

# Run the tkinter main loop
root.mainloop()
