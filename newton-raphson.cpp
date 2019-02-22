#include<iostream>
#include<cmath>

double request_tolerance() {
	double entry;
	std::cout << "Enter absolute error tolerance: ";
	std::cin >> entry;
	return entry;
}

double request_start() {
	double start;
	std::cout << "Enter starting parameter value: ";
	std::cin >> start;
	std::cout << std::endl;
	return start;
}

double f(double x) {
	double g = 2*10/x - 3*(1/(0.85 + x) + 1/(1.08 + x) + 1/(0.35 + x) + 1/(3.28 + x) + 1/(1.24 + x) + 1/(2.58 + x) + 1/(0.02 + x) + 1/(0.13 + x) + 1/(0.22 + x) + 1/(0.52 + x));
	return g;
}

double f_prime(double x) {
	double g = -2*10/pow(x, 2) + 3*(pow(0.85 + x, -2) + pow(1.08 + x, -2) + pow(0.35 + x, -2) + pow(3.28 + x, -2) + pow(1.24 + x, -2) + pow(2.58 + x, -2) + pow(0.02 + x, -2) + pow(0.13 + x, -2) + pow(0.22 + x, -2) + pow(0.52 + x, -2));
	return g;
}

double newton_raphson(double x) {
	return x - f(x)/f_prime(x);
}

double compute_error(double x_old, double x_new) {
	double diff = x_new - x_old;
	if (diff < 0)
		diff *= -1;
	return diff;
}

void display_step(double x_old, double x_new, int i, double error) {
	std::cout << "Step: " << i << "; new param: " << x_new << ";  old param: " << x_old << ";  error: " << error << std::endl;
	return;
}

int main() {
	double tol = request_tolerance();
	double x_new = request_start();
	int i = 1;
	double error, x_old;
	error = 1;
	while (error > tol) {
		x_old = x_new;
		x_new = newton_raphson(x_old);
		error = compute_error(x_old, x_new);
		display_step(x_old, x_new, i, error);
		i++;
	}
	return 0;
}
