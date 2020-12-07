from random import randint

while True:
    computer_choice = number = randint(0, 2)  # 0=Rock 1=Paper 2=Scissors
    choice = input("Rock, Paper, or Scissors?")
    if choice == "Rock":
        if computer_choice == 0:
            print("Tie")
        elif computer_choice == 1:
            print("You lose. Paper -> Rock")
        elif computer_choice == 2:
            print("You win. Rock -> Scissors")
    elif choice == "Paper":
        if computer_choice == 0:
            print("You win. Paper -> Rock")
        elif computer_choice == 1:
            print("Tie")
        elif computer_choice == 2:
            print("You lose. Scissors -> Paper")
    elif choice == "Scissors":
        if computer_choice == 0:
            print("You lose. Rock -> Scissors")
        elif computer_choice == 1:
            print("You win. Scissors -> Paper")
        elif computer_choice == 2:
            print("Tie")
    else:
        print("Invalid input")
