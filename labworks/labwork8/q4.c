#include <stdio.h>
typedef struct
{
    int hr;
    int min;
    int sec;
} Time;
int main()
{
    Time st, et;
    printf("Enter start time (hh:mm:ss): ");
    scanf("%d:%d:%d", &st.hr, &st.min, &st.sec);

    printf("Enter end time (hh:mm:ss): ");
    scanf("%d:%d:%d", &et.hr, &et.min, &et.sec);
    if (st.hr>et.hr)
    {
        return 1;
    }
    else if (st.hr== et.hr && st.min>et.min)
    {
        return 1;
    }
    else if (st.min== et.min && st.sec>et.sec)
    {
        return 1;
    }
    
    

    while (st.hr < et.hr ||(st.hr == et.hr && st.min < et.min) || (st.hr == et.hr && st.min == et.min && st.sec < et.sec))
    {
        printf("GOOD DAY\n");

        st.sec++;

        if (st.sec == 60)
        {
            st.sec = 0;
            st.min++;
        }
        if (st.min == 60)
        {
            st.min = 0;
            st.hr++;
        }
    }

    return 0;
}
