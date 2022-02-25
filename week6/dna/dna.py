import sys

import csv

if len(sys.argv) != 3:
    print("Error! Usage: python dna.py <valid .csv file> <valid .txt file> ")
    exit()

# list of dicts
people = []
# list of keys // STR sequences
keys = []

database = sys.argv[1]
with open(database) as file:
    reader = csv.DictReader(file)
    for person in reader:
        print(person)
        print(person['name'])
        people.append(person)

    for key in person:
        print(key, "->", person[key])
        keys.append(key)

print(f"people dictionary: a list of persons ", people)
print(f"list of keys ", keys)
# print(f"list of keys - name: ", keys[1:])


# print(people[0])
# print(people[1])
# print(people[2])

sequence = sys.argv[2]

counter_master = 0

sequence_counter = 0

dna_sequences = []

# # open the DNA sequence and read its contents into memory.
with open(sequence) as textfile:
    sequence_reader = textfile.read()
    dna_sequences.append(sequence_reader.strip())

# print(f"list of dna_sequences: ", dna_sequences)
# print(sequence_reader[0:5])
# print(sequence_reader)
# sequence_list = list(sequence_reader)
# print(sequence_list)



# for nBases in range(1, len_keys):
#     strs = list(person_STR[nBases])
#     len_strs = len(strs)
#     # print(f"strs ", strs)
#     # print(f"len strs ", len_strs)
#     for items in range(len(sequence_list)-len_strs):
#         i = items
#         # print(i)
#         if sequence_list[i:(i+len_strs)] == strs:
#             j = i
#             sequence_counter = 1
#             # counter_master = 1
#             while sequence_list[((j+len_strs)):(((j+len_strs))+len_strs)] == strs:
#                 sequence_counter = sequence_counter + 1
#                 # i = i+len_strs
#                 # print(sequence_list[((j+len_strs)):(((j+len_strs))+len_strs)])
#                 # print(sequence_list[i:(i+len_strs)])
#                 # print(f"sequence_counter: ", sequence_counter)
#                 if sequence_counter > counter_master:
#                     counter_master = sequence_counter
#                 else:
#                     counter_master = counter_master
#                     # sequence_counter = 0
#                 j = j+len_strs
#         # else:
#             # counter_master = sequence_counter
#             # i += 1
#             # print(f"AAAA counter _master: ", counter_master)
#             # sequence_counter = 1

#             # print(f"counter _master: ", counter_master)
#         counter_master_str = str(counter_master)
#         person_STR[nBases] = counter_master_str
#         # print(f"person_STR[nBases]: ", person_STR[nBases])
#     counter_master = 1
#     # print(f" ", counter_master_str)


# with open(database, newline='') as file:
#     reader = csv.reader(file)
#     for row in reader:
#         if person_STR[1:] == row[1:]:
#             print(row[0])
#             sys.exit(0)
#     else:
#         print("No match")