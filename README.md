# Teachinator – OOP Guess-the-Teacher Console Game

A console-based C++ program that guesses which teacher a user is thinking of by asking simple questions. Built as a 2nd semester OOP project using structures, file handling, and a scoring-based matching system.

'Check the slides to understand the whole Project'

---

## 📌 Features
- Teacher-guessing system for both male and female teachers  
- Reads teacher attributes from external `.txt` files  
- Scoring-based decision logic  
- Colorful Windows console output  
- Fully modular and structured OOP design  

## 🛠️ Tech Stack & Concepts

**Language:**  
- C++

**Libraries Used:**  
- `<iostream>`  
- `<fstream>`  
- `<iomanip>`  
- `<Windows.h>`  
- `<string>`

**Key Concepts:**  
- Structures  
- Functions  
- File I/O  
- Data parsing  
- Condition-based logic  
- Input validation  
- Windows console styling  

---

## ▶️ Program Flow
1. User selects male or female  
2. Program loads the respective data file  
3. Asks a series of questions  
4. Scores each teacher based on matching attributes  
5. Outputs the teacher with full points  
6. If no match is found, displays an error message


## How Questions Are Asked

1. The program first asks the user whether the teacher is **Male** or **Female**.  
2. Based on the choice, a series of questions is asked:

- **Male Teachers:**
  - Hair color: `Mixed` or `Black`
  - Facial hair: `Mustache` or `Beard`
  - Clothes: `Shalwar Kameez` or `Pant Shirt`
  - Age: Above 35 (`Yes`/`No`)  

- **Female Teachers:**
  - Wears Abaya: `Yes`/`No`
  - Wears Glasses: `Yes`/`No`
  - Young or Old: `Yes`/`No`  

> The program uses loops and input validation so only correct responses are accepted.


## How Data is Stored

- Male and Female teacher details are stored in plain text files inside the `Teachinator` folder:  

  - `MaleData.txt` contains one male teacher per line:  
    ```
    HairColor FacialHair Clothes Old
    ```
    Example:  
    ```
    mixed mustache shalwar yes
    black beard pant no
    ```

  - `FemaleData.txt` contains one female teacher per line:  
    ```
    Abaya Glasses Old
    ```
    Example:  
    ```
    yes yes no
    no no yes
    yes no yes
    ```

- These files are read into **C++ structures** (`Male_Teacher` and `Female_Teacher`) when the program starts.


## How the Answer is Determined

1. Each teacher has a **Points** counter initialized at 0.  
2. For every question answered by the user, the program compares the answer to each teacher’s stored attributes.  
   - If the attribute matches, that teacher’s `Points` is incremented by 1.  
3. After all questions are asked, the teacher with **points equal to the total number of questions for that gender** is selected as the guessed teacher.  
4. If no teacher matches all answers, the program outputs a **“no match found”** message and prompts the user to try again.


---
## ⚙️ Setup & Usage

Follow these steps to run Teachinator:

1. **Download the repository**  
   Clone this repo or download it as a ZIP and extract it to your preferred location.

2. **Locate the `Teachinator` folder**  
   Inside the repo, you will find a folder named `Teachinator` containing:
   - `MaleData.txt`
   - `FemaleData.txt`
   - `Teachinator.cpp`

3. **Copy the `Teachinator` folder to `C:\`**  
   Make sure the path is exactly `C:\Teachinator` so that the program can access the data files.

4. **Open your C++ IDE or Compiler**  
   - Open `Teachinator.cpp` in your preferred IDE (e.g., Code::Blocks, Visual Studio) or compile via terminal.

5. **Build and run the program**  
   - Compile the code.
   - Run the executable.
   - Follow the on-screen questions to play the game.

6. **Replay**  
   At the end, you can choose to run the program again if you want to guess another teacher.


## ⚠️ Notes
- Ensure the text files `MaleData.txt` and `FemaleData.txt` are present in `C:\Teachinator`.
- Only valid answers are accepted (e.g., Male/Female, Yes/No, Mustache/Beard, etc.)
- The game uses console colors to enhance the experience (works on Windows).

---

## 👨‍💻 Author
- Semester: 2nd Semester (2023)
- Project Type: OOP C++ Project  
- Developed by: Roshnab Afraz
