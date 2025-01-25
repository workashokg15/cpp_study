#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>
//#include <chrono>
using namespace std;

string year_month_day_now()
{
    ostringstream oss;
    //const std::chrono::time_point now{std::chrono::system_clock::now()};
    //const std::chrono::year_month_day ymd{std::chrono::floor<std::chrono::days>(now)};
    //oss << ymd.year() << "_" << ymd.month() << "_" << ymd.day();
    return oss.str();
}

struct Journal {
    string title;
    vector<string> entries;
    uint64_t count;

    explicit Journal(const string& title) : title(title) {count = 1;}

    void add_entry(const string& entry) {
        ostringstream oss;
        oss << "entry no " << count << ": " << entry;
        count += 1;
        entries.push_back(oss.str());
    }
};

struct PersistanceManager {
    static void save(const Journal &j,const string& filename) {
        ofstream ofs(filename); 
        ofs << j.title << endl;
        for (auto &e : j.entries) {
            ofs << e << endl;
        }    
    }
};

int main()
{
    Journal j("journal1");
    PersistanceManager pm;
    j.add_entry("i am doing this");
    j.add_entry("like a gentleman");
    j.add_entry("never minding the wind");

    //string filename = "journal_" + year_month_day_now();
    string filename = "journal.txt";
    pm.save(j, filename);
    return 0;
}