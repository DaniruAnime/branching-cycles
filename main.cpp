#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

    setlocale(LC_ALL,"rus");

    const double g = 9.81; // ускорение силы тяжести
    const double d = 19.1 / 100; // диаметр трубы в метрах
    const int n = 6; // количество скоростей

    double velocities[n] = {1, 2, 5, 10, 20, 50}; // массив скоростей
    double Fr_values[n], phi_values[n]; // массивы для хранения Fr (число фруда) и phi (ф)

    // Рассчитываем значения Fr и phi для каждой скорости
    for (int i = 0; i < n; ++i) {
        double v = velocities[i];
        Fr_values[i] = pow(v, 2) / (g * d);

        if (Fr_values[i] < 50) {
            phi_values[i] = 0.05 * pow(Fr_values[i], 0.2);
        } else {
            phi_values[i] = 0.35 * pow(Fr_values[i], 0.1);
        }
    }

    // Вывод результатов
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "v (м/с)\tFr\t\tϕ\n";

    for (int i = 0; i < n; ++i) {
        std::cout << velocities[i] << std::setw(14) << Fr_values[i] << std::setw(16) << phi_values[i] << "\n";
    }

    return 0;
}
