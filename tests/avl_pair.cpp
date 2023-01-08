#include <iostream>

// CPP program to illustrate
// std :: lower_bound

// Driver code
int main()
{
	// Input vector
	std::vector<int> v{ 10, 20, 30, 30, 30, 40, 50 };

	// Print vector
	std::cout << "Vector contains :";
	for (unsigned int i = 0; i < v.size(); i++)
		std::cout << " " << v[i];
	std::cout << "\n";

	std::vector<int>::iterator low1, low2, low3;
	
	// std :: lower_bound
	low1 = std::lower_bound(v.begin(), v.end(), 30);
	low2 = std::lower_bound(v.begin(), v.end(), 35);
	low3 = std::lower_bound(v.begin(), v.end(), 55);

	// Printing the lower bounds
	std::cout
		<< "\nlower_bound for element 30 at position : "
		<< (low1 - v.begin());
	std::cout
		<< "\nlower_bound for element 35 at position : "
		<< (low2 - v.begin());
	std::cout
		<< "\nlower_bound for element 55 at position : "
		<< (low3 - v.begin());

	return 0;
}
