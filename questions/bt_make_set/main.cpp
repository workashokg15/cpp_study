#include "../../common.hpp"
#include <functional>
#include <memory>
#include <vector>


using namespace AshokProgramming;


int main(int argc, char *argv[])
{
    function<void(vector<int>, int, string, vector<string>&)> makeset = [&](vector<int> in, int n, string curr, vector<string>& ans){
        ans.push_back(curr);
        int size = in.size();
        for(int i = n; i < size; i++) {
            curr.push_back(in[i]+48);
            cout << "=>> n:" << n << " i:" << i << "curr: " << curr << endl;
            makeset(in, i+1, curr, ans);
            curr.pop_back();
            cout << "<<= n:" << n << " i:" << i << "curr: " << curr << endl;
        }
    };
    while(1) {
        string line;
        string str="";
        vector<string> ans;
        cout << "Enter q/Q to quit OR input a number for execution: ";
        getline(cin, line);
        if(line == "q" || line == "Q") break;
        int num = stoi(line);
        vector<int>input; 

        cout << "Entered values is " << num << endl;
        input = vectorize_integer(input, num);
        auto size = input.size();
        //print_vector(input);
        //auto&& v = make_set(input);
        makeset(input, 0, str, ans);
        print_almost_any(ans);
        //out.clear();
        //cout << (*out[0])[0] << endl;
    }

    return 0;
}