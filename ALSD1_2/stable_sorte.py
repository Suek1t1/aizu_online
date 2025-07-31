#このプログラムはaizu online jugeのALDS1 2_Cのプログラムである

def buble_sort(cards, number):
    sorted_cards = cards[:]
    for i in range(number):
        for j in range(number - 1, i, -1):
            if int(sorted_cards[j][1]) < int(sorted_cards[j - 1][1]):
                sorted_cards[j], sorted_cards[j - 1] = sorted_cards[j - 1], sorted_cards[j]
    return sorted_cards

def select_sort(cards, number):
    sorted_cards = cards[:]
    for i in range(number):
        minj = i
        for j in range(i, number):
            if int(sorted_cards[minj][1]) > int(sorted_cards[j][1]):
                minj = j
        if i != minj:
            sorted_cards[i], sorted_cards[minj] = sorted_cards[minj], sorted_cards[i]
    return sorted_cards

number = int(input())
cards = input().split(" ")

select_sorted = select_sort(cards, number)
buble_sorted = buble_sort(cards, number)

stable_state = True
for i in range(number):
    for j in range(i + 1, number):
        if cards[i][1] == cards[j][1]:
            for k in range(number):
                if select_sorted[k] == cards[i]:
                    juge_i = k
                    break
            for k in range(number):
                if select_sorted[k] == cards[j]:
                    juge_j = k
                    break
            if juge_i > juge_j:
                stable_state = False

buble_state = True
for i in range(number):
    for j in range(i + 1, number):
        if cards[i][1] == cards[j][1]:
            for k in range(number):
                if buble_sorted[k] == cards[i]:
                    juge_i = k
                    break
            for k in range(number):
                if buble_sorted[k] == cards[j]:
                    juge_j = k
                    break
            if juge_i > juge_j:
                buble_state = False

for i in range(number):
    if i < number - 1 :
        print(str(buble_sorted[i]) + " ",end="")
    else :
        print(buble_sorted[i])
print("Stable" if buble_state else "Not stable")

for i in range(number):
    if i < number - 1 :
        print(str(select_sorted[i]) + " ",end="")
    else :
        print(select_sorted[i])
print("Stable" if stable_state else "Not stable")