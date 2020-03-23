#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
#define Interval 1000
using namespace std;

int main() {
    int i;
    double rand_x, rand_y, origin_dist, pi;
    int circle_pts = 0, square_pts = 0;

    srand(time(NULL));

    for(i = 0; i < (Interval * Interval); i++) {
        rand_x = (double)(rand() % (Interval + 1)) / Interval;
        rand_y = (double)(rand() % (Interval + 1)) / Interval;

        origin_dist = (rand_x * rand_x) + (rand_y * rand_y);

        if(origin_dist <= 1)
            circle_pts++;
        square_pts++;

        pi = (double)(4 *circle_pts ) / square_pts;

        cout << rand_x << " " << rand_y << " " << circle_pts << " " << square_pts << " - " << pi << endl << endl;

        if(i < 20)
            getchar();
    }
    
    cout << "\nFinal Estimation of Pi = " << setprecision(4) << pi << endl;
    return 0;
}