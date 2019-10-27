#include <iostream>
#include <vector>

template<typename T>
struct rectangle {
    public:
    T w; T h;
    virtual void setW(T new_w){
        this->w = new_w;
    }

    virtual void setH(T new_h){
        this->h = new_h;
    }
};

template<typename T>
struct square : public rectangle<T> {
    public:
    void setW(T new_w) override{
        this->w = this->h = new_w;
    }
    void setH(T new_h) override {
        this->h = this->w = new_h;
    }
};

// This function will accept all the derivates from rectangle
template<typename T>
void process(rectangle<T>& rec){
    rec.setW(10);
    std::cout << "Expected : " << 10*10 << ", returned :" << rec.h * rec.w << std::endl;
}



int main(){
    rectangle<int> r;
    square<int> s;

    r.setH(10);
    r.setW(10);
    s.setH(50);
    process(r);
    process(s);

    return 0;
}