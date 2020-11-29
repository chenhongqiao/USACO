from random import randint

number = randint(1, 100)

print("Guess a number between 1 and 100")

#print(number)

while True:
    guess = int(input("Enter guess:"))
    if guess < number:
        print("Too low")
    elif guess > number:
        print("Too high")
    else:
        break

print("Correct!")