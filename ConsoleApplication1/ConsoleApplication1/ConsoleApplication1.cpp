#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cmath>
using namespace std; 

class ErrorBase {
public:
    virtual void Message() = 0;
    virtual double setFun() = 0;
    double Qnr(double x, double y) {
        if (y == 0) return 1;
        if (x > y && y != 0) return x * x * (10 * y * y - x / 2);
        if (x <= y && 3 * x > y && y != 0) return x*x*x*x * y;
        if (x <= y && 3 * x <= y && y != 0) return y*y*y*y * x;
    }
    double Qnk1(double x, double y) {
        return 12 * Qnr(2.5 * x, y) - 3 * Qnr(x, 1.5 * y);
    }
    double Rnk(double x, double y, double z) {
		return 1.15 * x * Qnk1(x, y) + 0.95 * y * Qnk1(y, x) + 0.9 * z * Qnk1(z, x);
    }
};

class Error2Al4 : public ErrorBase {
public:
        void Message() override {
        cout << "Error 4: |x| <= 5 in Ux function!" << endl;
    }
		double setFun() override { return 0; }
        double Gnk(double x, double y, double z) {
            if (x * x + y * y + z * z >= 0.001) {
                return x * Wnk2(x / sqrt(x * x + y * y + z * z), y / sqrt(x * x + y * y + z * z)) +
                       y * Wnk2(y / sqrt(x * x + y * y + z * z), x / sqrt(x * x + y * y + z * z)) +
                       z * Wnk2(z / sqrt(x * x + y * y + z * z), x / sqrt(x * x + y * y + z * z));
            }
            else return 0;
        }
        double Wnk2(double x, double y) {
            return 10 * Wnr2(x, y) - 3 * Wnr2(x, y);
		}
        double Wnr2(double x, double y) {
            if (x > y) return 0.9 * T2x(x) - U2x(x) * U2x(y);
            else return T2x(x) * T2x(y) - 0.9 * U2x(x);


        }
        double U2x(double x) {
            double xx, y;

            map<double, double> ux;

            ifstream file("dat1.dat");

            if (!file.is_open()) return 0;

            while (file >> xx >> y) {
                ux[xx] = y;
            }

            file.close();

            if (ux.empty()) return 0;

            if (x < ux.begin()->first || x > ux.rbegin()->first) return 0;

            if (!ux.count(x)) {
                auto xi1 = ux.upper_bound(x); // Це x_{i+1}
                auto xi = prev(xi1);     // Це x_i

                double x_i = xi->first;
                double x_i1 = xi1->first;
                double u_i = xi->second;
                double u_i1 = xi1->second;

                return u_i1 + (u_i1 - u_i) * (x - x_i1) / (x_i1 - x_i);

            }
            return ux[x];
        }

        double T2x(double x) {
            double xx, y;

            map<double, double> tx;

            ifstream file("dat2.dat");

            if (!file.is_open()) return 0;

            while (file >> xx >> y) {
                tx[xx] = y;  
            }

            file.close();

            if (tx.empty()) return 0;
    
            if (x < tx.begin()->first || x > tx.rbegin()->first) return 0;

            if (!tx.count(x)) {
                auto xi1 = tx.upper_bound(x); // Це x_{i+1}
                auto xi = prev(xi1);     // Це x_i

                double x_i = xi->first;
                double x_i1 = xi1->first;
                double t_i = xi->second;
                double t_i1 = xi1->second;

                return t_i1 + (t_i1 - t_i) * (x - x_i1) / (x_i1 - x_i);

            }
            return tx[x];
        }


};

class ErrorNoFile : public ErrorBase {
public:
    void Message() override {
        cout << "Error: Could not open file dat1.dat!" << endl;
    }
	double setFun() override { return 0; }
    double U1x(double x) {
        return atan(asin(sin(3 * x)));
    }
    double T1x(double x) {
        return atan(acos(sin(2 * x)));
    }
    double Wnr1(double x, double y) {
        if (x > y) return T1x(x) - 0.9 * U1x(x) * U1x(y);
		else return 0.9 * T1x(x) * T1x(y) - U1x(x);
    }
    double Wnk(double x, double y) {
		return 10 * Wnr1(2.5 * x, y) - 4 * Wnr1(x, 2.5 * y);
    }
};

class ErrorRnk1 : public ErrorBase {
    double x, y, z;
public:
    ErrorRnk1(double dx, double dy, double dz) : x(dx), y(dy), z(dz) {}
    void Message() override {
        cout << "Error 5.1: 10*y^2 - x < 0. Recalculating Rnk with z = 1.25" << endl;
    }
    double setFun() override { return 1.25; } // Нове значення z
};

class ErrorRnk2 : public ErrorBase {
	double x, y, z;
public:
    ErrorRnk2(double dx, double dy, double dz) : x(dx), y(dy), z(dz) {}
    void Message() override {
        cout << "Error 5.2: y^2 - 2x < 0. Recalculating Rnk with z = 1.5" << endl;
    }
	double setFun() override { return 1.5; } // Нове значення z

};

class ErrorQnk : public ErrorBase {
public:
    void Message() override {
        cout << "Error 5.3: 10*x^2 - y < 0. Setting y = 0" << endl;
    }
    double setFun() override { return 0; } // Нове значення y
};

class GeneralError {
public:
    void Message() { cout << "Виключна ситуація в інших випадках (Qnr)" << endl; }
};

double fun(double x, double y, double z);
double Rnk(double x, double y, double z);
double Qnk(double x, double y);
double Qnr(double x, double y);

double fun(double x, double y, double z) {
	return x * Rnk(x, y, z) + Rnk(y, z, x) * Rnk(z, x, y);
}

double Rnk(double x, double y, double z) {
    try {
        return x * Qnk(x, y) + y * Qnk(y, x) + z * Qnk(z, x);
    }
    catch (ErrorRnk1& e) {
        e.Message();
        double n_z = e.setFun();
        return 1.15 * x * e.Qnk1(x, y) + 0.95 * y * e.Qnk1(y, x) + 0.9 * n_z * e.Qnk1(n_z, x);
    }
    catch (ErrorRnk2& e) {
        e.Message();
        double n_z = e.setFun();
        return 1.15 * x * e.Qnk1(x, y) + 0.95 * y * e.Qnk1(y, x) + 0.9 * n_z * e.Qnk1(n_z, x);
    }
}

double Qnk(double x, double y) {
    try {
		return 10.5 * Qnr(2 * x, y) - 3.75 * Qnr(x, 2 * y);
    }
    catch (ErrorQnk& e) {
        e.Message();
        int n_y = e.setFun();
        return 10.5 * Qnr(2 * x, n_y) - 3.75 * Qnr(x, 2 * n_y);
    }
}

double Qnr(double x, double y) {
    if (y == 0) { // 1
        return 1;
    }

    if (10 * y * y - x < 0) throw ErrorRnk1(x, y, 0);
    if (y * y - 2 * x < 0) throw ErrorRnk2(x, y, 0);
    if (10 * x * x - y < 0) throw ErrorQnk();

    if (x > y && 10 * (y*y*y*y) - x  >= 0 && y != 0) { 
        return x * x * sqrt(10 * (y*y*y*y) - x);
    }
    if (x <= y && 3*x > y && 10 * (x*x*x*x) - y >= 0 && y != 0) { 
        return (x*x*x) * log(10 * (x*x*x*x) - y);
    }
    if (x <= y && 3 * x <= y && (y*y*y*y) - 2 * x >= 0 && y != 0) { 
        return (y*y) * sqrt((y*y*y*y) - 2 * x);
    }
    
    throw GeneralError();
}

double gold(double x, double y, double z);
double Gnk(double x, double y, double z);
double Wnk(double x, double y);
double Wnr(double x, double y);
double Ux(double x);
double Tx(double x);

double gold(double x, double y, double z) {
	return x * Gnk(x, y, z) + Gnk(y, z, x) * Gnk(z, x, y);
}

double Gnk(double x, double y, double z) {
    try {
        return x * Wnk(x, y) + y * Wnk(y, z) + z * Wnk(z, x);
    }
    catch (Error2Al4& e) {
        e.Message();
		return e.Gnk(x, y, z);
    }
}

double Wnk(double x, double y) {
    try {
        return  10.5 * Wnr(2 * x, y) - 3.75 * Wnr(x, 2 * y);
    }
    catch (ErrorNoFile& e) {
        e.Message();
        return e.Wnk(x, y);
    }
}

double Wnr(double x, double y) {
    if (x > y) return Tx(x) - Ux(x) * Ux(y);
    else return Tx(x) * Tx(y) - Ux(x);
}

double Ux(double x) {
    double xx, y;

    if (abs(x) <= 5) throw Error2Al4();

    map<double, double> ux;

    ifstream file("dat1.dat");

	if (!file.is_open()) throw ErrorNoFile();

     
    while (file >> xx >> y) {
            ux[xx] = y;
        }

    file.close();

    if (ux.empty()) return 0;

    if (x < ux.begin()->first || x > ux.rbegin()->first) return 0;

    if (!ux.count(x)) {
        auto xi1 = ux.upper_bound(x); // Це x_{i+1}
        auto xi = prev(xi1);     // Це x_i

        double x_i = xi->first;
        double x_i1 = xi1->first;
        double u_i = xi->second;
        double u_i1 = xi1->second;

        return u_i1 + (u_i1 - u_i) * (x - x_i1) / (x_i1 - x_i);

    }
    return ux[x];
}

double Tx(double x) {
    double xx, y;
    map<double, double> tx;

    if (abs(x) <= 10) throw Error2Al4();

    ifstream file("dat2.dat");

    if (!file.is_open()) throw ErrorNoFile();


    while (file >> xx >> y) {
        tx[xx] = y;
    }

	file.close();

    if (tx.empty()) return 0;

    if (x < tx.begin()->first || x > tx.rbegin()->first) return 0;

    if (!tx.count(x)) {
        auto xi1 = tx.upper_bound(x); // Це x_{i+1}
        auto xi = prev(xi1);     // Це x_i

        double x_i = xi->first;
        double x_i1 = xi1->first;
        double t_i = xi->second;
        double t_i1 = xi1->second;

        return t_i1 + (t_i1 - t_i) * (x - x_i1) / (x_i1 - x_i);

    }

    return tx[x];
}

double func(double u, double v, string r);
double Tfun(double u, double v, string r);
double txt(string x);

double func(double u, double v, string r) {
    if (abs(u) <= 0.5) return Tfun(0, v, r);

    if (abs(u) > 0.5 && u <= v) return Tfun(u, v, r);

	if (abs(u) > 0.5 && u > v) return Tfun(u, 0, r) - Tfun(0, v, "set");

    throw GeneralError();
}

double Tfun(double u, double v, string r) {
	return u*u + v*v - txt(r) * (u + v) + txt(r)*txt(r);

}

double txt(string x) {
	bool found = false;
    double  r = 0;
    string xx;
    double y;

    map<string, double> txt;

    ifstream file("dat3.dat");

    if (!file.is_open()) {
        cout << "Error 14.1: the file does not open, or is missing " << endl; return r;
    }

    while (file >> xx) {
        if (xx == x) {
            found = true;
            if (file >> y) r = y; // 14.4
            else { cout << "Error 14.5: numeric value missing " << endl; r = 1; }           // 14.5

            break;
        }
        
        file >> y;
    }

    if (!found) {
        cout << "Error 14.3: word missing " << endl;
        r = 0;
    }

	file.close();

    return r;
	    
}

int main() {

    double x1, y1, z1, u, v, t, rez;
	string r1;
    cout << "Input x1, y1, z1:\n";
	cin >> x1 >> y1 >> z1;
	cout << "Input text:\n";
    cin >> r1;

    
    try {
        u = fun(x1, y1, z1);
		v = gold(x1, y1, z1);
        t = Tfun(u, v, r1);
        rez = func(u, v, r1);

		cout << "Result: " << rez << endl;

    }
    catch (GeneralError& e) {
		e.Message();    
    }
    catch (...) {
		cout << "An unexpected error occurred." << endl;
    }

    return 0;
}
