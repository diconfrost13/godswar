import Script.Global
import Script.Item
#import Script.Altar
#import Script.GuildQuestList

import GameAPI
import  Script.SysFun
#from  Script.SysFun import  Alter
#from  Script.SysFun import  Tranmit
from  Script.SysFun import  Approach
#from  Script.SysFun import  Exchange
#from  Script.SysFun import  Offical
#from  Script.SysFun import  Salary
from  Script.SysFun import  GuildQuest

#################################################################################

GuildQuestTuple = {
                3:GuildQuest(3,1201),
                4:GuildQuest(4,1202)

                }

#Noinput


class GuildQuestApp(Approach):
      def __init__(self,ID):
          Approach.__init__(self,ID)

      def Callback(self,Oper,player):
          if self.id==1 :
             print "Oper[1] is %d" % Oper[1]
             if GuildQuestTuple.has_key(Oper[1]):
                if GameAPI.GetPlayerAttr(player,Script.SysFun.FIELD_UNIONBUSINESS)>4:
                   return True,1000,GuildQuestTuple[int(Oper[1])].Callback(player)
                if GameAPI.GetPlayerAttr(player,Script.SysFun.FIELD_UNIONBUSINESS)<5:
                   return True,1001
             else:
                return False,
          else:
            print "__id==0"
            return True,GuildQuestTuple[3].GetID(),GuildQuestTuple[4].GetID()

          print "GuildQuest Callback"





GuildQuestAppTuple = (GuildQuestApp(0),GuildQuestApp(1),None)

#################################################################################



if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_SYS+Script.NPCConfig.NPC_FLAG_QUESTGIVER)

def GetSysType():
  return  Script.NPCConfig.NPC_FLAG_GuildQuest

def GetContentList():
  return {

          Script.NPCConfig.NPC_FLAG_GuildQuest:GuildQuestAppTuple
         }


def GetQuest():
  return Script.Quest.QI1207 , Script.Quest.QI1208 , Script.Quest.QI1209 , Script.Quest.QI1210 , Script.Quest.QI1211 , Script.Quest.QI1212, Script.Quest.QI1223 , Script.Quest.QI1224 , Script.Quest.QI1225 , Script.Quest.QI1226 , Script.Quest.QI1227 , Script.Quest.QI1228 , Script.Quest.QI1229 , Script.Quest.QI1230 




def test():
   print "NPCType",GetType()
   for a in GetQuest():
      print "Get QuestID = %d ,ID" % a.QuestID 
#print "Reward QuestID = %d ,ID" % a.QuestID


def Talk( player ):
# print "talk to Athens_038"
  return "Athens_038"

