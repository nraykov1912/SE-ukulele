#include <QString>

class Material{
private:
    int mId;
    float price;
    QString name;
    float absorption;
    float elasticity;

public:
    Material();
    Material(int, float, QString, float, float);

    int getId(void);
    float getPrice(void);
    void changePrice(float);
    QString getName(void);
    float getAbsorption(void);
    float getElasticity(void);

    Material& operator =(const Material&);
    Material& operator = (const int&);
};

class Uku_String{
private:
    int sId;
    float price;
    float length;
    float radius;
    QString color;
    Material material;

public:
    Uku_String();
    Uku_String(int, float, float, float, QString, Material);

    int getId(void);
    float getLength(void);
    float getRadius(void);
    void changeColor(QString);
    Material getMaterial(void);

    void makeSound(); // assume each Uku_String is made from diff material => creating diff sound

    Uku_String& operator =(const Uku_String&);
    Uku_String& operator =(const int&);
};

class Body{
private:
     int bId;
     float price;
     Material material;
     int toughness; // scale 1-3;

public:
     Body();
     Body(int,float, Material);

     int getId(void);
     Material getMaterial(void);

     int determineToughness(); // material defines toughness

     Body& operator =(const Body&);
     Body& operator =(const int&);
 };

class Bridge{
private:
    int bridgeId;
    float price;
    Material material;

public:
    Bridge();
    Bridge(int, float, Material);

    int getID(void);

    Bridge& operator =(const Bridge&);
    Bridge& operator =(const int&);
};

class Neck{
private:
    int nId;
    float price;
    float length;
    Material material;

public:
    Neck();
    Neck(int, float, float, Material);

    int getId(void);
    float getPrice(void);
    void changePrice(float);
    Material getMaterial(void);
    float getLength(void);

    Neck& operator =(const Neck&);
    Neck& operator =(const int&);
};

class Ukulele{
private:
    int uId;
    float price;
    Uku_String uku_String;
    Body body;
    Bridge bridge;
    Neck neck;

public:
    Ukulele();
    Ukulele(int,float, Uku_String, Body, Bridge, Neck);

    int getID(void);
    float getPrice(void);
    void changePrice(float);
};
