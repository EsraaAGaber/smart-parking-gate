import serial
import tkinter as tk
from PIL import Image, ImageTk  

def update_value():
    if ser.in_waiting > 0:
        line = ser.readline().decode().strip()
        if line == "NO":
            value_label.config(text="ALREADY FULL !!", fg="red")
            show_image("O.jpeg")
        else:
            value_label.config(text=" number of cars: " + line, fg="green")
            show_image("OO.jpeg")
    window.after(100, update_value)

def show_image(image_path):
    image = Image.open(image_path)
    photo = ImageTk.PhotoImage(image)
    image_label.config(image=photo)
    image_label.image = photo 

ser = serial.Serial('COM5', 9600) 

window = tk.Tk()
window.title("Arduino Value Display")

value_label = tk.Label(window, text="Waiting for value...", font=("Arial", 30, "bold"))
value_label.pack(expand=True, fill='both', anchor='center', pady=20)

image_label = tk.Label(window)
image_label.pack(expand=True, fill='both', anchor='center', pady=20)

update_value()

window.configure(bg="lightgray")

window.geometry("500x800") 

window.mainloop()
