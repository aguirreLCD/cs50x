from cs50 import get_string

# 1.Prompt for user's text
text = get_string("Text: ")
# print(f"Your text is: ", text)

# 2.Determines the Length of a string
# numberOfCharacters = len(text)
# print(f"number of chars ", numberOfCharacters)

# textOrd = ord("a")
# print(f"ord ", textOrd)

indexOfChars = 0
numberOfChars = 0
numberOfLetters = 0
numberOfSpaces = 0
numberOfSentences = 0
numberOfDigits = 0
numberOfWords = numberOfSpaces + 1

# # 3.Count the number of letters / words / sentences
# # 3.1 Count number of characters up until '\0' (aka NUL - end of a string)
# Python program to iterate over characters of a string
# Iterate over the string
for element in text:
    # print(element, end=' ')
    # print()
    if ((element >= 'a') and (element <= 'z')):
        numberOfLetters += 1
        numberOfChars += 1
    elif ((element >= 'A') and (element <= 'Z')):
        numberOfLetters += 1
        numberOfChars += 1
    elif (element == ' '):
        numberOfSpaces += 1
        numberOfWords += 1
        numberOfChars += 1
    elif (element == '!'):
        numberOfSentences += 1
        numberOfChars += 1
    elif (element == '?'):
        numberOfSentences += 1
        numberOfChars += 1
    elif (element == '.'):
        numberOfSentences += 1
        numberOfChars += 1
    # elif (element == ','):
    #     numberOfSentences += 1
        # numberOfChars += 1
    elif ((element >= '0') and (element <= '9')):
        numberOfDigits += 1
        numberOfChars += 1
indexOfChars += 1

# print(f"Your text has: {numberOfLetters} letters ", numberOfLetters)
# print(f"Your text has: {numberOfWords} words ", numberOfWords)
# print(f"Your text has: {numberOfSentences} sentences ", numberOfSentences)
# print(f"Your text has: {numberOfDigits} digits ", numberOfDigits)
# print(f"Your text has: {numberOfChars} characters ", numberOfChars)
# print(f"len: ", len(text))

# 4.float averageL
averageL = round((numberOfLetters / numberOfWords) * 100, 2)
# print(f"average L: {averageL} letters per 100 words. ")

# 5.float averageS
averageS = round((numberOfSentences / numberOfWords) * 100, 2)
# print(f"average S: {averageS} sentences per 100 words. ")

# 6.Coleman-Liau index
index = round(0.0588 * averageL - 0.296 * averageS - 15.8)
# print(f"index: {index} ")

if (index < 1):
    print("Before Grade 1")
elif (index > 16):
    print("Grade 16+")
else:
    print(f"Grade {index} ")