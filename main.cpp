#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
void printqueue(queue<int>);
int averagequeue(queue<int> thequeue);
main(int argc, char *argv[])
{
	cout << "Input File "<<argv[1]<<endl;
	ifstream inFile;
	inFile.open(argv[1]);
	int ndays = atoi(argv[2]);
	queue<int> dayqueue;
	cout << "Days "<<ndays<<endl;
	
	vector<int> cases;
	int dayval;
	// Read all of the day values into a vector
	while(inFile >> dayval) {
		cases.push_back(dayval);
	}
	for(int i = 0; i < cases.size(); i++) {
		cout << "["<<i<<"]="<<cases[i]<<endl;
	}
	for(int i = 0; i < ndays; i++) {
		cout << "pushing "<<cases[i]<<endl;
		dayqueue.push(cases[i]);
	}
	// Add new elements and print the average
	printqueue(dayqueue);
	cout << "Average "<<averagequeue(dayqueue)<<endl;
	for(int i = ndays; i < cases.size(); i++) {
		dayqueue.pop();
		dayqueue.push(cases[i]);
		printqueue(dayqueue);
		cout << "Average "<<averagequeue(dayqueue)<<endl;
	}
}
void printqueue(queue<int> thequeue)
{
	queue<int> tmpqueue = thequeue;
	while(!tmpqueue.empty()) {
		int value = tmpqueue.front();
		tmpqueue.pop();
		cout << value<<",";
	}
	cout << endl;
}
int averagequeue(queue<int> thequeue)
{
	queue<int> tmpqueue = thequeue;
	int qsize = thequeue.size();
	int total = 0;
	while(!tmpqueue.empty()) {
		int value = tmpqueue.front();
		tmpqueue.pop();
		total += value;
	}
	return(total/qsize);
}
