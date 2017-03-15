#include "mainwindow.h"
#include <iostream>

Material::Material(){
    mId = 0;
    price = 0;
    name = "Name not set";
    absorption = 0;
    elasticity = 0;
}

Material::Material(int mId, float price, QString name,
                   float absorption, float elasticity) {
    this->mId = mId;
    this->price = price;
    this->name = name;
    this->absorption = absorption;
    this->elasticity = elasticity;
}

int Material::getId(){
    return mId;
}

float Material::getPrice(){
    return price;
}

void Material::changePrice(float newPrice) {
    if(newPrice<0)
        price = 0;
    else
        price = newPrice;
}

QString Material::getName(){
    return name;
}

float Material::getAbsorption(){
    return absorption;
}

float Material::getElasticity(){
    return elasticity;
}

Material& Material::operator= (const Material& mat) {
    this->mId = mat.mId;
    this->price = mat.price;
    this->name = mat.price;
    this->absorption = mat.absorption;
    this->elasticity = mat.elasticity;

    return *this;
}

Material& Material::operator= (const int& def) {
    this->mId = def;
    this->price = def;
    this->name = " ";
    this->absorption = def;
    this->elasticity = def;

    return *this;
}

Uku_String::Uku_String(){
    sId = 0;
    price = 0;
    length =0;
    radius = 0;
    color = "not set";
    material = 0;
}

Uku_String::Uku_String(int sId, float price, float length, float radius,
               QString color, Material material){
    this->sId = sId;
    this->price = price;
    this->length = length;
    this->radius = radius;
    this->color = color;
    this->material = material;
}

int Uku_String::getId(){
    return sId;
}

float Uku_String::getLength(){
    return length;
}

float Uku_String::getRadius(){
    return radius;
}

Material Uku_String::getMaterial(){
    return material;
}

void Uku_String::changeColor(QString newColor){
    color = newColor;
}

void Uku_String::makeSound(){
    if(this->material.getAbsorption()<=3) {
        std::cout << "Low frequency soud" << std::endl;
    }

    if(this->material.getAbsorption()>3 && this->material.getAbsorption() <= 6){
        std::cout << "Medium frequency sound" << std::endl;
    }
    if(this->material.getAbsorption()>6){
        std::cout << "High frequency sound" << std::endl;
    }
}

Uku_String& Uku_String::operator =(const Uku_String& str){
    this->sId = str.sId;
    this->price = str.price;
    this->length = str.length;
    this->radius = str.radius;
    this->color = str.color;
    this->material = str.material;

    return *this;
}

Uku_String& Uku_String::operator =(const int& def){
    this->sId = def;
    this->price = def;
    this->length = def;
    this->radius = def;
    this->color = " ";
    this->material = def;

    return *this;
}

Body::Body(){
    bId = 0;
    price = 0;
    material = 0;
}

Body::Body(int bId, float price, Material material){
    this->bId = bId;
    this->price = price;
    this->material = material;
}

int Body::getId(){
    return bId;
}

Material Body::getMaterial(){
    return material;
}

int Body::determineToughness(){
    if(this->material.getElasticity()<=4){
        toughness = 1;
    }
    if(this->material.getElasticity()>4 && this->material.getElasticity()<8){
        toughness = 2;
    }
    if(this->material.getElasticity()>=8){
        toughness =3;
    }
    return toughness;
}

Body& Body::operator =(const Body& bod){
    this->bId = bod.bId;
    this->price = bod.price;
    this->material = bod.material;

    return *this;
}

Body& Body::operator =(const int& def){
    this->bId = def;
    this->price = def;
    this->material = def;

    return *this;
}

Bridge::Bridge(){
    bridgeId = 0;
    price = 0;
    material =0;
}

Bridge::Bridge(int bridgeId, float price, Material material){
    this->bridgeId = bridgeId;
    this->price = price;
    this->material = material;
}

int Bridge::getID(){
    return bridgeId;
}

Bridge& Bridge::operator =(const Bridge& bri){
    this->bridgeId = bri.bridgeId;
    this->price = bri.price;
    this->material = bri.material;

    return *this;
}

Bridge& Bridge::operator =(const int& def){
    this->bridgeId = def;
    this->price = def;
    this->material =def;

    return *this;
}

Neck::Neck(){
    nId = 0;
    price = 0;
    length =0;
    material =0;
}

Neck::Neck(int nId, float price, float length, Material material){
    this->nId = nId;
    this->price = price;
    this->length = length;
    this->material = material;
}

int Neck::getId(){
    return nId;
}

float Neck::getPrice(){
    return price;
}

void Neck::changePrice(float newPrice){
    if(newPrice < 0)
        price = 0;
    else
        price = newPrice;
}

Material Neck::getMaterial(){
    return material;
}

float Neck::getLength(){
    return length;
}

Neck& Neck::operator =(const Neck& ne){
    this->nId = ne.nId;
    this->price = ne.price;
    this->material = ne.material;
    this->length = ne.length;

    return *this;
}

Neck& Neck::operator =(const int& def){
    this->nId = def;
    this->price = def;
    this->material =def;
    this->length =def;

    return *this;
}

Ukulele::Ukulele(){
    uId = 0;
    price = 0;
    uku_String = 0;
    body = 0;
    bridge = 0;
    neck = 0;
}

Ukulele::Ukulele(int uId, float price, Uku_String uku_String,
                 Body body, Bridge bridge, Neck neck){
    this->uId = uId;
    this->price = price;
    this->uku_String = uku_String;
    this->body = body;
    this->bridge = bridge;
    this->neck = neck;
}

int Ukulele::getID(){
    return uId;
}

float Ukulele::getPrice(){
    return price;
}

void Ukulele::changePrice(float newPrice){
    if(newPrice<0)
        price = 0;
    else
        price = newPrice;
}
