#pragma once
#include "Turn.h"

class Star
{
private:
   int starType;
   Turn *created;
public:
   const static int TYPE_ISM = 0;
   const static int TYPE_HIGH_MASS = 1;
   const static int TYPE_MED_MASS = 2;
   const static int TYPE_LOW_MASS = 3;

   Star():
      starType(0),
      created(nullptr)
   { }

   Star(int type, Turn* turn) :
      starType(type),
      created(turn)
   { }

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
};

