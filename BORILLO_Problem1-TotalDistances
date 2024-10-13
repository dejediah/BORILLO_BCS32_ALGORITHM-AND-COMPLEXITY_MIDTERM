#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>

double pythagorean_total_dist(const std::vector<std::pair<double, double>>& N_distances) {
    double final_dist = 0;
    for (size_t i = 0; i < N_distances.size() - 1; i++) {
        // pythagorean theorem
        double dist = std::sqrt(std::pow(N_distances[i].first - N_distances[i + 1].first, 2) + std::pow(N_distances[i].second - N_distances[i + 1].second, 2));
        final_dist += dist;
    }
    return final_dist;
}

double summation(int N_length) {
    double sum = 0;
    if (N_length <= 0) {
        std::cout << "Number is invalid (0 or -)" << std::endl;
    } else {
        // summation formula
        sum = (N_length * (N_length + 1)) / 2.0;
    }
    return sum;
}

int main() {
    int N_length;
    std::cout << "Enter the total number of coordinates you will use: ";
    std::cin >> N_length;

    std::vector<std::pair<double, double>> N_distances;

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

    std::cout << "N_distances = ";
    for (const auto& point : N_distances) {
        std::cout << "(" << point.first << "," << point.second << ") ";
    }
    std::cout << std::endl;

    std::cout << "First point: (" << N_distances[0].first << "," << N_distances[0].second << ") " << std::endl;
    std::cout << "Final point: (" << N_distances.back().first << "," << N_distances.back().second << ")" << std::endl;
    std::cout << "Total Distance Travelled: " << pythagorean_total_dist(N_distances) << std::endl;

    std::cout << "Summation using summation formula: " << summation(N_length) << std::endl;

    return 0;
}
