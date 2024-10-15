#!/usr/bin/python3
import re

# Example address
address = "22,st salah salem-Giza"

# Regex pattern to match the given address structure
pattern = r'^\d{1,},st\s[\w\s]+-[\w\s]+$'

# Validate the address
if re.match(pattern, address):
    print("Valid address")
else:
    print("Invalid address")