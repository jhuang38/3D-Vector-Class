#include <iostream>
#include <cmath>

class vector_3d {
    private:
        double x1, x2, x3;
    public:
        // constructors
        vector_3d(): x1{0}, x2{0}, x3{0} {}
        vector_3d(double x, double y, double z): x1{x}, x2{y}, x3{z} {}

        // destructor
        ~vector_3d() {}

        // copy
        vector_3d(const vector_3d &original) {
            set_x1(original.get_x1());
            set_x2(original.get_x2());
            set_x3(original.get_x3());
        }

        //move

        // overloaded operators
        vector_3d operator+(const vector_3d &other) const {
            return vector_3d(x1 + other.x1, x2 + other.x2, x3 + other.x3);
        }
        vector_3d operator-(const vector_3d &other) const {
            return vector_3d(x1 - other.x1, x2 - other.x2, x3 - other.x3);
        }
        // scalar multiplication operator
        vector_3d operator*(const double &scalar) const {
            return vector_3d(x1 * scalar, x2 * scalar, x3 * scalar);
        }
        bool operator==(const vector_3d &other) const {
            return ((x1 == other.x1) && (x2 == other.x2) && (x3 == other.x3));
        }
        bool operator!=(const vector_3d &other) const {
            return ((x1 != other.x1) || (x2 != other.x2) || (x3 != other.x3));
        }
        
        
        friend std::ostream &operator<<(std::ostream &out, vector_3d const &a);

        // member functions
        // setters and getters
        double get_x1() const {
            return x1;
        }
        double get_x2() const {
            return x2;
        }
        double get_x3() const {
            return x3;
        }
        void set_x1(double new_x1) {
            x1 = new_x1;
        }
        void set_x2(double new_x2) {
            x2 = new_x2;
        }
        void set_x3(double new_x3) {
            x3 = new_x3;
        }
        // other operations with vectors
        double norm() const {
            return std::sqrt(get_x1() * get_x1() + get_x2() * get_x2() + get_x3() * get_x3());
        }
        void normalize() {
            const double original_norm = norm();
            set_x1(get_x1()/original_norm);
            set_x2(get_x2()/original_norm);
            set_x3(get_x3()/original_norm);

        }
        friend double dot_product(const vector_3d &a, const vector_3d &b);

        vector_3d projection(const vector_3d &other) const {
            vector_3d to_project(get_x1(), get_x2(), get_x3());
            double scalar_factor = dot_product(to_project, other)/(other.norm() * other.norm());
            return vector_3d(scalar_factor * other.get_x1(), scalar_factor * other.get_x2(), scalar_factor * other.get_x3());
        }

        vector_3d perp(const vector_3d &other) const {
            vector_3d to_project(get_x1(), get_x2(), get_x3());
            return to_project - to_project.projection(other);
        }

        friend vector_3d cross_product(const vector_3d &a, const vector_3d &b);
};

// other functions
std::ostream &operator<<(std::ostream &out, vector_3d const &a) {
    out << "[" << a.x1 << ", " << a.x2 << ", " << a.x3 << "]";
    return out;
}

double dot_product(const vector_3d &a, const vector_3d &b) {
    return a.get_x1() * b.get_x1() + a.get_x2() * b.get_x2() + a.get_x3() * b.get_x3();
}

vector_3d cross_product(const vector_3d &a, const vector_3d &b) {
    double x1_term = a.get_x2() * b.get_x3() - a.get_x3() * b.get_x2() + 0;
    double x2_term = -(a.get_x1() * b.get_x3() - a.get_x3() * b.get_x1()) + 0;
    double x3_term = a.get_x1() * b.get_x2() - a.get_x2() * b.get_x1() + 0;
    // for more intuitive representation, all cases of -0 are converted to 0
    return vector_3d(x1_term, x2_term, x3_term);
}

