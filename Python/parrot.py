parrot = "Norwegian Blue"

letter = input("Enter a character: ")

if letter in parrot.casefold():
    print("{} is in {} ".format(letter, parrot))
else:
    print("dont need that string") 