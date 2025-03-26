#include <stdio.h>
#include <time.h>

void declare_nd_print(void)
{
    time_t now;       // declate time_t

    now = time(NULL); // Both get the time now.
    time(&now);       // Both get the time now.

    printf("%s\n", ctime(&now));
    return;
}

void gm_is_utc(void)
{
    time_t now = time(NULL);

    //struct tm *utc_now = gmtime(&now);       // returns a pointer
    printf("Local: %s", asctime(localtime(&now)));
    // printf("  UTC: %s", asctime(utc_now));  // Together these print the same, local, time. So beware.
    return;
}

void print_gm_and_local(void)
{
    time_t now_to_utc = time(NULL);
    printf("Local: %s", asctime(localtime(&now_to_utc)));
    printf("  UTC: %s", asctime(gmtime(&now_to_utc)));
    return;
}

void manually_tm_local(void)
{
    struct tm my_datetime = { // manually loaded struct tm should be in localtime. A bit weird.
        .tm_year=125,         // years since 1900
        .tm_mon=2,            // months since January [0, 11]
        .tm_mday=26,          // day of the month [1, 31]
        .tm_hour=7,           // hours since midnight [0, 23]
        .tm_min=56,           // minutes after the hour [0, 59]
        .tm_sec=10,           // seconds after the minute [0, 59]
        .tm_isdst=-1,         // Daylight saving time flag
    };

    time_t my_datetime_epoch = mktime(&my_datetime); // mktime converts localtime to time_t calendar time.

    printf("%s\n", ctime(&my_datetime_epoch));
    printf("Is DST: %d\n", my_datetime.tm_isdst);

    return;
}

void manually_tm_utc(void)
{
    struct tm my_datetime = { // manually loaded struct tm should be in localtime. A bit weird.
        .tm_year=125,         // years since 1900
        .tm_mon=2,            // months since January [0, 11]
        .tm_mday=26,          // day of the month [1, 31]
        .tm_hour=7,           // hours since midnight [0, 23]
        .tm_min=56,           // minutes after the hour [0, 59]
        .tm_sec=10,           // seconds after the minute [0, 59]
        .tm_isdst=-1,         // Daylight saving time flag
    };

    time_t my_datetime_epoch = timegm(&my_datetime); // timegm converts utc to time_t calendar time. It's a unix-like method

    printf("%s\n", ctime(&my_datetime_epoch));
    printf("Is DST: %d\n", my_datetime.tm_isdst);

    return;
}

int main(void)
{
    manually_tm_utc();

    printf("Just Monika.\n");
    return 0;
}
