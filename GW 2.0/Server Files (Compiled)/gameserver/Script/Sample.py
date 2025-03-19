import Script.Global
import Script.Item
import Script.Altar
import GameAPI
import  Script.SysFun
from  Script.SysFun import  Alter
from  Script.SysFun import  Tranmit
from  Script.SysFun import  Approach
from  Script.SysFun import  Exchange
from  Script.SysFun import  Offical
from  Script.SysFun import  Salary

#################################################################################
TranmitTuple = {
                1:Tranmit(0,0,0,1),
                2:Tranmit(1,1,1,2),
                3:Tranmit(2,2,2,3),
                4:Tranmit(3,3,3,4)
                }

class TransmitApp(Approach):
      def __init__(self,ID):
          Approach.__init__(self,ID)
      def Callback(self,Oper,player):
          if self.id==1 :
             print "Oper[1] is %d" % Oper[1]
             if TranmitTuple.has_key(Oper[1]):
                return False,TranmitTuple[int(Oper[1])].Callback(player)
             else:
                return False,
          else:
            print "__id==0"                                               
            return True,TranmitTuple[1].GetID(),TranmitTuple[2].GetID(),TranmitTuple[3].GetID(),TranmitTuple[4].GetID()
          print "Offical Callback"
     
TransmitAppTuple = (TransmitApp(0),TransmitApp(1),None)

#################################################################################

ExchangeItem1 = Exchange(1)
ExchangeItem1.AllAlter = ( Alter(9,-5), Alter(24,100))
ExchangeItem2 = Exchange(2)
ExchangeItem2.AllAlter = ( Alter(9,-10), Alter(1,200))
ExchangeItem3 = Exchange(3)
ExchangeItem3.AllAlter = ( Alter(9,-15), Alter(1,300))
ExchangeItem4 = Exchange(4)
ExchangeItem4.AllAlter = ( Alter(9,-20), Alter(1,400))
ExchangeItem5 = Exchange(5)
ExchangeItem5.AllAlter = ( Alter(9,-30), Alter(1,500))

CreditExch = { 1:ExchangeItem1, 2:ExchangeItem2, 3:ExchangeItem3, 4:ExchangeItem4, 5:ExchangeItem5 }

class CreditExchangeApp(Approach):
      def __init__(self,ID):
          Approach.__init__(self,ID)
      def Callback(self,Oper,player):
          if self.id == 1 :
             print "Is there"
             if CreditExch.has_key(Oper[1]):
                print "has_key"
                return False,CreditExch[Oper[1]].Callback(player)
             else:
                print "No if"
                return False,
          else:
             return True,CreditExch[1].GetID(),CreditExch[2].GetID(),CreditExch[3].GetID(),CreditExch[4].GetID(),CreditExch[5].GetID()
  
CreditExchangeAppTuple = (CreditExchangeApp(0),CreditExchangeApp(1),None)

###################################################################################

Offical1 = Offical(1)
Offical1.offfical = ( Alter(9,100),Alter(10,100))
Offical2 = Offical(2)
Offical2.offfical = ( Alter(9,200),Alter(10,200))
Offical3 = Offical(3)
Offical3.offfical = ( Alter(9,300),Alter(10,3))
Offical4 = Offical(4)
Offical4.offfical = ( Alter(9,400),Alter(10,400))
Offical5 = Offical(5)
Offical5.offfical = ( Alter(9,500),Alter(10,500))

class OfficalApp(Approach):
      OfficalDict = { 
                      1:Offical1, 
                      2:Offical2, 
                      3:Offical3, 
                      4:Offical4, 
                      5:Offical5 
                    }
      def __init__(self,ID):
          Approach.__init__(self,ID)
      def GetOfficalID(self,pre):
          if pre < 1000 :
            return 255
          if pre >= 1000 and pre < 2000:
            return 1
          elif pre >= 2000 and pre < 5000:
            return 2
          else:
            return 3
      def Callback(self,Oper,player):
          if self.id==0:
             print "Offical id==0"
             if Oper[0] == Script.NPCConfig.NPC_FLAG_SYS_GRANT_OFFICAL:
                print "Script.NPCConfig.NPC_FLAG_SYS_GRANT_OFFICAL"
                Value=GameAPI.GetPlayerAttr(player,Script.SysFun.FIELD_PRESTIGE)
                print "value=%d" % Value
                return True,self.GetOfficalID(Value) 
          elif self.id==1:
              print "Offical id==1"
              Value=GameAPI.GetPlayerAttr(player,Script.SysFun.FIELD_PRESTIGE)
              print "value=%d" % Value
              Lv = self.GetOfficalID(Value)
              if OfficalApp.OfficalDict.has_key(Lv): 
                 return False,OfficalApp.OfficalDict[Lv].Callback(player)
          else:
             return False,
             
  
OfficalDictTuple = (OfficalApp(0),OfficalApp(1),None)

###################################################################################
Salary1=Salary(1)
Salary2=Salary(2)
Salary3=Salary(3)
Salary4=Salary(4)
Salary5=Salary(5)
Salary6=Salary(6)
Salary7=Salary(7)
Salary8=Salary(8)
Salary1.salary =  ( Alter(9,-5), Alter(24,100))
Salary2.salary =  ( Alter(9,-5), Alter(24,100))
Salary3.salary =  ( Alter(9,300), Alter(10,4))
Salary4.salary =  ( Alter(9,-5), Alter(24,100))
Salary5.salary =  ( Alter(9,-5), Alter(24,100))
Salary6.salary =  ( Alter(9,-5), Alter(24,100))
Salary7.salary =  ( Alter(9,-5), Alter(24,100))
Salary8.salary =  ( Alter(9,-5), Alter(24,100))

class SalaryApp(Approach):
      SalaryDict = { 
                      1:Salary1, 
                      2:Salary2, 
                      3:Salary3, 
                      4:Salary4, 
                      5:Salary5,
                      6:Salary6,
                      7:Salary7,
                      8:Salary8, 
                    }
      def __init__(self,ID):
          Approach.__init__(self,ID)
      def Callback(self,Oper,player):
          if self.id==0:
             print "Salary id==0"
             if Oper[0] == Script.NPCConfig.NPC_FLAG_SYS_OFFICAL_SALARY:
                Value=GameAPI.GetPlayerAttr(player,Script.SysFun.FIELD_KNIGHT)
                if SalaryApp.SalaryDict.has_key(Value):
                  return True,SalaryApp.SalaryDict[Value].GetID() 
          elif self.id==1:
              Value=GameAPI.GetPlayerAttr(player,Script.SysFun.FIELD_KNIGHT)
              if SalaryApp.SalaryDict.has_key(Value): 
                 return False,SalaryApp.SalaryDict[Value].Callback(player)
          else:
              return False,

SalaryProcessTuple = ( SalaryApp(0),SalaryApp(1),None)
###################################################################################

class AltarApp_0(Approach):
      def __init__(self,ID):
          Approach.__init__(self,ID)
      def Callback(self,Index,player):
          Consortia =  GameAPI.GetPlayerAttr(player,Script.SysFun.FIELD_UNION)
          Job =  GameAPI.GetPlayerAttr(player,Script.SysFun.FIELD_UNIONBUSINESS)
          print "consortia Id = %d,job = %d" % (Consortia,Job)
          if Consortia != 0 and Job >= 5:
             return True,1,2,3

class AltarApp_1(Approach):
    
      def __init__(self,ID):
          Approach.__init__(self,ID)
          
      def Callback(self,Oper,player):
          #reutrn Index+1,GameAPI.GetSurplus()
          if Oper[0] != Script.NPCConfig.NPC_FLAG_SYS_ALTAR:
             pass
          if Oper[1] == 1: #create altar
             res=GameAPI.GetHaveAltars(player)
             res.sort()
             all=[]
             for a in Script.Altar.AllAltar:
                 print "altar Id %d" % a.GetID()
                 all.append(a.GetID())
             print "append over"
             CreateAltar = list(set(all).difference(res))
             print "Difference over"
             if CreateAltar.__len__() > 0:
                CreateAltar.insert(0,True) 
             else:
                CreateAltar.insert(0,False) 
              
             return tuple(CreateAltar)  
          elif Oper[1] == 2 or Oper[1] == 3: #level up altar or delte altar
             res=GameAPI.GetHaveAltars(player)
             res.sort()
             if res.__len__() >0 :
                 res.insert(0,True)
             else:
                 res.insert(0,False)
             return tuple(res)
          else:
             return False,
            
class AltarApp_2(Approach):
      def __init__(self,ID):
          Approach.__init__(self,ID)
      def Callback(self,Oper,player):
          #reutrn Index+1,GameAPI.GetSurplus()
          if Oper[0] != Script.NPCConfig.NPC_FLAG_SYS_ALTAR:
             pass
          if Oper[1] == -1 or Oper[1] > 2:
             pass
          if Oper[2] == -1 or Oper[2] > 7:
             pass
       
          if Oper[1] == 1 :   #create altar
              return False,GameAPI.AltarCreate( player,Script.Altar.AllAltar[Oper[2]-1].GetID() )
          elif Oper[1] == 3:   #level up altar
              return False,GameAPI.AltarLevelup( player,Script.Altar.AllAltar[Oper[2]-1].GetID() )
          elif Oper[1] == 2:    #delte altar
              print "Altar will delete Id = %d" % Script.Altar.AllAltar[Oper[2]-1].GetID()
              return False,GameAPI.AltarDel( player,Script.Altar.AllAltar[Oper[2]-1].GetID() )
          else: 
              return False,
              
AltarAppTuple = (AltarApp_0(0),AltarApp_1(1),AltarApp_2(2),None)

###################################################################################

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_SYS)

def GetSysType():
  return  Script.NPCConfig.NPC_FLAG_SYS_TRANMIT+Script.NPCConfig.NPC_FLAG_SYS_CREDIT_EXCHANGE+Script.NPCConfig.NPC_FLAG_SYS_GRANT_OFFICAL+Script.NPCConfig.NPC_FLAG_SYS_OFFICAL_SALARY+Script.NPCConfig.NPC_FLAG_SYS_ALTAR

def GetContentList():
  return {
          Script.NPCConfig.NPC_FLAG_SYS_TRANMIT:TransmitAppTuple,
          Script.NPCConfig.NPC_FLAG_SYS_CREDIT_EXCHANGE:CreditExchangeAppTuple,
          Script.NPCConfig.NPC_FLAG_SYS_GRANT_OFFICAL:OfficalDictTuple,
          Script.NPCConfig.NPC_FLAG_SYS_OFFICAL_SALARY:SalaryProcessTuple,
          Script.NPCConfig.NPC_FLAG_SYS_ALTAR:AltarAppTuple
         }


def Talk():
# print "talk to Sparta_Newbie_001"
  return "Sparta_Newbie_001"

if __name__ == '__main__':
  print ""


