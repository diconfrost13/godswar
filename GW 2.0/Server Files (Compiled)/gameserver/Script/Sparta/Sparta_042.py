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

##################################################
TranmitTuple = {
                1:Tranmit(4,-108,-122,0,1),
                2:Tranmit(5,-156,-186,50,2)
               }

class TransmitApp(Approach):
      def __init__(self,ID):
          Approach.__init__(self,ID)
      def Callback(self,Oper,player):
          if self.id==1 :
             print "Oper[1] is %d" % Oper[1]
             if TranmitTuple.has_key(Oper[1]):
                if GameAPI.GetPlayerAttr(player,Script.SysFun.FIELD_RANK)>=TranmitTuple[int(Oper[1])].LV:
                   return False,TranmitTuple[int(Oper[1])].Callback(player)
             else:
                return True,1000
          else:
            print "__id==0"                                               
            return True,TranmitTuple[1].GetID(),TranmitTuple[2].GetID()
          print "Offical Callback"
     
TransmitAppTuple = (TransmitApp(0),TransmitApp(1),None)
#######################################################


def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_SYS)

def GetSysType():
  return  Script.NPCConfig.NPC_FLAG_SYS_TRANMIT

def GetContentList():
  return {
          Script.NPCConfig.NPC_FLAG_SYS_TRANMIT:TransmitAppTuple 
         }


def Talk( player ):
# print "talk to Sparta_042"
  return "Sparta_042"

if __name__ == '__main__':
  print ""
