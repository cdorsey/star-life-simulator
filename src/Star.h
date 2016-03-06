#pragma once
#include "Turn.h"

class Star
{
private:
   int starType;
   Turn *created;
   int lifespan;
public:
   const static int TYPE_ISM = 0;
   const static int TYPE_HIGH_MASS = 1;
   const static int TYPE_MED_MASS = 2;
   const static int TYPE_LOW_MASS = 3;

   Star():
           starType(TYPE_ISM),
           created(nullptr),
           lifespan(0)
   { }

   Star(int type, Turn* turn) :
      starType(type),
      created(turn)
   {
      if (type == TYPE_MED_MASS)
         lifespan = 3;
      else
         lifespan = 0;
   }

   void setType(int type)
   {
      this->starType = type;
   }
   void setCreated(Turn* turn)
   {
      this->created = turn;
   }
   int getType() const
   {
      return this->starType;
   }
   int getCreatedAsInt() const
   {
      return this->created->getNum();
   }

    int getLifespan() const
   {
      return this->lifespan;
   }
};

