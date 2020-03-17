#include <iostream>
#include <bits/stdc++.h>
#include <thread>
using namespace std;

class Scheduler {
    public:
    void operator()(unsigned int params) {
        using namespace std::this_thread;
        using namespace std::chrono;
        sleep_for(milliseconds(params));
        cout << "Executed" << endl;
    }
};

int main() {
    cout << "Starting Job" << endl;
    std::thread job(Scheduler(), 3000);
    job.join();
    cout << "Executed Main Job." << endl;
    return 0;
}