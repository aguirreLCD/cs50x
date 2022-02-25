import sys

import csv

if len(sys.argv) != 3:
    print("Error! Usage: python dna.py <valid .csv file> <valid .txt file> ")
    exit()

database = sys.argv[1]
sequence = sys.argv[2]

with open(database, newline='') as file:
    reader = csv.reader(file)

    # get first line = ['name', 'AGATC', 'TTTTTTCT', 'AATG', 'TCTAG', 'GATA', 'TATC', 'GAAA', 'TCTG']
    person_STR = next(reader)
    print(f"PERSON STR:  ", person_STR)

    length_person_STR = len(person_STR)
    print("LENGTH:       ",length_person_STR)

    # print(f"PERSON STR[1]: ", person_STR[1])

    for row in reader:
        print(row)
        for element in row:
            print(element)

#     print(lenght_row1)
#     print(row1[0])
#     print(row1[1])
#     print(row1[2])
#     print(row1[3])
#     print(row1[4])
#     print(row1[5])
#     print(row1[6])
#     print(row1[7])
#     print(row1[8])

# person_name = row1[0]
# person_STR1[1] = row1[1]
# person_STR2 = row1[2]
# person_STR3 = row1[3]
# person_STR4 = row1[4]
# person_STR5 = row1[5]
# person_STR6 = row1[6]
# person_STR7 = row1[7]
# person_STR8 = row1[8]

# person_STR = []

# for index in row1:
#     person_STR[index] = row1[index]
#     print(person_STR[index])



with open(database, "r") as csv_file:
    database_reader = csv.DictReader(csv_file, delimiter=" ")
    # <csv.DictReader object at 0x7f9a7124ad60>
    # print(database_reader)
    # print(f"list db reader", list(database_reader))
    # print(f"keys", database_reader.keys())
    # len(database_reader.keys())
    # len(database_reader)

    for row in database_reader:
        print(f'row db reader: \t{row}')
        for element in row:
            print(element)
        # print(person_STR[1])
        # print()
        # print(f'{row}')

        # name = str(row["name"])
        # str1 = int(row["AGATC"])
        # str2 = int(row["AATG"])
        # str3 = int(row["TATC"])
        # print(f"name, strs: ", name, str1, str2, str3)

        # print(f"name: ", row['name'[:]])
        # print(f"STR1: ", row['AGATC'[:]])
        # print(f"STR2: ", row['AATG'[:]])
        # print(f"STR3: ", row['TATC'[:]])
        # database_reader.keys()
        # database_list = list(row)
        # database_list.items()

        # database_list.append(row)
        # database_list = database_list.append(row)

        # database_list.append(row['name'[:]])
        # database_list.append(row['AGATC'[:]])
        # database_list.append(row['AATG'[:]])
        # database_list.append(row['TATC'[:]])
        # print(f"each item from database reader: ", row['name'], row['AGATC'], row['AATG'], row['TATC'])
        # print(f"row from database reader: ", row)

        # print(f"list: ", database_list)

# # print(f"name:    ", row['name'[:]])
# # print(f"STR1:    ", row['AGATC'[:]])
# # print(f"STR2:    ", row['AATG'[:]])
# # print(f"STR3:    ", row['TATC'[:]])
# print(f"db list: ", database_list[:])
# print(f"db list: ", database_list)

# name = database_list[0]
# AGATC = database_list[1]
# AATG = database_list[2]
# TATC = database_list[3]

# STR1 = list(AGATC)
# STR2 = list(AATG)
# STR3 = list(TATC)

# # # print(f"db list: ", database_list[0], database_list[1], database_list[2], database_list[3])
counter = 0
i = 0
counter_str1 = 0
counter_str2 = 0
counter_str3 = 0
counter_str4 = 0
counter_str5 = 0
counter_str6 = 0
counter_str7 = 0
counter_str8 = 0
counter_master = 0
sequence_counter = 0
# open the DNA sequence and read its contents into memory.
with open(sequence, 'r') as textfile:
    sequence_reader = textfile.read()
    print()
    # print(sequence_reader)

    # for bases in sequence_reader:
sequence_list = list(sequence_reader)

#for nBases in range(len(person_STR-1))
# str = list(person_STR[nBases])
str1 = list(person_STR[1])
len_str1 = len(str1)
        # for items in sequence_list:
counter_str = [0] * len(sequence_list)
for items in range(len(sequence_list)-len_str1):
    if sequence_list[items:(items+len_str1)] == str1:
        counter_str[items] = 1
    else:
        counter_str[items] = 0
# print(counter_str)
# for items in range(len(sequence_list)-len_str1):
    




    # i = items
    # print(sequence_list[i:(i+len_str1)])
    # print(i)
    # if sequence_list[i:(i+len_str1)] == str1:
    #     j = i
    #     sequence_counter = 1
    #     while sequence_list[((j+len_str1)):(((j+len_str1)) + len_str1)] == str1:
    #         sequence_counter = sequence_counter + 1
    #         print(f"sequence_counter: ", sequence_counter)

    #         if sequence_counter > counter_master:
    #             counter_master = sequence_counter
    #         else:
    #             counter_master = counter_master
    #         print(f"counter_master: ", counter_master)
    #         j = j+len_str1



                    # while sequence_list[i:i+len_str1] == sequence_list[i+len_str1:i+(2 * len_str1)]:
                    #     counter_str1 += 1
                    #     i += len_str1

            # if str2 == sequence_list[i:i+len_str2]:
            #     counter_str2 += 1
            #     # i += 1
            # i += 1








        # if person_STR[1] == sequence_reader[i:i+len(person_STR[1])]:
        #     counter_str1 += 1
        #     i += 1

        # if person_STR[2] == sequence_reader[i:i+len(person_STR[2])]:
        #     counter_str2 += 1
        #     i += 1

        # if person_STR[3] == sequence_reader[i:i+len(person_STR[3])]:
        #     counter_str3 += 1
        #     i += 1

        # if person_STR[4] == sequence_reader[i:i+len(person_STR[4])]:
        #     counter_str4 += 1
        #     i += 1

        # if person_STR[5] == sequence_reader[i:i+len(person_STR[5])]:
        #     counter_str5 += 1
        #     i += 1

        # if person_STR[6] == sequence_reader[i:i+len(person_STR[6])]:
        #     counter_str6 += 1
        #     i += 1

        # if person_STR[7] == sequence_reader[i:i+len(person_STR[7])]:
        #     counter_str7 += 1
        #     i += 1

        # if person_STR[3] == sequence_reader[i:i+len(person_STR[8])]:
        #     counter_str8 += 1
        #     i += 1

        # i += 1
        # counter += 1
# print(sequence_list)

print()
# print(list(person_STR[1]))
# print(f"hi: ", person_STR[1])
# print(sequence_list)
print(f"counter_master: ", counter_master)

# print(sequence_list[i:i+len(person_STR[1])])

# print(f"hey: ", sequence_reader[i:i+len(person_STR[1])])
# print(f"ARRAY 1", person_STR[:])
# print()
# print(f"INDEX 1 ATÉ FINAL DO ARRAY 1: ", person_STR[1:])
# print()
# # print(f"LENGTH do INDEX 1 ARRAY 1: ", len(person_STR[index + 1]))
# print()

# # # print(row1[1])
# print(f"sequence reader: ", sequence_reader[0:], end="")
# print()
# print(f"len sequence reader: ", len(sequence_reader))
# # print()
# # print(f"sequence list:   ", sequence_list[0:], end="")
# # print(f"len sequence list: ", len(sequence_list))
# # print(f"counter ", counter)
# # print()
# # # print(f"stemp  ", stemp)
# # print()
# # print(f"list person_STR[index]: ", list(person_STR[index]))

# # print(f"sequence_list[i:i+len(person_STR[1])]: ", sequence_list[i:i+len(person_STR[1])])
# print()
# print(f"counter for long run str1 ", counter_str1)
# # print()
# print(f"counter for long run str2 ", counter_str2)
# # print()
# print(f"counter for long run str3 ", counter_str3)
# # print()
# print(f"counter for long run str4 ", counter_str4)

# print(f"counter for long run str5 ", counter_str5)

# print(f"counter for long run str6 ", counter_str6)

# print(f"counter for long run str7 ", counter_str7)

# print(f"counter for long run str8 ", counter_str8)


# # 'Draco,9,13,8,26,15,25,41,39'


# # # print(f"counters:   ", counter_str1, counter_str2, counter_str3)
# # # print(f"name, strs: ", name, str1, str2, str3)

# # with open(database, "r") as csvfile:
# #     database_reader = csv.DictReader(csvfile)
# #     for row in database_reader:
# #         name = str(row["name"])
# #         str1 = int(row["AGATC"])
# #         str2 = int(row["AATG"])
# #         str3 = int(row["TATC"])
# #         print()
# #         print(f"name, strs: ", name, str1, str2, str3)
# #         print(f"counters:   ", counter_str1, counter_str2, counter_str3)

# #         if str1 == counter_str1:
# #             if str2 == counter_str2:
# #                 if str3 == counter_str3:
# #                     print(name)
#                     # sys.exit(0)
# #         else:
# #            print("No match")
#             # sys.exit(1)


#         # if (str1 == counter_str1) and (str2 == counter_str2) and (str3 == counter_str3):
#         #     print(name)
#         # else:
#         #     print("No match")


# # textfile.closed


