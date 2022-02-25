# Implement a program that prints out a half-pyramid of a specified height;
# first prompt the user with get_int for the half-pyramid’s height, a positive integer between 1 and 8, inclusive;
# If the user fails to provide a positive integer no greater than 8, you should re-prompt for the same again;
# Then, generate (with the help of print and one or more loops) the desired half-pyramid;

from cs50 import get_int

height = get_int("Height: ")
while height < 1 or height > 8:
    height = get_int("Height: ")

for i in range(height):
    print(" "*(height - i - 1) + "#"*(i+1), end="")
    print()