shopping_list = ["milk", "pasta", "chimken", "rice", "soy sauce"]

item_to_find = "rice"
found_at = None

# for index in range(len(shopping_list)):
#     if shopping_list[index] == item_to_find:
#         found_at = index 
#         break
if item_to_find in shopping_list:
    found_at = shopping_list.index(item_to_find)
if found_at == None:
    print("Item doesnt exist on a shopping_list")
else:
    print("Item found at position {}".format(found_at))