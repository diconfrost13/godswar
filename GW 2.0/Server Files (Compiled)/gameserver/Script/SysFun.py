import types    
import Script.Global
#import Script.Item
from Script.Item import ItemData 
import GameAPI

#prestige exchange
FLAG_SYSTEM_PRESTIGE_EXCHANGE = 0
#official position
FLAG_SYSTEM_OFFICIAL_POSITION = 1
#alary fro official 
FLAG_SYSTEM_OFFICIAL_SLARY    = 2
#transmit
FLAG_SYSTEM_TRANSMIT          = 3

#player attribute type
FIELD_NAME=0
FIELD_GENDER=1
FIELD_REGIONID=2
FIELD_X=3
FIELD_Y=4
FIELD_Z=5
FIELD_SPEED=6
FIELD_STYLE=7
FIELD_FACTION=8					
FIELD_PRESTIGE=9
FIELD_KNIGHT=10
FIELD_UNION=11
FIELD_UNIONBUSINESS=12
FIELD_UIUIONCONTRIBUTE=13
FIELD_CLASS=14
FIELD_EXP=15	 
FIELD_RANK=16
FIELD_HP=17
FIELD_MP=18
FIELD_ATTACKDISTANCE=19
FIELD_ATTACKSPEED=20
FIELD_HAIRSTYLE=21
FIELD_PUPILCOLOR=22
FIELD_BELIEF=23
FIELD_MONEY=24
FIELD_STONE=25
FIELD_SKILL_POINT=26
FIELD_SKILL_EXP=27
#Altar
FIELD_MAXHP=28        
FIELD_MaxMP=29            
FIELD_RESUMEHP=30         
FIELD_RESUMEMP=31       
FIELD_ATTACK=32		
FIELD_DEFEND=33		
FIELD_MAGICATTACK=34     
FIELD_MAGICDEFEND=35    
FIELD_HIT=36		
FIELD_DODGE=37				
FIELD_CRITAPPEND=38       
FIELD_CRITDEFEND=39    
FIELD_PHYDAMAGEAPPEND=40 
FIELD_MAGICDAMAGEAPPEND=41
FIELD_DAMAGESORB=42
FIELD_BECURE=43     
FIELD_CURE=44         
FIELD_STATUSHIT=45
FIELD_STATUDDODGE=46

class Alter:
      def __init__(self,type,value):
         self.Type = type
         self.Value= value
      def Callback(self,player):
          print "Altar callback"
          return GameAPI.AcceptGiftAttr(player,self)
      def GetValue(self):
          print "value = %d" % self.Value
          return self.Value

          
class GiftItem(ItemData):
      def __init__(self):
          ItemData.__init__(self)
      def Callback(self,player):
          print "GiftItem Callback"
          return GameAPI.AcceptGiftItem(player,self)

class Approach:
      def __init__(self,ID):
          self.id=ID
      def Callback(self):
          print "Approach ..."

class Tranmit:
      def __init__(self,MAP,X,Z,lv,id):
          self.__Alter_X   =  Alter(3,X )
          self.__Alter_Z   =  Alter(5,Z)
          self.__Alter_MAP =  Alter(2,MAP)
          self.LV          =  lv
          self.__ID        =  id
      def GetID(self):
          print self.__ID
          return self.__ID
      def Callback(self,player):
             return GameAPI.Fly(player,self.__Alter_MAP.Value,self.__Alter_X.Value,0,self.__Alter_Z.Value)

class Exchange:
      def __init__(self,ID):
          self.AllAlter=()
          self.id=ID
      def GetID(self):
          return self.id
      def Callback(self,player):
          for Item in self.AllAlter: 
              print "Execute..."
              if not Item.Callback(player):
                return False;
	      else:
		print "Exchange success!"
          return True
           
class Offical:
      def __init__(self,ID):
          self.offfical=()
          self.__id=id
      def GetID(self):
          return self.__id
      def Callback(self,player):
          for Offic in self.offfical:
              print "Offical Callback"
              Offic.Callback(player);
          return True

class Salary:
      def __init__(self,id):
          self.salary=()
          self.id=id
      def GetUpdate(self):
          return self.salary
      def GetID(self):
          return self.id
      def Callback(self,player):
          for Item in self.salary:
                print "Salary Callback"
    #           if type(Item) is types.TupleType:   
    #              for Sal in Item:
    #                 Sal.Callback(player);
    #            else:
                Item.Callback(player);
          return True


class GuildQuest:
      def __init__(self,id,list):
  
          self.ID        =  id
          self.List      =  list

      def GetID(self):
          print self.ID
          return self.ID
      def Callback(self,player):
          return GameAPI.GuildQuestRelease(player,self.List)  #Release_Quests_Of_One_List



Item1=GiftItem()
Item1.Base=2602
Item1.Money=0

Item2=GiftItem()
Item2.Base=2602
Item2.Money=0

Function={
           FLAG_SYSTEM_PRESTIGE_EXCHANGE:((Alter(0,-100),Item1),(Alter(0,-200),Item1),(Alter(0,-200),Item2)),
           FLAG_SYSTEM_OFFICIAL_POSITION:(Alter(0,20),Alter(1,40),Alter(2,30)),
           FLAG_SYSTEM_OFFICIAL_SLARY:( 
                                        (Alter(0,100),Item1,Item1,Item1,Item1),
                                        (Alter(0,100),Item1,Item1,Item1,Item1),
                                        (Alter(0,100),Item1,Item1,Item1,Item1),
                                        (Alter(0,100),Item1,Item1,Item1,Item1),
                                        (Alter(0,100),Item1,Item1,Item1,Item1),
                                        (Alter(0,100),Item1,Item1,Item1,Item1),
                                        (Alter(0,100),Item1,Item1,Item1,Item1),
                                        (Alter(0,100),Item1,Item1,Item1,Item1),
                                        (Alter(0,100),Item1,Item1,Item1,Item1),
                                        (Alter(0,100),Item1,Item1,Item1,Item1),
                                        (Alter(0,100),Item1,Item1,Item1,Item1),
                                        (Alter(0,100),Item1,Item1,Item1,Item1),
                                        (Alter(0,100),Item1,Item1,Item1,Item1),
                                        (Alter(0,100),Item1,Item1,Item1,Item1),
                                        (Alter(0,100),Item1,Item1,Item1,Item1),
                                        (Alter(0,100),Item1,Item1,Item1,Item1),
                                      )
         }

if __name__ == '__main__':
  print ""