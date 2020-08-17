"""

This is a quick script I wrote to help me memorize hex number addition.
You can set the numbers it will put into an equation using
MIN_INT and MAX_INT. Set HEX_FOCUS to a number between MIN_INT and
MAX_INT to test yourself using only that hex int. For example, setting
HEX_FOCUS to 12 will only test 0xC. ("C + 4 = ?", "C + 7 = ?"... etc)

If you get one wrong, it keeps the equation you got wrong in a dict
and comes back to it more often than others until you've gotten it
right 5 times in a row.

It also lets you know whenever the number you've gotten in a row
increments by 10.

To do: Make it OOP. Make it do subtraction. Turn it into a Django app.

"""


import random


MIN_INT = 1
MAX_INT = 18

INCORRECT_REASK_WEIGHT = .4

HEX_FOCUS = None

print(f"")
incorrect_dict = {}

def add_to_incorrect_dict(num1, num2, incorrect_dict):
    if not incorrect_dict.get(f"{num1} + {num2}"):
        equation_entry = {
            "num1": num1,
            "num2": num2,
            "correct_count": 0
        }
        incorrect_dict[f"{num1} + {num2}"] = equation_entry
    else:
        incorrect_dict[f"{num1} + {num2}"]["correct_count"] -= 1
    return incorrect_dict

CORRECT_COUNT = 0

while True:
    num1 = random.randint(1, MAX_INT - 3)
    num2 = random.randint(1, MAX_INT - 3)

    answer = num1 + num2

    if (answer <= 14) or (answer > MAX_INT) or (HEX_FOCUS) and (num1 != HEX_FOCUS and num2 != HEX_FOCUS):
        continue

    if CORRECT_COUNT and CORRECT_COUNT % 10 == 0:
        print(f"You got {CORRECT_COUNT} in a row.")

    reask = random.randint(1, 10)

    if reask <= INCORRECT_REASK_WEIGHT * 10 and incorrect_dict:

        reask_entry = incorrect_dict[random.choice(list(incorrect_dict.keys()))]
        num1 = reask_entry["num1"]
        num2 = reask_entry["num2"]

        answer = num1 + num2
    try:
        attempt = int(input(f"{num1:X} + {num2:X} = "), 16)
    except ValueError as e:
        print("INVALID INPUT\n")
        continue

    if attempt == num1 + num2:
        CORRECT_COUNT += 1
        if incorrect_dict.get(f"{num1} + {num2}"):
            incorrect_dict[f"{num1} + {num2}"]["correct_count"] += 1
            if incorrect_dict[f"{num1} + {num2}"]["correct_count"] > 5:
                del incorrect_dict[f"{num1} + {num2}"]
                print(f"Removing entry from dictionary")
                if not incorrect_dict:
                    print(f"Dictionary cleared!")
    else:
        CORRECT_COUNT = 0
        incorrect_dict = add_to_incorrect_dict(num1, num2, incorrect_dict)
        print(f"Wrong. Correct answer: {answer:X}")
        print(f"Incorrect dictionary length: {len(list(incorrect_dict.keys()))}")
