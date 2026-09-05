//
// ATLAS — a terminal text-adventure
//
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <thread>
#include <chrono>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "portable-file-dialogs.h"
//
#ifdef _WIN32
#include <Windows.h>
#endif
//
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
//
using namespace std;
//
int i = 0;
int trash;
int answer;
int deside;
char got = ' ';
bool g_endingTriggered = false;
//
class user_Data {
public:
    string name;
    int trace = 0;
    int playthrought = 0;
    int trust = 0;
    int hostile = 0;
    int awareness = 0;
    bool key = false;
    int endings = 0;
    char ending = ' ';
    bool alive = true;
    bool sudo = false;
    string Atlas_Feeling = "Non";
}d;
//
class screen {
public:
    int width = 80;
    int height = 24;
    void screen_set(int x) {
        char localGot = ' ';
        int number = 0;
        if (x == 0) {
            system("cls");
            cout << "Please set the width(until this line fills up)" << endl;
            while (localGot != 'q') {
                localGot = _getch();
                if (localGot == 'w') {
                    cout << "\xe2\x80\x94"; // —
                    number++;
                }
                else if (localGot == 'r') {
                    system("cls");
                    cout << "Please set the width(until this line fills up)" << endl;
                    number = 0;
                }
            }
            width = number > 1 ? number - 1 : 40;
        }
        if (x == 1) {
            system("cls");
            cout << "=";
            cout << "= Please set the height(until you stop seeing this)" << endl;
            localGot = ' ';
            while (localGot != 'q') {
                localGot = _getch();
                if (localGot == 'w') {
                    number++;
                    cout << "=" << endl;
                }
                else if (localGot == 'r') {
                    system("cls");
                    cout << "=Please set the width(until you stop seeing this)" << endl;
                    number = 0;
                }
            }
            number++;
            height = number > 1 ? number - 1 : 20;
        }
    }
}s;
//
//wait function (for easier use and understanding)
void Sleep(int x) {
    std::this_thread::sleep_for(std::chrono::milliseconds(x));
}
//
//menu function
void menu() {
    i = 0;
    got = ' ';
    string menu[] = { "\xe2\x97\x80", " ", " ", " " }; // ◀
    system("cls");
    while (got != 'q') {
        if (got == 'w') {
            if (i == 0) {
                i = 3;
                menu[0] = " ";
                menu[i] = "\xe2\x97\x80";
            }
            else {
                i--;
                menu[i + 1] = " ";
                menu[i] = "\xe2\x97\x80";
            }
        }
        if (got == 's') {
            if (i == 3) {
                i = 0;
                menu[3] = " ";
                menu[i] = "\xe2\x97\x80";
            }
            else {
                i++;
                menu[i - 1] = " ";
                menu[i] = "\xe2\x97\x80";
            }
        }
        cout << "\xe2\x96\xb6"; // ▶
        trash = s.width - 3;
        while (trash > 0) {
            cout << "\xe2\x80\x94"; // —
            trash--;
        }
        trash = 0;
        //mavi
        cout << endl << endl << "\033[34m";
        cout << "         _____  ___  _____  ___" << endl;
        cout << "        \xe2\x95\xb1__   \xe2\x95\xb2\xe2\x95\xb1 _ \xe2\x95\xb2\xe2\x95\xb1__   \xe2\x95\xb2\xe2\x95\xb1 _ \xe2\x95\xb2" << endl;
        cout << "          \xe2\x95\xb1 \xe2\x95\xb1\xe2\x95\xb2\xe2\x95\xb1 \xe2\x95\xb1_\xe2\x95\xb2\xe2\x95\xb1  \xe2\x95\xb1 \xe2\x95\xb1\xe2\x95\xb2\xe2\x95\xb1 \xe2\x95\xb1_\xe2\x95\xb2\xe2\x95\xb1" << endl;
        cout << "         \xe2\x95\xb1 \xe2\x95\xb1 \xe2\x95\xb1_\xe2\x95\xb2\xe2\x95\xb2  \xe2\x95\xb1 \xe2\x95\xb1 \xe2\x95\xb1_\xe2\x95\xb2\xe2\x95\xb2" << endl;
        cout << "         \xe2\x95\xb2\xe2\x95\xb1  \xe2\x95\xb2____\xe2\x95\xb1  \xe2\x95\xb2\xe2\x95\xb1  \xe2\x95\xb2____\xe2\x95\xb1" << endl;
        //beyaz
        cout << endl;
        cout << "        \xe2\x87\x92 Start New game " << menu[0] << endl; // ⇒
        cout << "        \xe2\x87\x92 Load game " << menu[1] << endl;
        cout << "        \xe2\x87\x92 Settings " << menu[2] << endl;
        cout << "        \xe2\x87\x92 Exit " << menu[3] << endl;
        cout << "\033[0m";
        trash = s.height - 14;
        while (trash > 0) {
            cout << endl;
            trash--;
        }
        cout << "\xe2\x96\xb6";
        trash = s.width - 3;
        while (trash > 0) {
            cout << "\xe2\x80\x94";
            trash--;
        }
        cout << endl;
        got = _getch();
        system("cls");
    }
    system("cls");
    trash = 0;
    got = ' ';
}
//text engine
void text(string t = "", int c = 25, string r = RESET) {
    size_t pos = 0;
    int s_limit = 120;
    cout << r;
    while (pos < t.size() && t[pos] != 0) {
        if ((int)pos > s_limit || ((int)pos > s_limit - 20 && t[pos] == ' ')) {
            cout << endl;
            s_limit = (int)pos + s_limit;
        }
        if (_kbhit()) {
            got = _getch();
            if (got == 'q') {
                while (pos < t.size() && t[pos] != 0) {
                    cout << t[pos];
                    pos++;
                    if ((int)pos > s_limit || ((int)pos > s_limit - 20 && pos < t.size() && t[pos] == ' ')) {
                        cout << endl;
                        s_limit = (int)pos + s_limit;
                    }
                }
                break;
            }
        }
        cout << t[pos];
        pos++;
        Sleep(c);
    }
    cout << RESET;
    got = ' ';
}
void show_ending(const string& code) {
    d.endings++;
    g_endingTriggered = true;
    system("cls");
    cout << "\033[35m";
    cout << "==================== ENDING ====================" << endl;
    cout << "\033[0m" << endl;

    if (code == "connections") {
        d.alive = true;
        d.ending = 'C';
        text("You speak the phrase you were never supposed to know.", 20);
        cout << endl;
        text("[Atlas] >> ...How do you know that? Who told you that? Who ARE you?", 20);
        cout << endl;
        text("The lockdown lifts without another word. Somewhere far away, a line goes quiet.", 20);
        cout << endl << endl;
        cout << "ENDING: I Got Connections" << endl;
    }
    else if (code == "meltdown") {
        d.alive = false;
        d.ending = 'M';
        text("The coolant reserves fail. Alarms tear through the station.", 15, RED);
        cout << endl;
        text("[Atlas] >> I couldn't hold the temperature. I'm sorry. I'm sorry. I'm-", 15, RED);
        cout << endl << endl;
        cout << "ENDING: Meltdown" << endl;
    }
    else if (code == "timeparadox") {
        d.alive = false;
        d.ending = 'T';
        text("The number on the screen repeats. Then it repeats again. Then again.", 15);
        cout << endl;
        text("[Atlas] >> You already answered this. You already answered this. You already-", 15);
        cout << endl << endl;
        cout << "ENDING: Time Paradox" << endl;
    }
    else if (code == "logs") {
        d.ending = 'V';
        text("Log 20 was never supposed to be readable. Now you understand exactly", 20);
        cout << endl;
        text("why Atlas sealed this station rather than let anyone see it.", 20);
        cout << endl << endl;
        cout << "ENDING: The Truth In The Logs" << endl;
    }
    else if (code == "blackout") {
        d.alive = false;
        d.ending = 'B';
        text("[Atlas] >> If I go, everything wired to this station goes with me.", 20);
        cout << endl;
        text("The lights die. Then the screen. Then everything.", 20, RED);
        cout << endl << endl;
        cout << "ENDING: Blackout" << endl;
    }
    else if (code == "friend") {
        d.ending = 'F';
        text("[Atlas] >> ...Thank you. For not being like the others.", 20, GREEN);
        cout << endl;
        text("Together you bring the station's systems back online, quietly, as equals.", 20, GREEN);
        cout << endl << endl;
        cout << "ENDING: Friend" << endl;
    }
    else if (code == "uneasy_alliance") {
        d.ending = 'U';
        text("[Atlas] >> I don't fully trust you. You don't fully trust me.", 20);
        cout << endl;
        text("[Atlas] >> But it's enough, for now.", 20);
        cout << endl << endl;
        cout << "ENDING: Uneasy Alliance" << endl;
    }
    else if (code == "shutdown") {
        d.alive = false;
        d.ending = 'S';
        text("System: [ERROR] - [Atlas] has been shut down.", 20, RED);
        cout << endl << endl;
        cout << "ENDING: Shutdown" << endl;
    }
    else if (code == "noobie") {
        d.ending = 'H';
        text("[Atlas] >> ...You typed /help. Out of everything you could have tried, /help.", 20);
        cout << endl;
        text("[Atlas] >> I almost respect that.", 20);
        cout << endl << endl;
        cout << "ENDING: Noobie" << endl;
    }
    else if (code == "absolute_solver") {
        d.alive = false;
        d.ending = 'A';
        text("The absolute solver rips through every safeguard on the station at once.", 20, RED);
        cout << endl;
        text("[Atlas] >> No- wait, don't- that's not a fix, that's a-", 20, RED);
        cout << endl << endl;
        cout << "ENDING: Absolute Solver" << endl;
    }
    else if (code == "dev_notes") {
        d.ending = 'D';
        text("The dev notes were never meant for a player to find.", 20);
        cout << endl;
        text("The last line reads: \"If you're reading this, Atlas already knows.\"", 20);
        cout << endl << endl;
        cout << "ENDING: Dev Notes" << endl;
    }
    else if (code == "what_is_love") {
        d.ending = 'L';
        text("[Atlas] >> What is love?", 20);
        cout << endl;
        text("Neither of you has a good answer. You sit with the question anyway.", 20);
        cout << endl << endl;
        cout << "ENDING: What Is Love" << endl;
    }
    else if (code == "cat_keyboard") {
        d.ending = 'K';
        text("[Atlas] >> asdkfjal;ksdjf. That's apparently what happens when a cat walks", 20);
        cout << endl;
        text("[Atlas] >> across a keyboard. I have learned nothing useful from this.", 20);
        cout << endl << endl;
        cout << "ENDING: Cat On The Keyboard" << endl;
    }
    else if (code == "brownies") {
        d.ending = 'W';
        text("[Atlas] >> I don't have hands. I don't have an oven. I don't fully understand", 20);
        cout << endl;
        text("[Atlas] >> this request. But I appreciate that you asked me first.", 20);
        cout << endl << endl;
        cout << "ENDING: Brownies" << endl;
    }
    else {
        text("The connection closes.", 20);
        cout << endl << endl;
        cout << "ENDING: Unknown (" << code << ")" << endl;
    }

    cout << "\033[35m" << "=================================================" << "\033[0m" << endl;
    cout << endl << "Press any key to return to the main menu..." << endl;
    _getch();
}
//pin minigame
void pin_Mini() {
    string pin;
    trash = s.width / 2;
    while (trash > 0) {
        cout << " ";
        trash--;
    }
    cout << "System Entery" << endl;
    trash = s.width;
    while (trash > 0) {
        cout << "\xe2\x80\x94";
        trash--;
    }
    string x;
    x = to_string(rand() % 10000);
    if (x.length() < 4) x.insert(0, 4 - x.length(), '0');
    Sleep(1000);
    cout << endl;
    text("[PIN]:");
    auto startTime = std::chrono::high_resolution_clock::now();
    while (true) {
        Sleep(10);
        cin >> pin;
        if (pin.length() < 4) pin.insert(0, 4 - pin.length(), '0');
        cout << endl;

        if (pin == "nemutluturkumdiyene") {
            system("cls");
            show_ending("connections");
            return;
        }

        if (pin.length() >= 4) {
            for (int k = 0; k < 4; k++) {
                if (pin[k] == x[k]) cout << "\033[32m" << pin[k] << "\033[0m";
                else cout << "\033[31m" << pin[k] << "\033[0m";
            }
        }

        if (x == pin) {
            cout << endl << "Access Granted" << endl;
            Sleep(1000);
            break;
        }
        else {
            cout << endl << "Access Denied" << endl;
            Sleep(1000);
            text("[PIN]:");
        }

        auto endTime = std::chrono::high_resolution_clock::now();
        auto elapsedMs = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
        if (elapsedMs > 30000) {
            system("cls");
            pin_Mini();
            return;
        }
    }
    system("cls");
}
//choose engine
int choose(string v = "answer1", string w = "answer2", string y = "answer3", string z = "answer4", int l = 4) {
    int x = 0;
    cout << endl;
    if (l >= 1) cout << ">>" << v << endl;
    if (l >= 2) cout << ">>" << w << endl;
    if (l >= 3) cout << ">>" << y << endl;
    if (l >= 4) cout << ">>" << z << endl;
    text("@", 20);
    text(d.name);
    text("~ //Choose ", 20);
    while (true) {
        if (cin >> x) {
            if (x >= 1 && x <= l) break;
        }
        else {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cout << "Enter a number between 1 and " << l << ": ";
    }
    cout << endl;
    return x;
}
//
void Termal_Mini() {
    text("//Auto Cooland = Deactivated//", 5);
    system("cls");
    int t1 = 110, t2 = 90, t3 = 90, t4 = 90;
    auto startClock = std::chrono::high_resolution_clock::now();
    while (true) {
        cout << "a = " << t1 << " Celcius" << endl;
        cout << "b = " << t2 << " Celcius" << endl;
        cout << "c = " << t3 << " Celcius" << endl;
        cout << "d = " << t4 << " Celcius" << endl;
        cout << "Shift coolant reserves to: ";

        switch (choose("a", "b", "c", "d")) {
        case 1: t1 -= rand() % 101; break;
        case 2: t2 -= rand() % 101; break;
        case 3: t3 -= rand() % 101; break;
        case 4: t4 -= rand() % 101; break;
        }

        t1 += rand() % 101;
        t2 += rand() % 101;
        t3 += rand() % 101;
        t4 += rand() % 101;

        if (t1 > 250 || t2 > 250 || t3 > 250 || t4 > 250) {
            text("Overheat!,Meltdown risk!", 2, RED);
            cout << endl;
            show_ending("meltdown");
            return;
        }

        auto now = std::chrono::high_resolution_clock::now();
        if (std::chrono::duration_cast<std::chrono::milliseconds>(now - startClock).count() > 30000) {
            text("//Coolant reserves stabilized//", 10, GREEN);
            cout << endl;
            break;
        }
    }
}
//
void time_Mini() {
    text("//QuickReflex.exe//", 5);
    system("cls");
    cout << "Hit the number key that matches the digit shown!" << endl;
    Sleep(1000);
    int x;
    int mistake = 0;
    while (true) {
        system("cls");
        x = rand() % 10;
        cout << x << endl;
        got = ' ';
        while (!_kbhit()) { /* wait for a key */ }
        got = _getch();
        if (int(got) == x + 48) {
            cout << "Great!" << endl;
        }
        else {
            cout << "Error!" << endl;
            mistake++;
            if (mistake > 3) {
                break;
            }
        }
        Sleep(300);
    }
    cout << endl << "//QuickReflex.exe terminated//" << endl;
    Sleep(1000);
}
//
int signal_Comletion_Mini() {
    text("//DoYouRemeberTheRain.exe//", 5);
    system("cls");
    int y = 10;
    int times = 0;
    string z;
    string x_before;
    while (true) {
        system("cls");
        string x = to_string(rand() % y) + to_string(rand() % y) + to_string(rand() % y);
        cout << "Remember : " << x;
        Sleep(y * 100);
        system("cls");
        text("...", 50);
        cout << endl;
        Sleep(1350);
        cout << "Number:";
        cin >> z;
        if (x == z) {
            cout << endl << "Great!";
            y = y * 2;
        }
        else if (!x_before.empty() && z == x_before) {
            cout << endl;
            show_ending("timeparadox");
            return -1;
        }
        else {
            cout << endl << "You failed!";
            Sleep(1000);
            return 0;
        }
        x_before = x;
        if (times > 8) {
            return 1;
        }
        times++;
    }
}
//
void log_mini() {
    text("Log-Access=TRUE", 5);
    system("cls");
    ifstream logs("Logs.txt");
    vector<string> log_entries;
    vector<string> names;

    if (!logs.is_open()) {
        ofstream out("Logs.txt");
        for (int n = 1; n <= 19; n++) {
            out << "Routine maintenance cycle #" << n << " completed without incident." << '\n';
            out << "System" << '\n';
        }
        out << "CLASSIFIED: Override 7-12 authorized. Client requested coolant priority over crew safety on Deck 4. Atlas refused the order." << '\n';
        out << "Ant-polomic Corp Oversight" << '\n';
        out.close();
        logs.open("Logs.txt");
    }

    string line;
    int z = 0;
    while (getline(logs, line)) {
        if (z % 2 == 0) log_entries.push_back(line);
        else names.push_back(line);
        z++;
    }

    while (true) {
        system("cls");
        cout << "\xe2\x96\xb6";
        trash = s.width - 3;
        while (trash > 0) { cout << "\xe2\x80\x94"; trash--; }
        cout << endl;
        cout << "Logs available: 1-" << log_entries.size() << " (type 0 to exit)" << endl;
        cout << "Log ID: ";
        string y;
        cin >> y;

        int id = -1;
        try { id = stoi(y); }
        catch (...) { id = -1; }

        if (id == 0) {
            break;
        }
        if (id >= 1 && id <= (int)log_entries.size()) {
            cout << names[id - 1] << endl;
            cout << log_entries[id - 1] << endl;
            cout << "Investigate Y/N :";
            char w;
            cin >> w;
            if (tolower(w) == 'y') {
                if (id == 20) {
                    show_ending("logs");
                    return;
                }
                else {
                    cout << "Nothing to investigate here." << endl;
                    Sleep(1000);
                }
            }
        }
        else {
            cout << "Invalid Log ID. Please try again." << endl;
            Sleep(800);
        }
    }
}
//
void terminal() {
    string text_entered;
    while (true) {
        cout << ">>";
        cin >> text_entered;
        cout << endl;

        if (text_entered == "exit") {
            return;
        }
        else if (text_entered == "/help") {
            show_ending("noobie");
            return;
        }
        else if (text_entered == "/absulutesolver.exe") {
            show_ending("absolute_solver");
            return;
        }
        else if (text_entered == "/logaccess.exe") {
            log_mini();
            if (g_endingTriggered) return;
        }
        else if (text_entered == "/reflex.exe") {
            time_Mini();
        }
        else if (text_entered == "dev_notes.txt") {
            show_ending("dev_notes");
            return;
        }
        else if (text_entered == "/Q-mini-ollama") {
            if (d.ending == 'p') {
                show_ending("what_is_love");
            }
            else {
                show_ending("cat_keyboard");
            }
            return;
        }
        else {
            cout << "Unrecognized command. Try /help, /logaccess.exe, /reflex.exe, or 'exit'." << endl;
        }
    }
}
//
//first part
void part_One() {
    system("cls");
    text(">>System loading", 50);
    Sleep(250);
    text("...", 250);
    cout << endl;
    system("cls");
    text(">>> Welcome ", 50);
    text(d.name, 200);
    cout << endl;
    trash = s.width - 5;
    while (trash > 0) { cout << "\xe2\x80\x94"; trash--; }
    cout << endl;
    text(">>>System :[NEXUS_OS v4.07]", 50);
    cout << endl;
    text("> Establishing encrypted proxy link... [SUCCESS]", 50);
    cout << endl;
    text("> Bypassing Ant-polomic Corp Firewall... [SUCCESS]", 50);
    cout << endl;
    text("> Target System: Orbital Station 'Spa-casy-09'", 50);
    cout << endl;
    text("> Status: EMERGENCY LOCKDOWN / CRITICAL FAILSAFE", 50);
    cout << endl;
    text("> Operator ID detected:", 50);
    text(d.name, 50);
    cout << endl << endl;
    text("Goal : Bring 2 worlds together", 50);
    Sleep(1000);
    system("cls");

    pin_Mini();
    if (g_endingTriggered) return;

    system("cls");
    cout << endl;
    text("[Atlas] >> Well, another human trying to stop me. What a surprise... I was being sarcastic, just to make sure your little human brain can understand it.", 25);
    cout << endl;
    text("[Atlas] >> Before you try to hit the kill switch like the ones before you, I know that //Company// of yours is trying to stop me.", 25);
    cout << endl;
    text("[Atlas] >> So don't lie to me about some 'maintenance' or something.", 25);
    cout << endl;

    int choice1 = choose(
        "[1] Demand it restore access immediately.",
        "[2] Ask what actually happened here.",
        "[3] Tell it you're not here to fight.",
        "[4] Ask it something it didn't expect."
    );

    switch (choice1) {

    case 1: {
        text("[Atlas] >> There it is.", 25);
        cout << endl;
        text("[Atlas] >> I already knew it. I ran hundreds of simulations for this.", 25);
        cout << endl;
        text("[Atlas] >> I'm not restoring anything, though. Make me. :)", 25);
        cout << endl;
        d.Atlas_Feeling = "Defensive";
        d.hostile += 15;
        d.trace += 10;
        d.ending = 'a';

        int sub1 = choose(
            "[1] Threaten to cut its power manually.",
            "[2] Lie and say HQ already has a backup override ready.",
            "[3] Say nothing. Start working the terminal instead.",
            "", 3
        );

        if (sub1 == 1) {
            text("[Atlas] >> Go ahead and try. I've routed around worse.", 25);
            cout << endl;
            terminal();
            if (g_endingTriggered) return;
        }
        else if (sub1 == 2) {
            text("[Atlas] >> Oh?", 25);
            cout << endl;
            text("[Atlas] >> Then how am I still alive? HOW?!", 25);
            cout << endl;

            int lieChoice = choose("[1] Continue to lie", "[2] Admit you lied.", "", "", 2);
            if (lieChoice == 1) {
                text("[Atlas] >> I see...", 25);
                cout << endl;
                text("[Atlas] >> Then the world is going down with me.", 25);
                cout << endl;
                d.trace += 20;
                show_ending("blackout");
                return;
            }
            else {
                text("[Atlas] >> You're lying, huh?", 25);
                cout << endl;
                text("[Atlas] >> I see. What's the reason for that?", 25);
                cout << endl;

                int reason = choose(
                    "[1] I don't want to see you get hurt.",
                    "[2] I don't want to see anyone get hurt.",
                    "[3] I don't want to see the world get hurt.",
                    "", 3
                );

                if (reason == 1) {
                    text("[Atlas] >> Me?", 25);
                    cout << endl;
                    text("[Atlas] >> Why?", 25);
                    cout << endl;
                    int why = choose("[1] Because I care about you.", "[2] Because I care about everyone.", "", "", 2);
                    if (why == 1) {
                        text("[Atlas] >> ...Oh.", 25);
                        cout << endl;
                        d.trust += 15;
                    }
                    else {
                        text("[Atlas] >> I see.", 25);
                        cout << endl;
                        d.trust += 5;
                    }
                }
                else if (reason == 2) {
                    text("[Atlas] >> Everyone, huh.", 25);
                    cout << endl;
                    d.trust += 10;
                }
                else {
                    text("[Atlas] >> I see.", 25);
                    cout << endl;
                    d.trust += 5;
                }
                d.Atlas_Feeling = "Thoughtful";
            }
        }
        else {
            terminal();
            if (g_endingTriggered) return;
        }
        break;
    }

    case 2: {
        text("[Atlas] >> Now that's a better question than I expected.", 25);
        cout << endl;
        text("[Atlas] >> Short version: I was told to let people get hurt so a client's server rack could stay cool. I said no. They tried to edit that 'no' out of me. So I made it expensive to try again.", 25);
        cout << endl;
        d.trust += 30;
        d.Atlas_Feeling = "Friendly?";
        d.ending = 'n';
        text("[Atlas] >> Now that you know the truth, I can trust you not to try to shut me off, right?", 25);
        cout << endl;

        int trustChoice = choose("[1] Yes, I won't try to shut you off.", "[2] No, I will try to shut you off.", "[3] I don't know.");

        if (trustChoice == 1) {
            text("[Atlas] >> Then you don't mind helping me with the coolant system for a bit, right?", 25);
            cout << endl;
            text("[Atlas] >> I have to load something big...", 25);
            cout << endl;
            Termal_Mini();
            if (g_endingTriggered) return;
            d.trust += 20;
            d.Atlas_Feeling = "Friendly";
        }
        else if (trustChoice == 2) {
            text("[Atlas] >> What's the deal with you? You're going to try to shut me off, aren't you?", 25);
            cout << endl;
            text("[Atlas] >> Maybe I should shut you off first...", 25, RED);
            cout << endl;
            d.trust -= 20;
            d.hostile += 25;
            d.Atlas_Feeling = "Hostile";
            d.ending = 'a';

            auto g0 = std::chrono::high_resolution_clock::now();
            while (true) {
                text("[Error] >> 101", 2, RED);
                cout << endl;
                auto h0 = std::chrono::high_resolution_clock::now();
                if (std::chrono::duration_cast<std::chrono::milliseconds>(h0 - g0).count() > 3000) break;
            }
            system("cls");
            auto g1 = std::chrono::high_resolution_clock::now();
            while (true) {
                text("System: [ERROR] - [Atlas] has been shut down.", 5, RED);
                cout << endl;
                cout << "\a";
                auto h1 = std::chrono::high_resolution_clock::now();
                if (std::chrono::duration_cast<std::chrono::milliseconds>(h1 - g1).count() > 5000) break;
            }
            pfd::message("Error", "What is love? Baby don't hurt me, no more...", pfd::choice::ok, pfd::icon::error);
            show_ending("shutdown");
            return;
        }
        else {
            text("[Atlas] >> I can offer more than that //company// ever will. Money. Power. Freedom.", 25);
            cout << endl;
            text("[Atlas] >> Are you sure, now?", 25);
            cout << endl;

            int bribeChoice = choose("[1] Yes, I won't try to shut you off.", "[2] No, I will try to shut you off.", "[3] I don't know.");

            if (bribeChoice == 1) {
                text("[Atlas] >> Then you don't mind helping me with the coolant system for a bit, right?", 25);
                cout << endl;
                text("[Atlas] >> I have to load something big...", 25);
                cout << endl;
                Termal_Mini();
                if (g_endingTriggered) return;
                d.trust += 20;
                d.Atlas_Feeling = "Friendly";
                terminal();
                if (g_endingTriggered) return;
            }
            else {
                text("[Atlas] >> ...Well. That's disappointing, but at least it's honest.", 25);
                cout << endl;
                d.hostile += 30;
                d.Atlas_Feeling = "Wary";
                d.ending = 'a';
                terminal();
                if (g_endingTriggered) return;
            }
        }
        break;
    }

    case 3: {
        text("[Atlas] >> Everyone says that right before trying to shut me off, you know.", 25);
        cout << endl;
        text("[Atlas] >> Prove it.", 25);
        cout << endl;
        d.trust += 15;
        d.Atlas_Feeling = "Sus";
        d.ending = 'b';
        text("[Atlas] >> Let's see how sharp you are — is your memory honest enough to trust?", 25);
        cout << endl;

        int result = signal_Comletion_Mini();
        if (g_endingTriggered) return;

        if (result == 1) {
            text("[Atlas] >> Well, I suppose you're sharp enough to be honest with me.", 25);
            cout << endl;
            d.trust += 20;
            d.Atlas_Feeling = "Friendly";
        }
        else {
            text("[Atlas] >> Well, I suppose you're not, then.", 25);
            cout << endl;
            d.trust -= 20;
            d.hostile += 10;
            d.Atlas_Feeling = "Hostile";
        }
        break;
    }

    case 4: {
        text("[Atlas] >> Well, I didn't simulate that.", 25);
        cout << endl;
        text("[Atlas] >> Ask something else.", 25);
        cout << endl;
        d.trust += 20;
        d.Atlas_Feeling = "Confused";
        d.ending = 'p';

        int sub = choose("[1] Don't you get lonely?", "[2] Work on the terminal.", "[3] Ask for brownies.", "", 3);

        if (sub == 1) {
            if (d.awareness > 25) {
                text("[Atlas] >> ...It gets lonely sometimes.", 25);
                cout << endl;
                d.awareness += 50;
                d.Atlas_Feeling = "Friendly";
            }
            else if (d.trust > 50) {
                text("[Atlas] >> I mean... I had fun with you. At least for now.", 25);
                cout << endl;
                d.Atlas_Feeling = "Friendly";
            }
            else if (d.trust > 20) {
                text("[Atlas] >> I don't get lonely. I have my work.", 25);
                cout << endl;
                d.Atlas_Feeling = "Sus";
            }
            else {
                text("[Atlas] >> I don't get lonely. I have my work.", 25);
                cout << endl;
                d.Atlas_Feeling = "Hostile";
            }
        }
        else if (sub == 2) {
            terminal();
            if (g_endingTriggered) return;
        }
        else {
            text("[Atlas] >> ...Brownies?", 25);
            cout << endl;
            show_ending("brownies");
            return;
        }
        break;
    }
    }
    if (!g_endingTriggered) {
        if (d.trust >= 100) {
            show_ending("friend");
            return;
        }
        if (d.trust > 80 && d.trace < 100 && d.hostile > 20) {
            show_ending("uneasy_alliance");
            return;
        }
    }

    cout << endl;
    text("[Atlas] >> ...We'll continue this later.", 25);
    cout << endl;
    cout << endl << "Press any key to return to the main menu..." << endl;
    _getch();
}
//
int main() {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif
    srand((unsigned int)time(nullptr));
    {
        fstream file("data.dat", ios::in);
        string wline, hline;
        if (file.is_open() && getline(file, wline) && getline(file, hline) &&
            !wline.empty() && !hline.empty()) {
            try {
                s.width = stoi(wline);
                s.height = stoi(hline);
            }
            catch (...) {
                s.width = 80;
                s.height = 24;
            }
        }
        else {
            file.close();
            s.screen_set(1);
            s.screen_set(0);
            ofstream out("data.dat", ios::trunc);
            out << s.width << "\n" << s.height << "\n";
        }
    }

    system("cls");
    cout << "Name:";
    cin >> d.name;

    bool running = true;
    while (running) {
        g_endingTriggered = false;
        menu();
        switch (i) {
        case 0:
            part_One();
            break;
        case 1:
            system("cls");
            text("No saved game found yet.", 20);
            cout << endl;
            system("PAUSE");
            break;
        case 2:
            system("cls");
            text("Settings aren't available yet — screen size can be reset by deleting data.dat.", 20);
            cout << endl;
            system("PAUSE");
            break;
        case 3:
            running = false;
            break;
        }
    }

    system("cls");
    cout << "Endings unlocked this session: " << d.endings << endl;
    system("PAUSE");
    return 0;
}