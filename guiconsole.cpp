/* MIT License

   Copyright (c) [2016] [Jae Choi]

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
 */


#include <QObject>
#include <QStringList>
#include "guiconsole.h"

guiConsole::guiConsole()
{

    // Initialize curses: don't echo, character break, no cursor
    initscr();
    noecho();
    cbreak();
    curs_set(0);

    // Check color support of the teriminal then set colorscheme
    if (has_colors()) start_color();

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);

    // Begin drawing

    // Add toolbar + status bar
    attron(A_REVERSE | A_BOLD);
    mvaddstr(0, 0, "Status: Busy...");
    chgat(-1, A_REVERSE | A_BOLD, 0, 0);
    attroff(A_REVERSE);

    mvaddstr(LINES - 1, 0, "Press Ctrl+C to quit");
    attroff(A_BOLD);

    display_Impedance = newwin(10, COLS, 2, 0);
    display_Duration = newwin(5, COLS, 2 + 10, 0);
    display_Configs = newwin(6, COLS, 5 + 2 + 10, 0);

    box(display_Impedance, ACS_VLINE, ACS_HLINE);
    box(display_Duration, ACS_VLINE, ACS_HLINE);
    box(display_Configs, ACS_VLINE, ACS_HLINE);

    mvwprintw(display_Impedance, 0, 5, " IMPEDANCE ");
    mvwchgat(display_Impedance, 0, 6, 9, A_BOLD, 4, NULL);

    mvwprintw(display_Duration, 0, 5, " DURATION ");
    mvwchgat(display_Duration, 0, 6, 8, A_BOLD, 4, NULL);

    mvwprintw(display_Configs, 0, 5, " CONFIGURATION & ANALYSIS ");
    mvwchgat(display_Configs, 0, 6, 24, A_BOLD, 4, NULL);

    touchwin(display_Configs);
    touchwin(display_Duration);

}

guiConsole::~guiConsole()
{
    delwin(display_Impedance);
    delwin(display_Duration);
    delwin(display_Configs);

    endwin();
}

void guiConsole::update_display()
{
    wnoutrefresh(stdscr);
    wnoutrefresh(display_Impedance);
    wnoutrefresh(display_Duration);
    wnoutrefresh(display_Configs);
    doupdate();
}

void guiConsole::touch_all()
{
    touchwin(stdscr);
    touchwin(display_Impedance);
    touchwin(display_Duration);
    touchwin(display_Configs);
}

void guiConsole::update_Impedance(int imp_values[], int channels)
{
    for (int i = 0; i < channels; i++) {
        int w_y = i % 4 + 2;
        int w_x = (COLS - 40) * ((int) i / 4) + 2;

        mvwprintw(display_Impedance, w_y, w_x, "Channel %d: %5.1f kOhms", i + 1, (float)imp_values[i]/1000.0f);
        mvwchgat(display_Impedance, w_y, w_x, 9, A_UNDERLINE, 0, NULL);

        // Routine that colors in impedance values according to their severity
        if (imp_values[i] > 80 * 1000) mvwchgat(display_Impedance, w_y, w_x + 10, 12, A_BOLD, 3, NULL);
        else if (imp_values[i] > 50 * 1000) mvwchgat(display_Impedance, w_y, w_x + 10, 12, A_BOLD, 2, NULL);
        else if (imp_values[i] >= 5 * 1000) mvwchgat(display_Impedance, w_y, w_x + 10, 12, A_BOLD, 1, NULL);
        else if (imp_values[i] < 5 * 1000) mvwchgat(display_Impedance, w_y, w_x + 10, 12, A_BOLD, 3, NULL);
    }
}

void guiConsole::update_Time(QString current_time)
{
    mvwprintw(display_Duration, 2, 2, current_time.toLatin1().data());
    //mvwprintw(display_Duration, 2, 2 + 27, current_time.toLatin1().data());
    //mvwchgat(display_Duration, 2, 2, 19, A_UNDERLINE, 0, NULL);
}

void guiConsole::update_Config(QString string_Config)
{

    QStringList temp = string_Config.split("\n");
    for (int i = 0; i < temp.size(); i++) mvwprintw(display_Configs, i + 2, 2, temp[i].toLatin1().data());

}

void guiConsole::update_Toolbar(QString string_Status)
{
    attron(A_REVERSE | A_BOLD);
    mvaddstr(0, 0, string_Status.toLatin1().data());
    clrtoeol();
    chgat(-1, A_REVERSE | A_BOLD, 0, 0);
    attroff(A_REVERSE | A_BOLD);
}
