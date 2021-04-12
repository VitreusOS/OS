#include "Debug.hpp"

using namespace HAL;

void Debug::write(const char* str)
{
    for (auto i = str; *i != '\0'; i++) {
        write(*i);
    }
}

void Debug::write(char c)
{
    asm volatile ("outb %b0,%w1" : : "a"(c), "d"(0xE9));
}

void Debug::write(uint64_t i)
{
    auto convert = [](auto num)
    {
        static char numberCharacters[]= "0123456789";
        static char buffer[64];
        char *ptr;

        ptr = &buffer[49];
        *ptr = '\0';

        do {
            *--ptr = numberCharacters[num % 10];
            num /= 10;
        } while(num != 0);

        return ptr;
    };

    write(convert(i));
}

void Debug::write(int i)
{
    auto convert = [](auto num)
    {
        static char numberCharacters[]= "0123456789";
        static char buffer[64];
        char *ptr;

        ptr = &buffer[49];
        *ptr = '\0';

        do {
            *--ptr = numberCharacters[num % 10];
            num /= 10;
        } while(num != 0);

        return ptr;
    };

    if (i < 0) {
        write('-');
    }

    write(convert(i));
}

void Debug::write(bool b)
{
    write(b ? "true" : "false");
}

