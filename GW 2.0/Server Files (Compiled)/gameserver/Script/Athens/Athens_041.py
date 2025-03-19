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
                4:Tranmit(2,98,-178,0,4),
                5:Tranmit(3,128,42,50,5)
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
            return True,TranmitTuple[4].GetID(),TranmitTuple[5].GetID()
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
# print "talk to Athens_041"
  return "Athens_041"

