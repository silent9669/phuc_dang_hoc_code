#!/usr/bin/env python3

while True:
    input_str = input("Enter your name (or 'q' to quit): ")
    if input_str.lower() == 'q':
        break
    else:
        print(f"Hello, {input_str}!")
