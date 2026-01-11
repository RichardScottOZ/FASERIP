#!/usr/bin/env python3

import random

# Script rank and effects to STDIN

effects = ["None", "Blunt Attack", "Edged Attack", "Shooting Attack",
           "Throwing Edged", "Throwing Blunt", "Energy", "Force", 
           "Grappling", "Grabbing", "Escaping", "Charging", "Dodging", 
           "Evading", "Blocking", "Catching", "Stun?", "Slam?", "Kill?"]

rank = ["", "SH0", "FB", "PR", "TY", "GD", "EX", "RM", "IN", "AM", "MN", 
        "UN", "SHX", "SHY", "SHZ", "CL1000", "CL3000", "CL5000", "Beyond"]

white_effects = ["WHITE", "MISS", "MISS", "MISS", "MISS", "MISS", "MISS", 
                 "MISS", "MISS", "MISS", "MISS", "MISS", "NONE", "AUTOHIT", 
                 "-6 CS", "AUTOHIT", "1-10", "GRAND SLAM", "ENDURANCE LOSS"]

green_effects = ["GREEN", "HIT", "HIT", "HIT", "HIT", "HIT", "HIT", "HIT", 
                 "MISS", "TAKE", "MISS", "HIT", "-2 CS", "EVASION", "-4 CS", 
                 "MISS", "1", "1 AREA", "E/S (EDGED/SHOOTING)"]

yellow_effects = ["YELLOW", "SLAM", "STUN", "BULLSEYE", "STUN", "HIT", 
                  "BULLSEYE", "BULLSEYE", "Partial", "GRAB", "ESCAPE", "SLAM", 
                  "-4 CS", "+1 CS", "-2 CS", "DAMAGE", "NO", "STAGGER", "NO"]

red_effects = ["RED", "STUN", "KILL", "KILL", "KILL", "STUN", "KILL", "STUN", 
               "HOLD", "BREAK", "REVERSE", "STUN", "-6 CS", "+2 CS", "+1 CS", 
               "CATCH", "NO", "NO", "NO"]

# Advanced Universal Table
universal_table = [
    ("SH0", -1, 66, 95, 100),
    ("FB", -1, 61, 91, 100),
    ("PR", -1, 56, 86, 100),
    ("TY", -1, 51, 81, 98),
    ("GD", -1, 46, 76, 98),
    ("EX", -1, 41, 71, 95),
    ("RM", -1, 36, 66, 95),
    ("IN", -1, 31, 61, 91),
    ("AM", -1, 26, 56, 91),
    ("MN", -1, 21, 51, 86),
    ("UN", -1, 16, 46, 86),
    ("SHX", -1, 11, 41, 81),
    ("SHY", -1, 7, 41, 81),
    ("SHZ", -1, 4, 36, 76),
    ("CL1000", -1, 2, 36, 76),
    ("CL3000", -1, 2, 31, 71),
    ("CL5000", -1, 2, 26, 66),
    ("Beyond", -1, 2, 21, 61)
]

# Generate d100 roll
d100 = random.randint(1, 100)

print("\n")
print("CHOOSE EFFECT")

count_effect = 0
for effect in effects:
    print(f"{count_effect}: {effect}  ", end="")
    count_effect += 1
print("\n")

chosen_effect = input()
while not chosen_effect.isdigit() or int(chosen_effect) > 18:
    print("CHOOSE EFFECT")
    chosen_effect = input()

chosen_effect = int(chosen_effect)
print(f"Effect = {effects[chosen_effect]}\n")

print("CHOOSE RANK")
count_rank = 0
for r in rank:
    print(f"{count_rank}: {r}  ", end="")
    count_rank += 1
print("\n")

chosen_rank = input()
while not chosen_rank.isdigit() or int(chosen_rank) > 18:
    print("CHOOSE RANK")
    chosen_rank = input()

chosen_rank = int(chosen_rank)
print(f"Rank = {rank[chosen_rank]} - {effects[chosen_effect]} - ", end="")

d100_result = "WHITE"
color_result = white_effects[chosen_effect]

for column in universal_table:
    if column[0] == rank[chosen_rank]:
        # found rank column
        column_rank = column[0]
        column_white = column[1]
        column_green = column[2]
        column_yellow = column[3]
        column_red = column[4]
        
        if d100 >= column_green:
            d100_result = "GREEN"
            color_result = green_effects[chosen_effect]
        if d100 >= column_yellow:
            d100_result = "YELLOW"
            color_result = yellow_effects[chosen_effect]
        if d100 >= column_red:
            d100_result = "RED"
            color_result = red_effects[chosen_effect]
        print(f"Roll : {d100} - {d100_result} - {color_result}")
        break
