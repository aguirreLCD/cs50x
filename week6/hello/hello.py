# Implement a program that prints out a simple greeting to the user;

# input and print, with format strings

# answer = input("What's your name? ")
# print(f"hello, {answer}")

# get_string and print, with format strings

from cs50 import get_string

answer = get_string("What's your name? ")
print(f"hello, {answer}")