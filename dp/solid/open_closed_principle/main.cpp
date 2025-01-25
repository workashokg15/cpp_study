#include <iostream>
#include <vector>
#include <random>
#include <string>
using namespace std;

enum class Color {red, blue, green};
enum class Size {small, medium, big};

struct Product {
    string name;
    Color color;
    Size size;
    explicit Product(const string& name, Color c, Size s) : name(name), color(c), size(s) {}    
    const string& get_name() const {
        return name;
    }
};
ostream& operator<<(ostream& out, const Product* p) {
    return out << p->get_name();
}


struct FilterBySize {
    Size size;
    FilterBySize(const Size size):size(size) {};
    bool filter(Product p) {
        return p.size == size;
    }
};

struct FilterByColor {
    Color color;
    FilterByColor(const Color color):color(color) {};
    bool filter(Product p) {
        return p.color == color;
    }
};

struct FilterByColorAndSize {
    Size size;
    Color color;
    FilterByColorAndSize(const Size size, const Color color):color(color), size(size) {}
    bool filter(Product& p) {
        return size == p.size && color == p.color;        
    }
};

template <typename T>
struct Specification {
    virtual ~Specification() = default;
    virtual bool is_satisfied(T* item) const = 0;
};


struct ColorSpecification : public Specification<Product> {
    Color color;
    ColorSpecification(Color color) : color(color) {}
    bool is_satisfied(Product *p) const override{
        return p->color == color;
    }
};

struct SizeSpecification : public Specification<Product> {
    Size size;
    SizeSpecification(Size size) : size(size) {}
    bool is_satisfied(Product *p) const override{
        return p->size == size;
    }
};

template <typename T>
struct AndSpecification : public Specification<T>
{
    const Specification<T>& first;
    const Specification<T>& second;

    AndSpecification(const Specification<T>& first, const  Specification<T>& second) : first(first), second(second) {}
    bool is_satisfied(T *item) const override {
        return first.is_satisfied(item) && second.is_satisfied(item);
    }
};

template <typename T>
AndSpecification<T> operator&&(Specification<T>& first, Specification<T>& second) {
    return {first, second};
}

template <typename T>
struct OrSpecification : public Specification<T> {
    const Specification<T>& first;
    const Specification<T>& second;

    OrSpecification(const Specification<T>&first, const Specification<T>& second): first(first), second(second) {}

    bool is_satisfied(T *item) const override {
        return first.is_satisfied(item) || second.is_satisfied(item);
    }
};

template <typename T>
OrSpecification<T> operator||(Specification<T>&first, Specification<T>& second) {
    return {first, second};
}



template <typename T>
struct Filter {
    virtual vector<T *> filter_by_specification(vector<T *>&products, Specification<T>& spec) const = 0;
};

struct BetterFilter:Filter<Product> {
    vector<Product *> filter_by_specification(vector<Product *>&products, Specification<Product>& spec) const override {
        vector<Product *> items;
        for(auto& product : products) {
            if(spec.is_satisfied(product)) {
                items.push_back(product);
            }
        }
        return items;
    }
};

int main()
{
    vector<Product*> products;
    products.push_back(new Product{"rexona", Color::red, Size::small});
    products.push_back(new Product{"atree", Color::green, Size::big});
    products.push_back(new Product{"kite", Color::green, Size::medium}); 
    products.push_back(new Product{"ahouse", Color::blue, Size::big});

    ColorSpecification gs(Color::green);
    BetterFilter fb;

    auto green_products = fb.filter_by_specification(products, gs);
    for(auto& product : green_products) {
        cout << product << " is green" << endl;
    }
    cout << endl;

    auto bs = SizeSpecification(Size::big);
    auto gb_spec = gs && bs;
    auto green_and_big_products = fb.filter_by_specification(products, gb_spec);
    for(auto& product : green_and_big_products) {
        cout << product << " is green and big" << endl;
    }
    cout << endl;

    ColorSpecification rs{Color::red};
    auto g_or_r_spec = gs || rs;
    auto green_or_red_products = fb.filter_by_specification(products, g_or_r_spec);
    for(auto& product : green_or_red_products) {
        cout << product << " is green or red" << endl;
    }
    cout << endl;

    return 0;
}