
import tkinter as tk
import math

class AnalogHumidityScale(tk.Canvas):
    def __init__(self, master=None, humidity=0):
        super().__init__(master, width=400, height=400, bg='white')
        self.humidity = humidity
        self.create_circle(150, 150, 150)
        self.create_ticks()
        self.create_needle()
        self.pack()

    def create_circle(self, x, y, r):
        self.create_oval(x - r, y - r, x + r, y + r, width=2)
        self.create_oval

    def create_ticks(self):
        for i in range(0, 130, 10):
            angle = math.radians(270 - (i * 2.7))
            x_outer = 150 + 140 * math.cos(angle)
            y_outer = 150 + 140 * math.sin(angle)
            x_inner = 150 + 120 * math.cos(angle)
            y_inner = 150 + 120 * math.sin(angle)
            self.create_line(x_inner, y_inner, x_outer, y_outer, width=2)
            self.create_text(150 + 160 * math.cos(angle), 150 + 160 * math.sin(angle), text=str(i), font=("Arial", 10, "bold"))

    def create_needle(self):
        angle = math.radians(270 - (self.humidity * 3))
        x_needle = 150 + 130 * math.cos(angle)
        y_needle = 150 + 130 * math.sin(angle)
        self.needle = self.create_line(150, 150, x_needle, y_needle, fill='red', width=2)

    def update_needle(self, humidity):
        self.humidity = humidity
        self.delete(self.needle)
        self.create_needle()

def update_humidity(scale, label, scale_canvas):
    humidity = scale.get()
    label.config(text=f"Humidity: {humidity}%")
    scale_canvas.update_needle(humidity)

if __name__ == "__main__":
    root = tk.Tk()
    root.title("Analog Humidity Scale")

    scale_canvas = AnalogHumidityScale(root, humidity=45)
    scale_canvas.pack()

    humidity_scale = tk.Scale(root, from_=0, to=130, orient=tk.HORIZONTAL, length=300)
    humidity_scale.set(45)
    humidity_scale.pack()

    humidity_label = tk.Label(root, text="Humidity: 45%")
    humidity_label.pack()

    humidity_scale.config(command=lambda value: update_humidity(humidity_scale, humidity_label, scale_canvas))
    root.mainloop()
