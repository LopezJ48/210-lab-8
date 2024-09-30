#include <iostream>

using namespace std;

class Color {
private:
    int red;
    int green;
    int blue;

public:
    // Constructor
    Color(int r, int g, int b) : red(r), green(g), blue(b) {}

    // Setter methods (remove const)
    void setRed(int r) {
        red = r; // Use the class member variable
    }

    void setGreen(int g) {
        green = g; // Use the class member variable
    }

    void setBlue(int b) {
        blue = b; // Use the class member variable
    }

    // Getter methods
    int getRed() const {
        return red;
    }

    int getGreen() const {
        return green;
    }

    int getBlue() const {
        return blue;
    }

    // Print method
    void print() const { // Marked as const since it doesn't modify the object
        cout << "Color (R: " << red << ", G: " << green << ", B: " << blue << ")" << endl;
    }
};

int main() {
    // Creating Color objects with different RGB values
    Color Mix1(255, 99, 43);
    Color Mix2(0, 255, 0);
    Color Mix3(0, 0, 255);
    Color Mix4(255, 255, 0);
    Color Mix5(255, 0, 255);
    Color Mix6(0, 255, 255);
    Color Mix7(128, 128, 128);

    // Printing the color objects
    Mix1.print();
    Mix2.print();
    Mix3.print();
    Mix4.print();
    Mix5.print();
    Mix6.print();
    Mix7.print();

    return 0;
}
