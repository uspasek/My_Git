name = input("dawaj lanek")
age = int(input("How old are you ? "))
print(age)
    
if age < 18 & age != 1 :
    print("You are {0} years too young child".format(18 - age))
elif age == 1:
    print("you are {0} year old childy ".format(age))
else:
    print("you are {0} years old and allowed to vote".format(age))