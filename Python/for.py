# parrot = "Norwegian Blue"

# for character in parrot:
#     print(character)

number = input("Please enter a series of numbers: ")
seperator = ""
for char in number:
    if not char.isnumeric():
        seperator+=char

print(seperator)
