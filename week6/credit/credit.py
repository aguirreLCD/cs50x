# https://blog.tecladocode.com/python-30-day-9-project/

from cs50 import get_string

credit_card_number = list(get_string("Please enter the credit car number: ").strip())
# print(f"ccnum:     ", credit_card_number)
# print(f"len  :     ", len(credit_card_number))

new_copy = credit_card_number.copy()
# print(f"copy:      ", new_copy)
# print(f"len copy:  ", len(new_copy))

# Remove the last digit from the card number
check_digit = credit_card_number.pop()
# print(f"check digit ", check_digit)

# Reverse the order of the remaining numbers
credit_card_number.reverse()
# print(f"reverse               : ", credit_card_number)

# take the digit at every even index and double it
# inside a for loop, check whether or not the index is divisible by 2. If it is, we know we have an even index.

# for odd = convert the digit to an integer, and then call append to add the integer to processed_digits
# for even =  convert the digit to an integer and double the value;
# then check if the result of this operation is greater than 9;
# If it is, then subtract 9 from the result;
# then add this number to the processed_digits

processed_digits = []

for index, digit in enumerate(credit_card_number):
    if index % 2 == 0:
        doubled_digit = int(digit) * 2

        # Subtract 9 from any results that are greater than 9
        if doubled_digit > 9:
            doubled_digit = doubled_digit - 9

        processed_digits.append(doubled_digit)
    else:
        processed_digits.append(int(digit))

total = int(check_digit) + sum(processed_digits)

# print(f"processed ", processed_digits)
# print(f"total", total)
# print(f"ccnum p :  ", credit_card_number)
# print(f"len   p :  ", len(credit_card_number))

# print(f"    copy:  ", new_copy)
# print(f"len copy:  ", len(new_copy))

if total % 10 == 0:
    # print(f"total", total)
    # print(f"len copy h", len(new_copy))
    # if len(new_copy) > 12 or len(new_copy) < 17:
    if len(new_copy) == 15 and ((new_copy[0] == "3") and (new_copy[1] == "4" or "7")):
        print(f"AMEX")
    elif len(new_copy) == 16 and ((new_copy[0] == "5") and (new_copy[1] == "1" or "2" or "3" or "4" or "5")):
        print(f"MASTERCARD")
    elif len(new_copy) == 13 or 16 and ((new_copy[0] == "4")):
        print(f"VISA")
    else:
        print("INVALID flag")
else:
    print("INVALID")

# print(f"total", total)
# print(f"len copy L", len(new_copy))