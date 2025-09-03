import tkinter as tk
import paho.mqtt.client as mqtt

broker = "broker.hivemq.com"
topic = "IoT-IF-Undip"

client = mqtt.Client()
client.connect(broker)


def send_on():
    client.publish(topic, "1")
    status_label.config(text="LED ON")


def send_off():
    client.publish(topic, "0")
    status_label.config(text="LED OFF")


# GUI
root = tk.Tk()
root.title("Kontrol LED IoT")

frame = tk.Frame(root, padx=20, pady=20)
frame.pack()

status_label = tk.Label(frame, text="Status: -")
status_label.grid(row=1, column=0, columnspan=2, padx=10)

on_btn = tk.Button(frame, text="Nyalakan LED", command=send_on, bg="green", fg="white")
on_btn.grid(row=0, column=0, padx=10)

off_btn = tk.Button(frame, text="Matikan LED", command=send_off, bg="red", fg="white")
off_btn.grid(row=0, column=1, padx=10)

root.mainloop()
