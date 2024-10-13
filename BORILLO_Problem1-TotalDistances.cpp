/* 
Borillo, Raphael Jedidiah R. | BCS32 | 202230704
Problem 1:
To improve your delivery route calculations, you need to compute the total distance between multiple delivery points efficiently. 
The distance between two points  (𝑥1,𝑦1) (x1​,y1​) and  (𝑥2,𝑦2) (x2​,y2​) is calculated using the formula:

√𝑑=(𝑥2−𝑥1)^2+(𝑦2−𝑦1)^2

Given N delivery points in 2D space, write a program that computes the total distance traveled for a given sequence of points. 
Additionally, calculate the sum of the first N natural numbers using summation formulas.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>


// setting function to determine total distance using pythagorean theorem
double pythagorean_total_dist(const std::vector<std::pair<double, double>>& N_distances) {
    double final_dist = 0;
    // iterates through each point
    for (size_t i = 0; i < N_distances.size() - 1; i++) {
        // pythagorean theorem
        double dist = std::sqrt(std::pow(N_distances[i].first - N_distances[i + 1].first, 2) + std::pow(N_distances[i].second - N_distances[i + 1].second, 2));
        // tallies current distance
        final_dist += dist;
    }
    return final_dist;
}
// setting function to determine the summation of the first N natural numbers
double summation(int N_length) {
    double sum = 0;

    // failsafe for N = 0 or negtaive numbers
    if (N_length <= 0) {
        std::cout << "Number is invalid (0 or negative)" << std::endl;
    } else {
        // summation formula
        sum = (N_length * (N_length + 1)) / 2.0;
    }
    return sum;
}

// main runtime
int main() {

    // criteria 1: Input N (total number of points)
    int N_length;
    std::cout << "Enter the total number of coordinates you will use: ";
    std::cin >> N_length;

    std::vector<std::pair<double, double>> N_distances;
    
    // criteria 2: Input list of N coordinates representing the delivery points.
    for (int i = 0; i < N_length; i++) {
        std::string point;
        std::cout << "Enter coordinates for point " << i + 1 << " (format: (x,y)): ";
        std::getline(std::cin >> std::ws, point);

        std::stringstream ss(point);
        char c;
        double x, y;
        if (ss >> c >> x >> c >> y >> c && c == ')') {
            N_distances.emplace_back(x, y);
        } else {
            std::cout << "Invalid format. Please enter a tuple of the form (x,y)." << std::endl;
            i--;
        }
    }

    // outputs list of coordinates
    std::cout << "N_distances = ";
    for (const auto& point : N_distances) {
        std::cout << "(" << point.first << "," << point.second << ") ";
    }
    std::cout << std::endl;

    // outputs first and final points, then the total distance traveled
    std::cout << "First point: (" << N_distances[0].first << "," << N_distances[0].second << ") " << std::endl;
    std::cout << "Final point: (" << N_distances.back().first << "," << N_distances.back().second << ")" << std::endl;
    std::cout << "Total Distance Traveled: " << pythagorean_total_dist(N_distances) << std::endl;

    // outputs summation result for N
    std::cout << "Summation using summation formula: " << summation(N_length) << std::endl;

    return 0;
}
