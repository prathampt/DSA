typedef struct {
    int kms;
    int meters;
} Distance;

void readDistance(Distance *d);
void displayDistance(Distance d);
Distance addDistances(Distance d1, Distance d2);
Distance subtractDistances(Distance d1, Distance d2);
