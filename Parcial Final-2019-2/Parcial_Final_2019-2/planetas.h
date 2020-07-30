#ifndef PLANETAS_H
#define PLANETAS_H
#include <QGraphicsItem>
#include <QPainter>
#include <math.h>
#include <QDebug>

#define G 1
#define dt  1
#define es 0.05

class Planetas : public QGraphicsItem
{
private: //Atributos
    float Pposx,Pposy,Pvelx,Pvely,Pmasa,Pradio,Acelx,Acely;
    float Posx,Posy,Velx,Vely;

public://Metodos
    Planetas(float x, float y, float vx, float vy, float m, float r); //Constructor
    float CalcularAcelx(Planetas *A);
    float CalcularAcely(Planetas *A);
    float CalcularVelx();
    float CalcularVely();
    void ModValor();
    void  mover();
    //Metodos get
    float getposx() ;
    float getposy() ;
    float getvelx() ;
    float getvely() ;
    float getmasa() ;
    float getPosx();
    float getPosy();
    QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PLANETAS_H
