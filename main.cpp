#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<float> bubbleSort(vector<float>& array){
	float tmp;
	int passCounter = 0;//counts how many times no swap is made
	while(passCounter < array.size()-1){//when no swaps are made over entire list, list is sorted
		for(int i = 0; i < array.size()-1; ++i){
			if(array[i]>array[i+1]){
				tmp = array[i+1];
				array[i+1] = array[i];
				array[i] = tmp;
				passCounter = 0;
			}
			else{
				passCounter++;
			}
		}
	}

	return array;
}

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str); // Turn the string into a stream.
	string tok;

	while(getline(ss, tok, delimiter)) {
		internal.push_back(tok);
	}
				  
	return internal;
}



int main(){
	string inputString;	
	cout << "Array to sort (separate by spaces): ";
	getline(cin, inputString);

	vector<string> stringInputArray = split(inputString, ' ');

	vector<float> inputArray; 
	for(int i = 0; i < stringInputArray.size(); i++){
		inputArray.push_back(stof(stringInputArray[i]));
	}
	
	vector<float> sorted = bubbleSort(inputArray);
	cout << endl << "Sorted Array:" << endl;	
	for(int i = 0; i < sorted.size(); i++){
		cout << sorted[i];
		if(i == sorted.size()-1){
			cout << endl;
		}else{
			cout << ", ";
		}
	}
	cout << endl;
	return 0;
}
