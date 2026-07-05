# MathGame


# Math Game – C++ Console Application

A simple interactive math quiz game built with C++.  
It generates random arithmetic questions based on your chosen settings, tracks your score, and gives instant visual and sound feedback.

---

## Features

- Choose how many questions you want to answer.
- Pick a difficulty level: Easy, Medium, Hard, or Mixed.
- Pick an operation type: Addition, Subtraction, Multiplication, Division, or Mixed.
- Questions are generated automatically according to your choices.
- Screen colour changes to green for correct answers and red for wrong ones.
- A beep sound plays when you answer incorrectly.
- Final report shows your total correct/wrong answers and whether you passed or failed.
- Option to replay without restarting the program.

---

## How to Play

1. Run the program.
2. Enter a positive number for how many questions you'd like.
3. Choose difficulty:
   - `1` = Easy  
   - `2` = Medium  
   - `3` = Hard  
   - `4` = Mixed (random per question)
4. Choose operation type:
   - `1` = Addition  
   - `2` = Subtraction  
   - `3` = Multiplication  
   - `4` = Division  
   - `5` = Mixed (random per question)
5. For each question, type your answer and press Enter.
6. After the last question, the final score and result are displayed.
7. Enter `Y` or `y` to play again, or any other key to exit.

---

## Compilation and Execution

This project uses Windows‑specific functions (`windows.h`), so it runs best on Windows.

Compile with any C++ compiler that supports C++11 or later, for example:

```bash
g++ MathGame.cpp -o MathGame.exe
