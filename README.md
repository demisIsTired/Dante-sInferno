
<div align="center">
<h1 align="center">
<img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-markdown-open.svg" width="100" />
<br>
Dante-sInferno
</h1>
<h3 align="center">📍 Dante's Inferno: The ultimate guide to code management.</h3>
<h3 align="center">🚀 Developed with the software and tools below.</h3>
<p align="center">

<img src="https://img.shields.io/badge/OpenAI-412991.svg?style=for-the-badge&logo=OpenAI&logoColor=white" alt="types-mock" />
<img src="https://img.shields.io/badge/Python-3776AB.svg?style=for-the-badge&logo=Python&logoColor=white" alt="langcodes" />
<img src="https://img.shields.io/badge/precommit-FAB040.svg?style=for-the-badge&logo=pre-commit&logoColor=black" alt="types-setuptools" />
<img src="https://img.shields.io/badge/spaCy-09A3D5.svg?style=for-the-badge&logo=spaCy&logoColor=white" alt="isort" />
<img src="https://img.shields.io/badge/Pytest-0A9EDC.svg?style=for-the-badge&logo=Pytest&logoColor=white" alt="mypy" />

<img src="https://img.shields.io/badge/pandas-150458.svg?style=for-the-badge&logo=pandas&logoColor=white" alt="typing_extensions" />
<img src="https://img.shields.io/badge/NumPy-013243.svg?style=for-the-badge&logo=NumPy&logoColor=white" alt="openai" />
<img src="https://img.shields.io/badge/Hypothesis-BD1C2B.svg?style=for-the-badge&logo=Hypothesis&logoColor=white" alt="dacite" />
<img src="https://img.shields.io/badge/tqdm-FFC107.svg?style=for-the-badge&logo=tqdm&logoColor=black" alt="jinja2" />
</p>

</div>

---
## 📚 Table of Contents
- [📚 Table of Contents](#-table-of-contents)
- [📍Overview](#-introdcution)
- [🔮 Features](#-features)
- [⚙️ Project Structure](#project-structure)
- [🧩 Modules](#modules)
- [🏎💨 Getting Started](#-getting-started)
- [🗺 Roadmap](#-roadmap)
- [🤝 Contributing](#-contributing)
- [🪪 License](#-license)
- [📫 Contact](#-contact)
- [🙏 Acknowledgments](#-acknowledgments)

---

## 📍Overview

GitHub is a project that allows for easy collaboration and code sharing between developers. It also provides a platform for developers to showcase their work and find other developers to work with.

## 🔮 Feautres

> `[📌  INSERT-PROJECT-FEATURES]`

---

<img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-github-open.svg" width="80" />

## ⚙️ Project Structure

```bash
.
├── include
│   ├── menuConfig.hpp
│   └── parallelJam.hpp
├── main.cpp
├── Makefile
├── README.md
├── source
│   ├── drawGame.cpp
│   ├── events.cpp
│   ├── gameLoop.cpp
│   ├── initGame.cpp
│   └── menuConfig.cpp
└── utils
    ├── font.ttf
    ├── map.txt
    ├── menu
    │   ├── background.png
    │   ├── menu_play_high.png
    │   ├── menu_play.png
    │   ├── menu_quit_high.png
    │   └── menu_quit.png
    └── tileset.png

5 directories, 18 files
```
---

<img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-src-open.svg" width="80" />

## 💻 Modules
<details closed><summary>.</summary>

| File     | Summary                                                                                                                         |
|:---------|:--------------------------------------------------------------------------------------------------------------------------------|
| main.cpp | This code is the main function for a game called Parallel Jam. It sets up the random seed and then calls the gameLoop function. |

</details>

<details closed><summary>Include</summary>

| File            | Summary                                                                                                                                                                                     |
|:----------------|:--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| parallelJam.hpp | This code is for a game module class for a game called "parallelJam". It includes variables and functions to initialize, delete, set, draw, and handle events for the game.                 |
| menuConfig.hpp  | This code creates a class called MenuConfig which is used to draw a menu and handle events in the game ParallelJam. It contains a loop, quit boolean, event, window, and vector of sprites. |

</details>

<details closed><summary>Source</summary>

| File           | Summary                                                                                                                                                                                                    |
|:---------------|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| menuConfig.cpp | This code is a menu configuration for the game "Dante's Inferno". It creates a window with a background image, a play button, and a quit button.                                                           |
| initGame.cpp   | This code is part of the GameModule class in the parallelJam project. It initializes the game by setting the player's position, score, and timer, as well as the enemy positions and pushes.               |
| gameLoop.cpp   | This code is a game loop for a game called ParallelJam. It includes the GameModule and MenuConfig classes, and it initializes the game, handles events, and draws the game while the game loop is running. |
| events.cpp     | This code handles events for the game ParallelJam. It checks for keyboard events, moves the map and player, moves enemies, checks for collisions, and handles the score.                                   |
| drawGame.cpp   | This code draws a game with a map, enemies, and a player. It includes functions to draw the title, text, map, player, and enemies.                                                                         |

</details>

<details closed><summary>Utils</summary>

| File        | Summary                                                                                                           |
|:------------|:------------------------------------------------------------------------------------------------------------------|
| tileset.png | This code is an error message indicating that a file could not be decoded because it is not a text or UTF-8 file. |
| font.ttf    | This code is an error message indicating that a file could not be decoded because it is not a text or UTF-8 file. |

</details>

<details closed><summary>Utils/menu</summary>

| File               | Summary                                                                                                           |
|:-------------------|:------------------------------------------------------------------------------------------------------------------|
| menu_quit_high.png | This code is an error message indicating that a file could not be decoded because it is not a text or UTF-8 file. |
| menu_quit.png      | This code is an error message indicating that a file could not be decoded because it is not a text or UTF-8 file. |
| menu_play_high.png | This code is an error message indicating that a file could not be decoded because it is not a text or UTF-8 file. |
| menu_play.png      | This code is an error message indicating that a file could not be decoded because it is not a text or UTF-8 file. |
| background.png     | This code is an error message indicating that a file could not be decoded because it is not a text or UTF-8 file. |

</details>
<hr />

## 🚀 Getting Started

### ✅ Prerequisites

Before you begin, ensure that you have the following prerequisites installed:
> `[📌  INSERT-PROJECT-PREREQUISITES]`

### 💻 Installation

1. Clone the Dante-sInferno repository:
```sh
git clone https://github.com/demisIsTired/Dante-sInferno
```

2. Change to the project directory:
```sh
cd Dante-sInferno
```

3. Install the dependencies:
```sh
g++ -o myapp main.mm
```

### 🤖 Using Dante-sInferno

```sh
./myapp
```

### 🧪 Running Tests
```sh
#run tests
```

<hr />

## 🛠 Future Development
- [X] [📌  COMPLETED-TASK]
- [ ] [📌  INSERT-TASK]
- [ ] [📌  INSERT-TASK]


---

## 🤝 Contributing
Contributions are always welcome! Please follow these steps:
1. Fork the project repository. This creates a copy of the project on your account that you can modify without affecting the original project.
2. Clone the forked repository to your local machine using a Git client like Git or GitHub Desktop.
3. Create a new branch with a descriptive name (e.g., `new-feature-branch` or `bugfix-issue-123`).
```sh
git checkout -b new-feature-branch
```
4. Make changes to the project's codebase.
5. Commit your changes to your local branch with a clear commit message that explains the changes you've made.
```sh
git commit -m 'Implemented new feature.'
```
6. Push your changes to your forked repository on GitHub using the following command
```sh
git push origin new-feature-branch
```
7. Create a pull request to the original repository.
Open a new pull request to the original project repository. In the pull request, describe the changes you've made and why they're necessary. 
The project maintainers will review your changes and provide feedback or merge them into the main branch.

---

## 🪪 License

This project is licensed under the `[📌  INSERT-LICENSE-TYPE]` License. See the [LICENSE](https://docs.github.com/en/communities/setting-up-your-project-for-healthy-contributions/adding-a-license-to-a-repository) file for additional info.

---

## 🙏 Acknowledgments

[📌  INSERT-DESCRIPTION]


---

