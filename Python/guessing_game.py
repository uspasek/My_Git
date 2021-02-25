low = 1
high = 1000
print("Think of a nr between {} and {} ".format(low, high))
input("Press ENTER to start")
guesses = 1

while True:
    guess_ = low + (high - low) // 2
    high_low = input("My guess is {}. Should i guess higher or lower?"
                     "Enter h or l, or c if my guess was correct"
                     .format(guess_)).casefold()
    if high_low == "h":

        low = guess_ + 1
    elif high_low == "l":

        high = guess_ - 1
    elif high_low == "c":
        print("I have got it in {} guesses!".format(guesses))
        break
    else:
        print("Please enter h,l or c ")

    guesses += 1