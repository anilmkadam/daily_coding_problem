#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Logger {
    private :
    vector<string> logs;

    ll getSize() {
        return logs.size();
    }

    public:
    void record(string logMsg) {
        logs.push_back(logMsg);
    }

    string getLast(ll i) {
        ll logsSize = getSize(); 

        ll logRecordNum = logsSize - i;
        if(logRecordNum <= 0 || logRecordNum >= logsSize)
            return "No logs found\n";
        return logs[logRecordNum];
    }
};

int main() {
    Logger logging;
    logging.record("qwertyui1");
    logging.record("qwertyui2");
    logging.record("qwertyui3");
    logging.record("qwertyui4");
    logging.record("qwertyui5");
    logging.record("qwertyui6");
    logging.record("qwertyui7");
    logging.record("qwertyui8");
    logging.record("qwertyui9");
    logging.record("qwertyui10");
    logging.record("qwertyui11");
    logging.record("qwertyui12");
    logging.record("qwertyui13");
    logging.record("qwertyui14");
    logging.record("qwertyui15");
    
    cout << logging.getLast(15) << endl;
}
