import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER+Script.NPCConfig.NPC_FLAG_VENDOR)

def GetQuest():
  return Script.Quest.QI1003

def GetQuestReward():
  return Script.Quest.QR1002

def GetitemListType():
  return 1 , 2

def GetItemList():
  return Script.Item.ItemList103 , Script.Item.ItemList113

def Talk( player ):
# print "talk to Athens_Newbie_002"
  return "Athens_Newbie_002"

