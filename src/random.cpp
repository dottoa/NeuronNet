#include "random.h"

RandomNumbers::RandomNumbers(unsigned long int s) : seed(s) {
    if (seed == 0) {
        std::random_device rd;
        seed = rd();
    }else{
		seed=s;
	}
    rng = std::mt19937(seed);
}

double RandomNumbers::uniform_double(double lower, double upper){
	
    std::uniform_real_distribution<> unif(lower, upper);
    return unif(rng);
}


void RandomNumbers::uniform_double(std::vector<double>& v, double lower, double upper){
	for (auto e:v) e = uniform_double(lower,upper);
}
		
double RandomNumbers::normal(double mean, double sd){
	 std::normal_distribution<double> norm(mean,sd);
	 return norm(rng);
}
    
void RandomNumbers::normal(std::vector<double>& v, double mean, double sd){
	for (auto e:v) e = normal(mean,sd);
	}

int RandomNumbers::poisson(double mean){
	std::poisson_distribution<> poiss(mean);
	return poiss(rng);
}

void RandomNumbers::poisson(std::vector<int>& v, double mean){
	for (auto e:v) e = poisson(mean);
}



