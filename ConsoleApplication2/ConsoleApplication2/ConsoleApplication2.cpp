#include <iostream>
#include <cmath>
#include <random>
#include <string>
#include <thread> // Для роботи з потоками
#include <chrono> // Для пауз (sleep)
#include <mutex>  // Для запобігання змішуванню тексту в консолі

using namespace std;

// М'ютекс потрібен, щоб потік 1 не перебивав вивід потоку 2 в консоль
mutex consoleMutex;

struct Point {
    double x, y;
};

class Building {
protected:
    string type;
    Point pos;
    Point target;
    double speed;
    bool isMoving;

public:
    Building(string t, double startX, double startY, double V,
        double minTargetX, double minTargetY, double rangeW, double rangeH)
        : type(t), speed(V) {

        pos = { startX, startY };

        if (startX >= minTargetX && startX <= minTargetX + rangeW &&
            startY >= minTargetY && startY <= minTargetY + rangeH) {
            isMoving = false;
            target = pos;
        }
        else {
            random_device rd;
            mt19937 gen(rd());
            uniform_real_distribution<> disX(minTargetX, minTargetX + rangeW);
            uniform_real_distribution<> disY(minTargetY, minTargetY + rangeH);

            target = { disX(gen), disY(gen) };
            isMoving = true;
        }
    }

    void update(double dt) {
        if (!isMoving) return;

        double dx = target.x - pos.x;
        double dy = target.y - pos.y;
        double distance = sqrt(dx * dx + dy * dy);

        if (distance <= speed * dt) {
            pos = target;
            isMoving = false;

            lock_guard<mutex> lock(consoleMutex);
            cout << "\n[EVENT] " << type << " arrived at destination.\n";
        }
        else {
            pos.x += (dx / distance) * speed * dt;
            pos.y += (dy / distance) * speed * dt;
        }
    }

    void printStatus() {
        lock_guard<mutex> lock(consoleMutex); // Блокуємо консоль для чистого виводу
        cout << type << " at (" << pos.x << ", " << pos.y << ") "
            << (isMoving ? "moving..." : "stopped.") << endl;
    }

    bool isMovingN() const { return isMoving; }

    void runSimulationLoop() {
        while (isMovingN()) {
            update(1.0);
            printStatus();
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }
};

class CapitalB : public Building {
public:
    CapitalB(double x, double y, double w, double h, double V)
        : Building("Capital Building", x, y, V, 0, 0, w / 2, h / 2) {
    }
};

class WoodenB : public Building {
public:
    WoodenB(double x, double y, double w, double h, double V)
        : Building("Wooden Building", x, y, V, w / 2, h / 2, w / 2, h / 2) {
    }
};

int main() {
    double w = 100.0, h = 100.0, v = 5.0;

    CapitalB cb(80, 80, w, h, v);
    WoodenB wb(10, 10, w, h, v);

    cout << "Multithreaded simulation started:\n";
    cout << "----------------------------------\n";

    thread t1(&Building::runSimulationLoop, &cb);
    thread t2(&Building::runSimulationLoop, &wb);

    t1.join();
    t2.join();

    cout << "----------------------------------\n";
    cout << "Simulation finished. All buildings arrived.\n";

    return 0;
}