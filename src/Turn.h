#pragma once

#include <stdexcept>

class Turn
{
private:
   int planetaryNeb;
   int T1Supernova;
   int T2SuperNova;
   int num;
public:
   Turn():
      planetaryNeb(0),
      T1Supernova(0),
      T2SuperNova(0),
      num(0)
   {}

   Turn(int pn, int tI, int tII, int n):
      planetaryNeb(pn),
      T1Supernova(tI),
      T2SuperNova(tII),
      num(n)
   {}

   Turn(const Turn& obj):
      planetaryNeb(obj.planetaryNeb),
      T1Supernova(obj.T1Supernova),
      T2SuperNova(obj.T2SuperNova)
   {
      num = obj.num + 1;
   }

   int getNum() const
   {
      return num;
   }

   /* Increments amount of enrichment via planetary nebula (arbitrary unit) */
   void incPN()
   {
      this->planetaryNeb++;
   }

   /* Increments amount of enrichment via Type I supernova (arbitrary unit) */
   void incT1()
   {
      throw new std::logic_error("Type 1 supernovae not implemented");
      this->T1Supernova++;
   }

   /* Increments amount of enrichment via Type II supernova (arbitrary unit) */
   void incT2()
   {
      this->T2SuperNova++;
   }

   friend std::ostream& operator<<(std::ostream& os, const Turn& obj) 
   {
      os << "TI: " << obj.T1Supernova << " TII: " << obj.T2SuperNova << " PN: " << obj.planetaryNeb;

      return os;
   }
};

