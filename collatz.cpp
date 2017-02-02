#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

<<<<<<< HEAD
long long collatz(long long x){
    if(x==1)
        return 0;
    if(x%2==0)
        return collatz(x/2)+1;
    else
        return(collatz(x + (x>>1) + 1) + 2);
}

int main(){
	//Naive Solution
	/*int args;
=======
int main(){
	int args;
>>>>>>> c97fd4f9402ab4982fac8cb17f789ab17d8d62c8
	int num;
	int cycle_length;
	int check;
	int placeholder;
	int max_length;
	int ans;

	cin >> args;
	for(int _=0; _<args; ++_){
		cin >> num;
		check = num / 2 + 1;
		max_length = 0;
		ans = 0;

		while(check<=num){
			cycle_length = 0;
			placeholder = check;
			while(placeholder > 1){
				if(placeholder%2==0){
					placeholder = placeholder / 2;
					++cycle_length;
				}
				else{
					placeholder = placeholder + (placeholder >> 1) + 1;			//Synonymous with (3*placeholder +1)/2
					++++cycle_length;
				}
			}
			if(cycle_length >= max_length){
				max_length = cycle_length;
				ans = check;
			}
			++check;
		}
		cout << ans << endl;
<<<<<<< HEAD
	}*/

	//Alternate Naive Solution
    int args;
    long long num;
    long long start;
    long long max_length;
    int ans;
    long long cycle_length;
    
    cin >> args;
    for(int _=0;_<args;++_){
        cin >> num;
        start = num/2+1;
        max_length = 0;
        
        for(long long i=start; i<=num; ++i){
            cycle_length = collatz(i);
            if(max_length <= cycle_length){
                ans = i;
                max_length = cycle_length;
            }
        }
        cout << ans << endl;
    }
    
	return 0;
}

