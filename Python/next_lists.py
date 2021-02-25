
computer_parts = ["computer",
                  "monitor",
                  "mouse",
                  "keyboard",
                  "mouse mat"
                  ]
for part in computer_parts:
    print(part)
    
print()    
print(computer_parts[2])
print()
print(computer_parts[0:3])
print(computer_parts[-2])      
a = computer_parts
print("Added hard drive to the list")
a.append("hard drive")
print(a)