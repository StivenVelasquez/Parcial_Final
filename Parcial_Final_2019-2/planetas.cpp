#include "planetas.h"

float Planetas::getposx()
{
    return Pposx;
}

float Planetas::getposy()
{
    return Pposy;
}

float Planetas::getvelx()
{
    return Pvelx;
}

float Planetas::getvely()
{
    return Pvely;
}

float Planetas::getmasa()
{
    return Pmasa;
}


QRectF Planetas::boundingRect() const //se define el rectangulo que encierra el objeto
{
    return QRectF(-Pradio,-Pradio,2*Pradio,2*Pradio);
}

//Para dibujar los cuerpos
void Planetas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawEllipse(boundingRect());
}

Planetas::Planetas(float x, float y, float vx, float vy, float m, float r)//Constructor de la clase
 {
      Pposx =x;
      Pposy = y;
      Pvelx = vx;
      Pvely =vy;
      Pmasa=m;
      Pradio =r;
      Velx=0;
      Vely=0;
      Acelx=0;
      Acely=0;
}

float Planetas::CalcularAcelx(Planetas *A)//Para aceleración en 'X'
{
    float dist,ang;

    dist=sqrt( pow(A->getposx()-getposx(),2)+ pow( A->getposy()-getposy(),2));
    ang= atan2(( A->getposy()-getposy()) , A->getposx()-getposx());
    Acelx +=(((G * A->getmasa()) / pow(dist,2))*cos(ang) );

 return Acelx;

}

float Planetas::CalcularAcely(Planetas *A)//Para aceleracion en 'Y'
{
    float dist,ang;

    dist=sqrt( pow( A->getposx()-getposx(),2)+ pow( A->getposy()-getposy(),2));
    ang= atan2(( A->getposy()-getposy()) , A->getposx()-getposx());
    Acely += (((G * A->getmasa()) / pow(dist,2))*sin(ang));

    return Acely;
}

float Planetas::CalcularVelx()//Para velocidad en 'X'
{
 Velx= getvelx() + (Acelx* dt);
         return Velx;
}

float Planetas::CalcularVely()//Para velocidad en 'Y'
{
    Vely= getvely() + (Acely* dt);
            return Vely;

}

float Planetas::getPosx()//Para la Posición en 'X'
{
    Posx=getposx()+(getvelx() * dt) + ((Acelx* pow(dt,2)/2));
     return Posx;

}

float Planetas::getPosy()//Para la Posición en 'Y'
{
    Posy=getposy()+(getvely() * dt) + ((Acely* pow(dt,2)/2));
     return Posy;

}

void Planetas::ModValor()
{
    Pposx=Posx;
    Pposy=Posy;
    Pvelx=Velx;
    Pvely=Vely;
    Acelx=0;
    Acely=0;

}

void Planetas::mover()
{
    qDebug()<<"Posiciones sin escalar  Posx= "<<Posx << "  Posy= "<<Posy<<endl;
    setPos(Posx*es,-Posy*es);
    qDebug()<<"Posiciones escaladas  Posx= "<<Posx*es << "  Posy= "<<Posy*es<<endl;
}
