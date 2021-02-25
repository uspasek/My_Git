answer =  5
print("Please guess the nr between 1 and 10: ")
guess =  int(input())
if 1 <= guess <= 10:
    if answer == guess:
        print("You guessed right")

    elif answer < guess:
        print("Guess higher")
    elif answer > guess:
        print("Guess lower")    
else:
    print("bag off")