#include <cpr/cpr.h> //cpr is a REST API for C++
#include <cstdlib>

void miner(int argc, char** argv) {
	// SETUP
	// retrieve latest block
	auto latest = cpr::Get(cpr::Url{"https://blockchain.info/latestblock"});
	print(latest);


	//set difficulty
	//set max nonce
	//retrieve block
	//compute merkle root from transactions once transactions are full

	//mining 
	// **assume nonce and merkle root already set**
	//loop nonce increments/randomizes
	//compute double sha256
	//check if result is a solution
}

unsigned long long int nonce = 0;
int counter;
for (counter = 0; counter < 50; ++counter) {
	srand(nonce);
	nonce = 4294967296 * ((double)rand() / RAND_MAX);
}
//notifying blockchain

