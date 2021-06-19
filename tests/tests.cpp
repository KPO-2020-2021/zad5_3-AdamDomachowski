#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include <stdio.h>
#include "Vector.hh"
#include "Vector2D.hh"
#include "Vector3D.hh"
#include "Matrix.hh"
#include "matrix2x2.hh"
#include "matrix3x3.hh"
#include "Cuboid.hh"
#include "prism6.hh"
#include "Solid.hh"
#include "scena.hh"


//testy do Vector3D

TEST_CASE("odczytywanie wartosci wektora."){
    double tab[]={9,67,5};
    double a,b,c;
    Vector3D temporary(tab);
    a = temporary[0];
    b = temporary[1];
    c = temporary[2];
    CHECK((a == 9 && b == 67 && c == 5));
}
 
TEST_CASE("wprowadzanie danych do wektora"){ 
    Vector3D temporary;
    double a=7,b=15,c=20;
    temporary[0]=a;
    temporary[1]=b;
    temporary[2]=c;
    CHECK((temporary[0]==7 && temporary[1]==15 && temporary[2]==20));
}

TEST_CASE("konstrukor bezparametryczny"){
    Vector3D temporary;
    CHECK((temporary[0]==0 && temporary[1]==0 && temporary[2]==0));
}

TEST_CASE("konstruktor parametryczny"){
    double tab[]={1,2,3};
    Vector3D temporary(tab);
    CHECK((temporary[0]==1 && temporary[1]==2 && temporary[2]==3));
}

TEST_CASE("operatora indeksowania - za duzy/maly indeks"){
    double tab[]={1,2,3};
    Vector3D temporary(tab);
    WARN_THROWS (temporary[33]);
}

TEST_CASE("wypisanie wektora"){
    double tab[]={3,2,45};
    Vector3D temporary(tab);
    std::ostringstream out;
    out << temporary;
    CHECK ("3.0000000000 2.0000000000 45.0000000000 " == out.str());  
}

TEST_CASE("wczytywanie wartosci do wektora3D ( >> )."){
    Vector3D temporary;
    std::istringstream input("44 2 -3");
    input >> temporary;
    CHECK ((temporary[0] == 44 && temporary[1] == 2 && temporary[2] == -3));  
}

TEST_CASE("dodawanie dwoch wektorow."){
    double a[]={1,2,3},b[]={6,8,-7};
    Vector3D temporoary(a),temporoary2(b);
    temporoary=temporoary+temporoary2;
    CHECK ((temporoary[0] == 7 && temporoary[1] == 10 && temporoary[2] == -4));  
}

TEST_CASE("odejmowanie dwoch wektorow."){
    double a[]={1,2,5},v[]={6,8,-6};
    Vector3D Vec1(a),Vec2(v);
    Vec1=Vec1-Vec2;
    CHECK ((Vec1[0] == -5 && Vec1[1] == -6 && Vec1[2] == 11));  
}

TEST_CASE("mnozenie wektora3D i liczby."){
    double tab[]={1,2,3};
    Vector3D temp(tab);
    temp=temp*2;
    CHECK ((temp[0] == 2 && temp[1] == 4 && temp[2] == 6));  
}

TEST_CASE("dzielenie wektora3D przez liczbe typu double."){
    double a[]={1,2,3};
    Vector3D temp(a);
    temp=temp/2;
    CHECK ((temp[0] == 0.5 && temp[1] == 1 && temp[2] == 1.5));  
}

TEST_CASE("dzielenie wektora3D przez 0."){
    double a[]={1,2,3};
    Vector3D Vec1(a);
    WARN_THROWS (Vec1 = Vec1 / 0);
}

// testy do Vector2D

TEST_CASE("vector - konstruktor bezparametryczny Vector()")
{
  Vector2D test = Vector2D();
  for(int i=0;i<SIZE;i++){
  CHECK(test[i]==0);
  }
}

TEST_CASE("vector - konstruktor parametryczny Vector(double[2])")
{
  double example[2] = {1,2}; 
  //double bad_sample[2] = {2137,2137};
  Vector2D test = Vector2D(example);
  for(int i=0;i<SIZE;i++){
  CHECK(test[i]==example[i]);
  }
}

TEST_CASE("vector - operator +")
{
  double first[2] = {1,2}; 
  Vector2D first_one = Vector2D(first);

  double second[2] = {2137,2137};
  Vector2D second_one = Vector2D(second);
  Vector2D temp = first_one + second_one;

  double sum[2] = {2138,2139};
  Vector2D sample = Vector2D(sum);

  for(int i=0;i<SIZE;i++){
  CHECK(temp[i]==sample[i]);
  }
}

TEST_CASE("vector - operator -")
{
  double first[2] = {1,2}; 
  Vector2D first_one = Vector2D(first);

  double second[2] = {2137,2137};
  Vector2D second_one = Vector2D(second);
  Vector2D schowek = first_one - second_one;

  double sum[2] = {-2136,-2135};
  Vector2D sample = Vector2D(sum);

  for(int i=0;i<SIZE;i++){
  CHECK(schowek[i]==sample[i]);
  }
}

TEST_CASE("vector - operator [out of size]") 

{
  double sample_pack[2] = {21,37};
  Vector2D sample = Vector2D(sample_pack);  

  WARN_THROWS(sample[3]);
 
}

//testy dla matrix2x2

TEST_CASE("konstrukor bezparametryczny"){
    Matrix2x2 temp;
    CHECK((temp(0,0)==1 && temp(0,1)==0 && temp(1,0)==0 && temp(1,1)==1));
}

TEST_CASE("konstruktor parametryczny"){ 
    Matrix2x2 temp[2][2];
    CHECK((sizeof(temp)/sizeof(Matrix2x2)==4));
}

TEST_CASE("wczytywanie i odczytywania wartosci"){
    double tab[2][2]={1,2,3,4};
    Matrix2x2 temp(tab);
    CHECK((temp(0,0)==1 && temp(0,1)==2 && temp(1,0) ==3 && temp(1,1)==4));
}

TEST_CASE("mnozenie macierzy2x2 i wektora."){
    double a[]={5,10}, b[2][2]={1,2,3,4};
    Vector<2> A(a);
    Matrix2x2 B(b);
    A=B*A;
    CHECK((A[0] == 25 && A[1] == 55));
}

TEST_CASE("mnozenie macierzy przez macierz."){
    double a[2][2]={1,2,3,4},b[2][2]={9,5,3,2};
    Matrix2x2 A(a),B(b),Result;
    Result = A * B;
    CHECK((Result(0,0) == 15 && Result(0,1) == 9 && Result(1,0) == 39 && Result(1,1) == 23));
}

TEST_CASE("dodawanie dwoch macierzy"){
    double a[2][2]={4,6,8,12},b[2][2]={6,4,2,-2};
    Matrix2x2 temp(a),temp1(b),Result;
    Result = temp + temp1;
    CHECK((Result(0,0) == 10 && Result(0,1) == 10 && Result(1,0) == 10 && Result(1,1) == 10));
}

TEST_CASE("porownanie dwoch takich samych macierzy."){
    double a[2][2]={1,2,3,4};
    Matrix2x2 temp1(a),temp2(a);
    CHECK((temp1==temp2));
}

TEST_CASE("porownanie dwoch roznych macierzy."){
    double a[2][2]={1,2,3,4},b[2][2]={1,5,7,4};
    Matrix2x2 temp(a),temp1(b);
    CHECK(!(temp==temp1));
}

TEST_CASE("reset macierzy."){
    double a[2][2]={1,2,3,4};
    Matrix2x2 temp(a),jednostkowa;
    temp.reset_matrix();
    CHECK((temp==jednostkowa));
}

//testy dla Cuboid

TEST_CASE("test parametrycznego konstruktora klasy."){
Cuboid cub;

CHECK(cub.jaka_nazwa() == "../datas/cuboid.dat");
double zero[3] = {0,0,0};
Vector3D srodek = Vector3D(zero);
CHECK(cub.zczytaj_srodek() == srodek);

double w0[3] = {-15,15,10};
double w1[3] = {-15,15,-10};
double w2[3] = {15,15,10};
double w3[3] = {15,15,-10};
double w4[3] = {15,-15,10};
double w5[3] = {15,-15,-10};
double w6[3] = {-15,-15,10};
double w7[3] = {-15,-15,-10};

Vector3D a = Vector3D(w0);
CHECK(cub.czytaj_wierzcholki(0) == a);
Vector3D b = Vector3D(w1);
CHECK(cub.czytaj_wierzcholki(1) == b);
Vector3D c = Vector3D(w2);
CHECK(cub.czytaj_wierzcholki(2) == c);
Vector3D d = Vector3D(w3);
CHECK(cub.czytaj_wierzcholki(3) == d);
Vector3D e = Vector3D(w4);
CHECK(cub.czytaj_wierzcholki(4) == e);
Vector3D f = Vector3D(w5);
CHECK(cub.czytaj_wierzcholki(5) == f);
Vector3D g = Vector3D(w6);
CHECK(cub.czytaj_wierzcholki(6) == g);
Vector3D h = Vector3D(w7);
CHECK(cub.czytaj_wierzcholki(7) == h);
}

//testy dla prism6

TEST_CASE("test parametrycznego konstruktora klasy Prism6."){
Prism6 prism;

CHECK(prism.jaka_nazwa() == "../datas/graniastoslup6.dat");
double zero[3] = {0,0,0};
Vector3D srodek = Vector3D(zero);
CHECK(prism.zczytaj_srodek() == srodek);
/*
double w0[3] = {10,0,7.5};
double w1[3] = {10,0,-7.5};
double w2[3] = {5,8.6602540378,7.5};
double w3[3] = {5,8.6602540378,-7.5};
double w4[3] = {-5,8.6602540378,7.5};
double w5[3] = {-5,8.6602540378,-7.5};
double w6[3] = {-10,0,7};
double w7[3] = {-15,-15,-10};
double w8[3] = {15,-15,10};
double w9[3] = {15,-15,-10};
double w10[3] = {-15,-15,10};
double w11[3] = {-15,-15,-10};

Vector3D a = Vector3D(w0);
CHECK(prism.czytaj_wierzcholki(0) == a);
Vector3D b = Vector3D(w1);
CHECK(prism.czytaj_wierzcholki(1) == b);
Vector3D c = Vector3D(w2);
CHECK(prism.czytaj_wierzcholki(2) == c);
Vector3D d = Vector3D(w3);
CHECK(prism.czytaj_wierzcholki(3) == d);
Vector3D e = Vector3D(w4);
CHECK(prism.czytaj_wierzcholki(4) == e);
Vector3D f = Vector3D(w5);
CHECK(prism.czytaj_wierzcholki(5) == f);
Vector3D g = Vector3D(w6);
CHECK(prism.czytaj_wierzcholki(6) == g);
Vector3D h = Vector3D(w7);
CHECK(prism.czytaj_wierzcholki(7) == h);
Vector3D i = Vector3D(w8);
CHECK(prism.czytaj_wierzcholki(4) == i);
Vector3D j = Vector3D(w9);
CHECK(prism.czytaj_wierzcholki(5) == j);
Vector3D k = Vector3D(w10);
CHECK(prism.czytaj_wierzcholki(6) == k);
Vector3D l = Vector3D(w11);
CHECK(prism.czytaj_wierzcholki(7) == l);
*/
}


//testy dla Drona






