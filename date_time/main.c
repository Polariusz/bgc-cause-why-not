#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void declare_and_print(void)
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
    struct tm my_datetime = { // written with utc, pls use timegm instead of mktime.
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

void printing_time(void)
{
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    struct tm *utc = gmtime(&now);

    printf("UTC        : %s", asctime(utc)); // This prints utc time
    printf("Local Time : %s", ctime(&now)); // with this, the acstime(utc) later prints localtime, without the asctime(local) below prints utc. Am I... missing something?
    printf("Local Time : %s", asctime(local));
    printf("UTC-n't    : %s", asctime(utc)); // this prints local time
    printf("UTC        : %s", asctime(gmtime(&now))); // this prints utc time
}

void having_control(void)
{
    char s[128];

    time_t now = time(NULL);

    // %c: print date as per current locale
    strftime(s, sizeof(s), "%c", localtime(&now));
    puts(s);

    // %A: full weekday name
    // %B: full month name
    // %d: day of the month
    strftime(s, sizeof(s), "%A, %B %d", localtime(&now));
    puts(s);

    // %I: hour (12 hour clock)
    // %M: minute
    // %S: second
    // %p: AM or PM
    strftime(s, sizeof s, "It's %I:%M:%S %p", localtime(&now));
    puts(s);

    // %F: ISO 8601 yyyy-mm-dd
    // %T: ISO 8601 hh:mm:ss
    // %z: ISO 8601 time zone offset
    strftime(s, sizeof s, "ISO 8601: %FT%T%z", localtime(&now));
    puts(s);

    // %Z: timezone name or abbreviation
    // %W: The week number of the current year as a decimal number,
    //     range 00 to 53, starting with the first Monday as the
    //     first day of week 01. (Calculated from tm_yday and tm_wday.)
    strftime(s, sizeof s, "We are in the %Z timezone and it is the %W week", localtime(&now));
    puts(s);

    return;
}

void week_number(void)
{
    char s[128];

    struct tm my_datetime = {
        .tm_year=125,         // years since 1900
        .tm_mon=0,            // months since January [0, 11]
        .tm_mday=9,          // day of the month [1, 31]
        .tm_hour=12,           // hours since midnight [0, 23]
        .tm_min=0,           // minutes after the hour [0, 59]
        .tm_sec=0,           // seconds after the minute [0, 59]
        .tm_isdst=-1,         // Daylight saving time flag
    };


    printf("%s", asctime(&my_datetime));
    time_t epoch = mktime(&my_datetime);

    // The week number begins from 0.
    strftime(s, sizeof s, "We are in the %Z timezone and it is the %W week", localtime(&epoch));
    puts(s);

    return;
}

void precise(void)
{
    struct timespec prec;
    timespec_get(&prec, TIME_UTC);
    time_t now = time(NULL);

    printf("by time()  : %ld\n", now);
    printf("by timespec: %ld, %ld\n", prec.tv_sec, prec.tv_nsec);

    return;
}

struct TimeDiff {
    long int max;
    long int min;
    long int avg;
};

int precise_2(void)
{
    struct TimeDiff *time_diff = malloc(sizeof(struct TimeDiff));
    if(time_diff == NULL) {
	printf("Download more RAM.\n");
	return 69;
    }
    time_diff->max = -1;
    time_diff->min = -1;
    time_diff->avg = -1;

    int ready = 0;
    int div = 0;
    struct timespec prev;
    for(int i = 0; i < 1000; i++) {
	struct timespec next;
	timespec_get(&next, TIME_UTC);

	if(ready && next.tv_sec == prev.tv_sec) {
	    if(time_diff->max == -1) {
		time_diff->max = next.tv_nsec - prev.tv_nsec;
	    } else if (time_diff->max < next.tv_nsec - prev.tv_nsec) {
		time_diff->max = next.tv_nsec - prev.tv_nsec;
	    }
	    if(time_diff->min == -1) {
		time_diff->min = next.tv_nsec - prev.tv_nsec;
	    } else if (time_diff->min > next.tv_nsec - prev.tv_nsec) {
		time_diff->min = next.tv_nsec - prev.tv_nsec;
	    }
	    if(time_diff->avg == -1) {
		time_diff->avg = next.tv_nsec - prev.tv_nsec;
		div++;
	    } else {
		time_diff->avg += next.tv_nsec - prev.tv_nsec;
		div++;
	    }
	}

	prev = next;
	ready = 1;
    }
    time_diff->avg /= div;
    printf("max: %ld\n", time_diff->max);
    printf("min: %ld\n", time_diff->min);
    printf("avg: %ld\n", time_diff->avg);

    return 0;
}

int main(void)
{
    precise_2();

    printf("\nJust Monika.\n");
    return 0;
}
