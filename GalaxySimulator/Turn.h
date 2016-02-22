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

   Turn(int pn, int tI, int tII, int n):
      planetaryNeb(pn),
      TISupernova(tI),
      TIISuperNova(tII),
      num(n)
   {}

   Turn(const Turn& obj):
      planetaryNeb(obj.planetaryNeb),
      TISupernova(obj.TISupernova),
      TIISuperNova(obj.TIISuperNova),
      num(obj.num)
   {}

   int getNum() const
   {
      return num;
   }
};

