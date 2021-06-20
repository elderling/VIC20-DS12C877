#include <vic20.h>
#include <stdlib.h>
#include <peekpoke.h>
#include <conio.h>

// Change this to 0x9C00 if that's where the clock is
#define RTC_BASE 0x9800

int main() {
  char hour, minute, second;

  clrscr();

  while (1) {

    POKE(RTC_BASE, 0x04);
    hour = PEEK( RTC_BASE + 1 );
    POKE(RTC_BASE, 0x02);
    minute = PEEK( RTC_BASE + 1 );
    POKE(RTC_BASE, 0x00);
    second = PEEK( RTC_BASE + 1 );

    gotoxy(0,0);
    cprintf("%x,%x,%x", hour, minute, second);
  }

  return 0;
}
