shopping_list = ["milk", "pasta", "chimken", "rice", "soy sauce"]

# for item in shopping_list:
#     if item != "chimken":
#         print("Buy " + item)

for item in shopping_list:
    if item == "chimken":
        continue
        # break
    print("Buy " + item)