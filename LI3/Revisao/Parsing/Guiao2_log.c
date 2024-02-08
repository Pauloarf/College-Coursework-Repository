#include <stdio.h>
#include <time.h>

int main(int argc, char **argv)
{
    FILE *fp = fopen("log.log", "a");
    time_t t = time(NULL);
    struct tm timeInfo = *localtime(&t);

    fputs("The time is: \n", fp);
    fprintf(fp, "[%d-%02d-%02d %02d:%02d:%02d] - %s\n",
            timeInfo.tm_year + 1900, timeInfo.tm_mon + 1, timeInfo.tm_mday,
            timeInfo.tm_hour, timeInfo.tm_min, timeInfo.tm_sec, argv[1]);

    fclose(fp);
    return 0;
}