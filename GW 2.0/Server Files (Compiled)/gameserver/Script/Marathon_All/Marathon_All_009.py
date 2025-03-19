import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER+Script.NPCConfig.NPC_FLAG_VENDOR)

def GetQuest():
  return Script.Quest.QI1157 , Script.Quest.QI1200 , Script.Quest.QI1201

def GetQuestReward():
  return Script.Quest.QR1157 , Script.Quest.QR1200 , Script.Quest.QR1201

def GetitemListType():
  return 1 , 

def GetItemList():
  return Script.Item.ItemList101 , Script.Item.ItemList0

def Talk( player ):
# print "talk to Marathon_All_009"
  return "Marathon_All_009"

