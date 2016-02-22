#pragma once
class Turn
{
private:
   int planetaryNeb;
   int TISupernova;
   int TIISuperNova;
   int num;
public:
   Turn():
      planetaryNeb(0),
      TISupernova(0),
      TIISuperNova(0),
      num(0)
   {}

   Turn(int pn, int tI, int tII):
      planetaryNeb(pn),
      TISupernova(tI),
      TIISuperNova(tII)
   {}

   int getNum() const
   {
      return num;
   }
};

