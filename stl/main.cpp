#include "vector_st.hpp"


#include <cmath>
#include <cstdio>
#include <algorithm>
#include <set>
#include <iostream>
#include <iomanip> 
using namespace std;



int get_query() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		/* Enter your code here */
        long long a = A;
        char arr[16] = {0};
        char prarr[16] = {0};
        printf("0x%x\n",a);
        //find number of decimals
        sprintf(arr, "%+.02f", B);
        int len = 1;
        while(arr[++len]);
        int prep_underscores = 15 - len;
        int i = 0;
        for (i = 0; i < prep_underscores; i++)
            prarr[i] = '_';
                
        printf("%s", prarr);
        printf("%s\n", arr);
        printf("%1.9E\n",C);
        
	}
	return 0;

}


int main(int ac, char** av)
{
    get_query();
    stl_study::test_vector();
}


