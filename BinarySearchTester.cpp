#include <iostream>
#include <algorithm> // used for sort function
#include <ctime> // used for clock and random seed
#include <vector> // used to dynamically create an array
#include <iomanip> // used for decimal precision

using namespace std;

int linearSearch(vector<int> v, int key);

int BinarySerach(vector<int> v, int key);


int main()
{
	int n;
	srand(time(0)); // used to reset Random Seed;
	vector<int> a; /* Vector is being used in place of an Array as my IDE(Visual Studio) has problems
	                with Static Array declaration of really big numbers. The vector is only for the dynamic
				   allocation, and is treated as an array otherwise.  */
				   
	clock_t c1; // Timer object
	

	cout << "please enter a size" << endl;
	cin >> n;
	for (int i = 0; i <n; i++)
	{
		a.push_back( rand() % (1000 - (-1000) + 1) - 1000); // Adding random numbers between -1000 to 1000
		
	}
	sort(a.begin(),a.end()); // C++ built in sort, 

	c1 = clock(); // Start Clock;
	for (int i = 0; i < 100; i++)
	{
		
		int key = rand() % (1000 - (-1000) + 1) - 1000;
		linearSearch(a, key);
	}
	c1 = clock() - c1; // End Clock

	cout<< "Average time of Linear Search " << 1000*((c1 / (double)CLOCKS_PER_SEC) / 100) << setprecision(9) << " ms" << endl; // Get average time of Linear Search in ms

	c1 = clock(); 
	for (int i = 0; i < 100; i++)
	{

		int key = rand() % (1000 - (-1000) + 1) - 1000;
		BinarySerach(a, key);
	}
	c1 = clock() - c1;
	cout << "Average time of Binary Search " << 1000*((c1 / (double)CLOCKS_PER_SEC) / 100) << setprecision(9) << " ms" << endl; // Get average time of Binary Search in ms


	a.clear(); // empty my vector
	cout << "please enter a size" << endl;
	cin >> n;
	for (int i = 0; i <n; i++)
	{
		a.push_back(rand() % (1000 - (-1000) + 1) - 1000);  // Refill array with random integers, -1000 to 1000

	}
	sort(a.begin(), a.end()); // sort
	int key = 5000; 

	c1 = clock();
	linearSearch(a, key);
	c1 = clock() - c1;
	cout << "Worse case time of Linear Search " << 1000*((c1 / (double)CLOCKS_PER_SEC)) << setprecision(9) << " ms" << endl; // Worse Case Time of Linear Search in ms

	c1 = clock();
	BinarySerach(a, key);
	c1 = clock() - c1;
	cout << "Worse case time of Binary Search " << 1000*((c1 / (double)CLOCKS_PER_SEC)) << setprecision(9) << " ms" << endl; // Worse Case Time of Binary Search in ms

	//Part b #5
	double executableTime = pow(10.0, -6) / log2(100000); // xlog(100000) = 1 ms        from above binary search worse case, solve for x
	cout << "Time it takes to execute one line of code on this machine " << executableTime << endl; 

	cout << "Estimation of worse case time of linear search for input of 10^7 = " << executableTime * pow(10.0, 7.0) << setprecision(9) << " seconds" << endl;

	cout << "Estimation of worse case time of binary search for input of 10^7 = " << executableTime * log2(pow(10.0, 7.0)) << setprecision(9) << " seconds" << endl;

	system("pause");
	return 0;
}

int linearSearch(vector<int> v, int key)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == key) { return 1; } //if we match return true
	}
	return -1; // return false
	
}

int BinarySerach(vector<int> a, int key)
{
	int right = a.size()-1; // Starting upper bound, last index of array
	int left = 0; // Starting lower bound, first index of array
	int mid = (a.size() - 1) / 2;

	while (left <= right) 
	{
		
		mid = (left + right) / 2; // average between two numbers = new midpoint
		

		if (a[mid] == key) { return 1; } // if we mind return true

		else if (a[mid] < key)
		{
			left = mid + 1; // set new lower bound, partioning the array into the upperhalf
		}
		else

			right = mid - 1; // Set new upperbound, partioning the array into the lowerhalf
		
	}
	
	return -1; // if we dont find, return false
}