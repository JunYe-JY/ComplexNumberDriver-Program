#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
class ComplexNumber {
private:
    double real_part;
    double imaginary_part;
    int i_power;
    
public:
    ComplexNumber(): real_part(0.), imaginary_part(0.), i_power(1) {}
    ComplexNumber(double real_prt, double imaginary_prt): real_part(real_prt), imaginary_part(imaginary_prt), i_power(1) {}
    
    void set_real_part(double real_prt) { real_part = real_prt; }
    void set_imaginary_part(double imaginary_prt) { imaginary_part = imaginary_prt; }
    double get_real_part(void) const { return real_part; }
    double get_imaginary_part(void) const { return imaginary_part; }
    
    friend ostream& operator<<(ostream& os, ComplexNumber& obj) {
        if (obj.i_power % 2 == 0 && obj.i_power % 4 != 0) {
            obj.imaginary_part *= -1;
        }
        os << obj.real_part << "+" << obj.imaginary_part << "i";
        return os;
    }
    
    const ComplexNumber operator+(ComplexNumber& right_op) {
        ComplexNumber res;
        res.set_real_part(this ->get_real_part() + right_op.get_real_part());
        res.set_imaginary_part(this ->get_imaginary_part() + right_op.get_imaginary_part());
        return res;
    }
    
    const ComplexNumber operator-(ComplexNumber& right_op) {
        ComplexNumber res;
        res.set_real_part(this ->get_real_part() - right_op.get_real_part());
        res.set_imaginary_part(this ->get_imaginary_part() - right_op.get_imaginary_part());
        return res;
    }
    
    const ComplexNumber operator*(ComplexNumber& right_op) {
        ComplexNumber res;
        res.set_real_part((this ->real_part * right_op.get_real_part()) - (this ->imaginary_part * right_op.get_imaginary_part()));
        res.set_imaginary_part((this ->real_part * right_op.get_imaginary_part()) + (this ->imaginary_part * right_op.get_real_part()));
        res.i_power = this ->i_power + right_op.i_power;
        return res;
    }
    
    const ComplexNumber operator/(ComplexNumber& right_op) {
        ComplexNumber res;
        double real_prt, imaginary_prt;
        real_prt = (this ->real_part * right_op.get_real_part()) + (this ->imaginary_part * right_op.get_imaginary_part());
        imaginary_prt = (this ->imaginary_part * right_op.get_real_part()) - (this ->real_part * right_op.get_imaginary_part());
        double denominator = (pow(right_op.get_real_part(), 2.)) + (pow(right_op.get_imaginary_part(), 2.));
        res.set_real_part(real_prt / denominator);
        res.set_imaginary_part(imaginary_prt / denominator);
        res.i_power = this ->i_power - right_op.i_power;
        return res;
    }
    
    void operator!(void) {
        this ->imaginary_part *= -1;
        return;
    }
};


int main(){
    ComplexNumber c1; // Default constructor
    ComplexNumber c2(1, 2); // Value constructor
    
    // Test accessor functions
    cout << "Value of c1 (default constructor): \nc1.Re() == " << c1.get_real_part() << ", c1.Im() == " << c1.get_imaginary_part() << endl;
    cout << "Value of c2 (value constructor): \nc2.Re() == " << c2.get_real_part() << ", c2.Im() == " << c2.get_imaginary_part() << endl;
    
    // Test overloaded operators
    ComplexNumber c3(3.0, 4.0);
    ComplexNumber sum = c2 + c3;
    ComplexNumber diff = c2 - c3;
    ComplexNumber product = c2 * c3;
    ComplexNumber quotient = c2 / c3;
    
    cout << "\n";
    cout << "c2 + c3 (" << c2 << " + " << c3 << ") == " << sum << endl;
    cout << "c2 - c3 (" << c2 << " - " << c3 << ") == " << diff << endl;
    cout << "c2 * c3 (" << c2 << " * " << c3 << ") == " << product << endl;
    cout << "c2 / c3 (" << c2 << " / " << c3 << ") == " << quotient << endl;
    
    // Test complex conjugate
    !c2; // Apply the complex conjugate operation
    cout << "Conjugate of c2 (" << c2 << ") == " << c2 << endl;
    
    vector<ComplexNumber> a;
    vector<ComplexNumber> b;
    
    
    for (int n = 0; n < 10; n++) {
        ComplexNumber temp(n, 2*n);
        a.push_back(temp);
        b.push_back(temp);
    }
    
    cout << "\nVector output using indexed for-loop:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << a.at(i) << endl;
    }
    
    cout << "\nVector output using an iterator in for-loop:" << endl;
    for (vector<ComplexNumber>::iterator it = a.begin(); it != a.end(); ++it) {
        cout << *it << endl;
    }
 
    cout << endl;
 
    return 0;
}
