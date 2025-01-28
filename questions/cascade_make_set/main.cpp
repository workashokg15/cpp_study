#include "../../common.hpp"
#include <functional>
#include <memory>
#include <set>

using namespace AshokProgramming;


int main(int argc, char *argv[])
{
    vector<unique_ptr<vector<string>>> out;
    auto makeseth = [&](auto in, auto n, auto input_size, auto&&makeseth){
        if(n == 0) cout << out[0]->at(0) << endl;
        if(n == input_size) return;
        string s;
        auto size = out.size();
        for(int i = 0; i < size; i++) {
            auto size1 = out[i]->size();
            for(int j = 0; j < size1; j++){
                s = out[i]->at(j) + to_string(in[n]);
                if(j == 0) {
                    auto e = {s,};
                    auto entry = make_unique<vector<string>>(move(e));
                    out.push_back(move(entry));
                } else {
                    out[i+1]->push_back(s);
                }
                cout << s << endl;
            }
        }
        makeseth(in, n+1, input_size, makeseth);
    };
    auto makeset = [&](auto in, auto n, auto input_size, auto&& makeset){
        vector<string> empty = {"[]",};
        auto empty_set = make_unique<vector<string>>(move(empty));
        out.push_back(move(empty_set));
        return makeseth(in, n, input_size, makeseth);
    };
    while(1) {
        string line;
        cout << "Enter q/Q to quit OR input a number for execution: ";
        getline(cin, line);
        if(line == "q" || line == "Q") break;
        int num = stoi(line);
        vector<int>input; 

        cout << "Entered values is " << num << endl;
        input = vectorize_integer(input, num);
        auto size = input.size();
        //print_vector(input);
        auto&& v = make_set(input);
        makeset(input, 0, size, makeset);
        out.clear();
        //cout << (*out[0])[0] << endl;
    }

    return 0;
}