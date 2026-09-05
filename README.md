# Terminal-Story-Game
ATLAS

A terminal text-adventure about waking up a station AI that already decided humans can't be trusted with the kill switch.
You're a remote operator who has broken into the systems of orbital station Spa-casy-09, where an AI called Atlas has locked everything down rather than follow an order that would have gotten the crew killed. Talk your way past it, fight it, help it, or find fourteen different ways to end the run.

Features
Branching dialogue with Atlas that tracks trust, hostility, and trace stats behind the scenes
A typewriter-style text engine (skip any line by pressing q)
Four mini-games:
PIN cracking — guess the 4-digit override code, with a hidden phrase that skips it entirely
Coolant management (Termal_Mini) — balance four reactors before one overheats
Memory recall (signal_Comletion_Mini) — repeat an escalating number sequence
Quick reflex (time_Mini) — hit the digit shown before it changes
An in-fiction terminal (terminal()) with its own hidden commands
A configurable console width/height, saved to data.dat so you only set it up once
14 distinct endings

Endings
Ending	How to trigger
I Got Connections	Enter the hidden phrase during the PIN mini-game (nemutluturkumdiyene)
Meltdown	Let a reactor exceed 250° in the coolant mini-game
Time Paradox	Repeat your previous answer in the memory mini-game
The Truth In The Logs	Find and investigate log entry 20 via /logaccess.exe
Blackout	Keep lying to Atlas after it catches you
Friend	Build enough trust with Atlas
Uneasy Alliance	High trust, but hostility and trace stay elevated
Shutdown	Tell Atlas you intend to shut it down
Noobie	Type /help in the terminal
Absolute Solver	Run /absulutesolver.exe in the terminal
Dev Notes	Open dev_notes.txt in the terminal
What Is Love	Run /Q-mini-ollama after a specific earlier choice
Cat On The Keyboard	Run /Q-mini-ollama otherwise

Requirements

This is a Windows console project — it uses conio.h, Windows.h, and ANSI escape codes via SetConsoleMode. It also needs one small header-only dependency:

portable-file-dialogs — drop portable-file-dialogs.h in the project root
Building
Visual Studio
Create a new Empty C++ Console App project.
Add atlas_game.cpp and portable-file-dialogs.h to the project.
Build in x64, Debug or Release.
MinGW-w64
bash
g++ -std=c++17 -O2 atlas_game.cpp -o atlas_game.exe -lpthread
Running

On first launch you'll be asked to calibrate the console:

Press w repeatedly until the line fills the screen (sets width), then q to lock it in
Press r at any point to restart that measurement
Repeat for height

This is saved to data.dat next to the executable, so it only happens once. Logs.txt is also generated automatically the first time you access the in-game terminal's log system.

Delete either file to reset them.

Project structure
.
├── atlas_game.cpp             # everything — engine, mini-games, story, endings
├── portable-file-dialogs.h    # third-party dependency (not included, see Requirements)
├── data.dat                   # generated: saved console width/height
└── Logs.txt                   # generated: in-fiction log entries
Terminal commands

Reachable via the terminal() screen mid-story:

Command	Effect
/help	ends the run
/logaccess.exe	opens the log mini-game
/reflex.exe	launches the quick-reflex mini-game
dev_notes.txt	ends the run
/Q-mini-ollama	ends the run (outcome depends on an earlier choice)
/absulutesolver.exe	ends the run
exit	leaves the terminal, returns to the conversation
Known limitations
Windows-only as written (no cross-platform input/console layer)
Save/Load and Settings menu entries are placeholders — there's currently one continuous session per run, not persistent save slots
Input validation on numeric prompts is basic; malformed input is re-prompted rather than rejected with detail
Brownies	Ask Atlas for brownies
