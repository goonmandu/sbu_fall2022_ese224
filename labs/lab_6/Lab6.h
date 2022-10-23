#pragma once
#include <string>
#include <vector>
#include <iostream>

void print_vec(std::vector<double>);
double max(double, double);
void swap(double &, double &);

std::string longest_common_prefix(std::vector<std::string> &);
int non_adjacent_candies(std::vector<int> &);
std::vector<double> merge(std::vector<double> &, std::vector<double> &);
std::vector<double> mergesort(std::vector<double> &);
int partition(std::vector<double> &, int, int);
void quicksort(std::vector<double> &, int, int);