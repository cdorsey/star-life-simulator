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
      TIISuperNova(obj.TIISuperNova)
   {
      num = obj.num + 1;
   }

   int getNum() const
   {
      return num;
   }

   friend std::ostream& operator<<(std::ostream& os, const Turn& obj) 
   {
      os << "TI: " << obj.TISupernova << " TII: " << obj.TIISuperNova << " PN: " << obj.planetaryNeb;

      return os;
   }
};

