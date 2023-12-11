#include <stdio.h>

typedef struct {
    int hours;
    int minutes;
    int seconds;
} Time;
Time addDur(Time t1, Time t2) {
    Time result;
    result.seconds = t1.seconds + t2.seconds;
    result.minutes = t1.minutes + t2.minutes + result.seconds / 60;
    result.hours = t1.hours + t2.hours + result.minutes / 60;
    result.seconds %= 60;
    result.minutes %= 60;
    return result;
}

Time subDur(Time t1, Time t2) {
    Time result;
    int totalSeconds1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int totalSeconds2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
    int differenceSeconds = totalSeconds1 - totalSeconds2;
    result.hours = differenceSeconds / 3600;
    result.minutes = (differenceSeconds % 3600) / 60;
    result.seconds = differenceSeconds % 60;
    return result;
}

void printTime(Time t, const char* label) {
    printf("%s: %02d:%02d:%02d\n", label, t.hours, t.minutes, t.seconds);
}

int main() {
    Time duration1 = {10, 20, 50};
    Time duration2 = {5, 30, 40};

    Time sumResult = addDur(duration1, duration2);
    printTime(sumResult, "Sum");

    Time differenceResult = subDur(duration1, duration2);
    printTime(differenceResult, "Difference");

    return 0;
}
