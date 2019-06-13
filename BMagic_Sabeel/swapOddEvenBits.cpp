#include<iostream>
using namespace std;
int main()
 {
	// all even bits need to be right shifted by 1
	// all odd bits need to be left shifted by 1

	// to get all even bits and with 0xAAAAAAAA
	// to get odd bits and with 0x55555555

	unsigned int t;
	cin >> t;
	while(t--) {
	    unsigned int n;
	    cin >> n;

	    // swap bits method
	    unsigned int even_bits = n & 0xAAAAAAAA;
	    unsigned int odd_bits = n & 0x55555555;

	    // right shift even, left shift odd
	    even_bits = even_bits >> 1;
	    odd_bits = odd_bits << 1;

	    // combine
	    cout << (even_bits | odd_bits) << endl;
	}
	return 0;
}
