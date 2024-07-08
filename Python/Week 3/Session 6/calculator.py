import tkinter as tk
from tkinter import messagebox

def calculate_result():
    try:
        num1 = int(entry1.get())
        num2 = int(entry2.get())
        operation = operation_var.get()
        if operation == "sum":
            result = num1 + num2
        elif operation == "Subtract":
            result = num1 - num2
        result_label.config(text=f"Result: {result}")
    except ValueError:
        messagebox.showerror("Invalid input", "Please enter valid integers")

# Create the main window
root = tk.Tk()
root.title("Calculator")

# Create and place the widgets
tk.Label(root, text="Enter first integer:").grid(row=0, column=0)
entry1 = tk.Entry(root)
entry1.grid(row=0, column=1)

tk.Label(root, text="Enter second integer:").grid(row=1, column=0)
entry2 = tk.Entry(root)
entry2.grid(row=1, column=1)

operation_var = tk.StringVar(value="sum")
tk.Radiobutton(root, text="Sum", variable=operation_var, value="sum").grid(row=2, column=0)
tk.Radiobutton(root, text="Subtract", variable=operation_var, value="Subtract").grid(row=2, column=1)

tk.Button(root, text="Calculate", command=calculate_result).grid(row=3, column=0)

result_label = tk.Label(root, text="Result:")
result_label.grid(row=4, column=0)

# Start the main event loop
root.mainloop()