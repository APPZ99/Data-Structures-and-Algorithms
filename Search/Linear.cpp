#include <iostream>

using namespace std;

int main(){
	int mass[6] = {10,10,9,10,10,10};
	for(int i = 0; i < 6; i++){
		if(mass[i] == 9){
			printf("found! The NO. is %d", i+1);
		}
	}
	return 0;
}
