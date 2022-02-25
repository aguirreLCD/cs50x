# Implement a program that prints out a double half-pyramid of a specified height;
# first prompt the user with get_int for the half-pyramid’s height, a positive integer between 1 and 8, inclusive;
# If the user fails to provide a positive integer no greater than 8, you should re-prompt for the same again;
# Then, generate (with the help of print and one or more loops) the desired half-pyramids;

from cs50 import get_int

height = get_int("Height: ")
while height < 1 or height > 8:
    height = get_int("Height: ")

gap = (f" "*2)
# half_pyramid_left = (" "*(height - i - 1) + "#"*(i+1))
# half_pyramid_right = (" "*(height - 1) + "#"*(i+1))

for i in range(height):
    # print(" "*(height - i - 1) + "#"*(i+1) + " "*(height - 1) + "#"*(i+1))
    print(" "*(height - i - 1) + "#"*(i+1), end="")
    print(gap, end="")
    # print(" ", " ", end="")
    print(" "*((height - 1) - height) + "#"*(i + 1), end="")
    # print(half_pyramid_left, end="")
    # print(half_pyramid_right, end="")
    print()