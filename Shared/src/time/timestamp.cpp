#include <iomanip>
#include <iostream>
#include <sys/timeb.h>
#include <time/timestamp.h>
char *timestamp() {
# define TIME_SIZE 40

    struct timeb tp;
    char *s = new char[TIME_SIZE];
    char *f = new char[TIME_SIZE];
    ftime(&tp);


    strftime(s, TIME_SIZE, "%Y-%m-%d %H:%M:%S", localtime(&tp.time));
    snprintf(f, TIME_SIZE, "%s.%d", s, tp.millitm);

    return f;
# undef TIME_SIZE
}