#include <iostream>
using namespace std;

//--------------------------обувь - абстрактный и конкретные продукты ------------------------------------------------
class IShoes {
public:
    virtual void makeShoes() = 0;
};

class sportShoes : public IShoes {
public:
    void makeShoes() override {
        cout << "Кроссовки" << endl;
    }
};

class formalShoes : public IShoes {
public:
    void makeShoes() override {
        cout << "Туфли" << endl;
    }
};

//--------------------------одежда - абстрактный и конкретные продукты ------------------------------------------------
class IClothes {
public:
    virtual void makeClothes() = 0;
};

class sportClothes : public IClothes {
public:
    void makeClothes() override {
        cout << "Спортивный костюм" << endl;
    }
};

class formalClothes : public IClothes {
public:
    void makeClothes() override {
        cout << "Смокинг" << endl;
    }
};

//--------------------------Образ - абстрактная и конкретные фабрики------------------------------------------------

class ILookFactory {
public:
    virtual IClothes* provideClothes() = 0;
    virtual IShoes* provideShoes() = 0;
};

class formalLookFactory : public ILookFactory {
public:
    IClothes* provideClothes() override {
        return new formalClothes();
    }

    IShoes* provideShoes() override {
        return new formalShoes();
    }
};

class sportLookFactory : public ILookFactory {
public:
    IClothes* provideClothes() override {
        return new sportClothes();
    }

    IShoes* provideShoes() override {
        return new sportShoes();
    }
};

//--------------------------Клиентское взаимодействие------------------------------------------------

void ClientCode(ILookFactory& factory) {
    IClothes* clothes = factory.provideClothes();
    IShoes* shoes = factory.provideShoes();
    clothes->makeClothes();
    shoes->makeShoes();
    delete clothes;
    delete shoes;
}

int main()
{
    setlocale(LC_ALL, "russian");

    cout << "Классический образ состоит из:" << endl;

    formalLookFactory* f1 = new formalLookFactory();
    ClientCode(*f1);
    delete f1;

    cout << endl << "Спортивный образ состоит из:" << endl;
    sportLookFactory* f2 = new sportLookFactory();
    ClientCode(*f2);
    delete f2;

    return 0;

}