MAX_ALTAR_NUM = 10
import math
import GameAPI

from Script.SysFun import Alter

class CAltarUpCondition:
       def __init__(self,LV,money,bijou):
           self.Money = money
           self.bijou = bijou
           self.LV    = LV
       def GetValues(self):
           return self.Money,self.bijou

           
class CAltarOblation:
       def __init__(self,affect,Con):
           self.Impact  = affect
           self.Consume = Con
       def GetConsume(self,LV):
           return abs(self.Consume[LV].GetValue());
       def GetValues(self,LV):
           temp = {}
           for k in self.Impact:
                  temp[k]=abs(self.Impact[k][LV-1])
           return temp

       def Release(self,LV,player):
           for C in self.Impact:
              print "LV=%d" % LV
              Temp = Alter( C[LV].Type,-C[LV].Value ) 
              Temp.Callback(player)
           return True

       def LvUp(self,LV,player):
           print "LvUp LV=%d" % LV
           self.Consume[LV].Callback(player)
           for C in self.Impact:
              C[LV].Callback(player)
           return True

       def LoadImpact(self,LV,player):
	   print "LoadImpact LV=%d" % LV
           for C in self.Impact:
              C[LV].Callback(player)
           return True


class CAltar:
       def __init__(self, AltarUpCondition, AltarOblation,type):
           self.__Type       = type
           self.__LVCondtion = AltarUpCondition
           self.__Oblation   = AltarOblation
       def Printf(self):
           print "Hello!"
       def LvValues(self,lv):
           print "Level %d" % lv
           print self.__LVCondtion
           return self.__LVCondtion[lv].GetValues()
       def OblationValues(self,lv):
           return self.__Oblation.GetValues(lv)
       def ConValues(self):
           return self.__Oblation
       def Levelup(self,lv,GUID):
           return GameAPI.AltarLevelup(lv,GUID)
       def OblationLevelup(self,lv):
           effect=self.OblationValues(lv)
           return GameAPI.OblationLevelup(lv,effect)
       def GetID(self):
           return self.__Type


################################################################################

UPCondition =   ( 
                   #ID=0
                   (
                     CAltarUpCondition(0,100,5),
                     CAltarUpCondition(1,180,9),
                     CAltarUpCondition(2,260,13),
                     CAltarUpCondition(3,320,16),
                     CAltarUpCondition(4,420,21),
                     CAltarUpCondition(5,600,30),
                     CAltarUpCondition(6,840,42),
                     CAltarUpCondition(7,1160,58),
                     CAltarUpCondition(8,1600,80),
                     CAltarUpCondition(9,2400,120),
                     CAltarUpCondition(10,4000,200),
                     CAltarUpCondition(11,7000,350)
                    ),
                  )

Impact0 = ( ( Alter(-1,0),Alter(28,100),Alter(28,200),Alter(28,300),Alter(28,400),Alter(28,500),Alter(28,600),Alter(28,700),Alter(28,800),Alter(28,900),Alter(28,1000),Alter(28,1100),Alter(28,1200)),
            ( Alter(-1,0),Alter(29,20),Alter(29,40),Alter(29,60),Alter(29,80),Alter(29,100),Alter(29,120),Alter(29,140),Alter(29,160),Alter(29,180),Alter(29,200),Alter(29,220),Alter(29,240)),
          )

Impact1 = ( ( Alter(-1,0),Alter(30,10),Alter(30,20),Alter(30,30),Alter(30,40),Alter(30,50),Alter(30,60),Alter(30,70),Alter(30,80),Alter(30,90),Alter(30,100),Alter(30,110),Alter(30,120)),
            ( Alter(-1,0),Alter(42,6),Alter(42,12),Alter(42,18),Alter(42,25),Alter(42,31),Alter(42,37),Alter(42,43),Alter(42,50),Alter(42,56),Alter(42,62),Alter(42,68),Alter(42,75)),
          )

Impact2 = ( ( Alter(-1,0),Alter(29,30),Alter(29,60),Alter(29,90),Alter(29,120),Alter(29,150),Alter(29,180),Alter(29,210),Alter(29,240),Alter(29,270),Alter(29,300),Alter(29,330),Alter(29,360)),
            ( Alter(-1,0),Alter(31,5),Alter(31,10),Alter(31,15),Alter(31,20),Alter(31,25),Alter(31,30),Alter(31,35),Alter(31,40),Alter(31,45),Alter(31,50),Alter(31,55),Alter(31,60)),
          )

Impact3 = ( ( Alter(-1,0),Alter(32,27),Alter(32,55),Alter(32,82),Alter(32,110),Alter(32,137),Alter(32,165),Alter(32,192),Alter(32,220),Alter(32,247),Alter(32,275),Alter(32,302),Alter(32,330)),
            ( Alter(-1,0),Alter(36,3),Alter(36,6),Alter(36,9),Alter(36,12),Alter(36,15),Alter(36,18),Alter(36,21),Alter(36,24),Alter(36,27),Alter(36,30),Alter(36,33),Alter(36,36))
          )

Impact4 = ( ( Alter(-1,0),Alter(34,22),Alter(34,45),Alter(34,67),Alter(34,90),Alter(34,112),Alter(34,135),Alter(34,157),Alter(34,180),Alter(34,202),Alter(34,225),Alter(34,247),Alter(34,270)),
            ( Alter(-1,0),Alter(32,12),Alter(32,25),Alter(32,37),Alter(32,50),Alter(32,62),Alter(32,75),Alter(32,87),Alter(32,100),Alter(32,112),Alter(32,125),Alter(32,137),Alter(32,150))
          )

Impact5 = ( ( Alter(-1,0),Alter(33,25),Alter(33,50),Alter(33,75),Alter(33,100),Alter(33,125),Alter(33,150),Alter(33,175),Alter(33,200),Alter(33,225),Alter(33,250),Alter(33,275),Alter(33,300)),
            ( Alter(-1,0),Alter(35,7),Alter(35,15),Alter(35,22),Alter(35,30),Alter(35,37),Alter(35,45),Alter(35,52),Alter(35,60),Alter(35,67),Alter(35,75),Alter(35,82),Alter(35,90)),
          )

Impact6 = ( ( Alter(-1,0),Alter(35,12),Alter(35,25),Alter(35,37),Alter(35,50),Alter(35,62),Alter(35,75),Alter(35,87),Alter(35,100),Alter(35,112),Alter(35,125),Alter(35,137),Alter(35,150)),
            ( Alter(-1,0),Alter(42,6),Alter(42,12),Alter(42,18),Alter(42,25),Alter(42,31),Alter(42,37),Alter(42,43),Alter(42,50),Alter(42,56),Alter(42,62),Alter(42,68),Alter(42,75)),
          )

Impact7 = ( ( Alter(-1,0),Alter(42,12),Alter(42,25),Alter(42,37),Alter(42,50),Alter(42,62),Alter(42,75),Alter(42,87),Alter(42,100),Alter(42,112),Alter(42,125),Alter(42,137),Alter(42,150)),
            ( Alter(-1,0),Alter(37,3),Alter(37,6),Alter(37,9),Alter(37,12),Alter(37,15),Alter(37,18),Alter(37,21),Alter(37,24),Alter(37,27),Alter(37,30),Alter(37,33),Alter(37,36)),
          )

Impact8 = ( ( Alter(-1,0),Alter(36,6),Alter(36,12),Alter(36,18),Alter(36,24),Alter(36,30),Alter(36,36),Alter(36,42),Alter(36,48),Alter(36,54),Alter(36,60),Alter(36,66),Alter(36,72)),
            ( Alter(-1,0),Alter(34,10),Alter(34,20),Alter(34,30),Alter(34,40),Alter(34,50),Alter(34,60),Alter(34,70),Alter(34,80),Alter(34,90),Alter(34,100),Alter(34,110),Alter(34,120)),
          )

Impact9 = ( ( Alter(-1,0),Alter(37,6),Alter(37,12),Alter(37,18),Alter(37,24),Alter(37,30),Alter(37,36),Alter(37,42),Alter(37,48),Alter(37,54),Alter(37,60),Alter(37,66),Alter(37,72)),
            ( Alter(-1,0),Alter(30,5),Alter(30,10),Alter(30,15),Alter(30,20),Alter(30,25),Alter(30,30),Alter(30,35),Alter(30,40),Alter(30,45),Alter(30,50),Alter(30,55),Alter(30,60)),
          )
Consume = (
            (Alter(-1,0),Alter(13,-6),Alter(13,-9),Alter(13,-12),Alter(13,-16),Alter(13,-21),Alter(13,-27),Alter(13,-34),Alter(13,-42),Alter(13,-51),Alter(13,-62),Alter(13,-73),Alter(13,-86)),
          )


Oblation = (
            CAltarOblation(Impact0,Consume[0]),
            CAltarOblation(Impact1,Consume[0]),
            CAltarOblation(Impact2,Consume[0]),
            CAltarOblation(Impact3,Consume[0]),
            CAltarOblation(Impact4,Consume[0]),
            CAltarOblation(Impact5,Consume[0]),
            CAltarOblation(Impact6,Consume[0]),
            CAltarOblation(Impact7,Consume[0]),
            CAltarOblation(Impact8,Consume[0]),
            CAltarOblation(Impact9,Consume[0])
            )


AllAltar=( 
           CAltar(UPCondition[0],Oblation[0],1),
           CAltar(UPCondition[0],Oblation[1],2),
           CAltar(UPCondition[0],Oblation[2],3),
           CAltar(UPCondition[0],Oblation[3],4),
           CAltar(UPCondition[0],Oblation[4],5),
           CAltar(UPCondition[0],Oblation[5],6),
           CAltar(UPCondition[0],Oblation[6],7),
           CAltar(UPCondition[0],Oblation[7],8),
           CAltar(UPCondition[0],Oblation[8],9),
           CAltar(UPCondition[0],Oblation[9],10)
         )

################################################################################

if __name__ == "__main__":
       pass