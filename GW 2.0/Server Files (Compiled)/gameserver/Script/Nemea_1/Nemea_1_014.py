import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER+Script.NPCConfig.NPC_FLAG_VENDOR)

def GetQuest():
  return Script.Quest.QI202 , Script.Quest.QI203

def GetQuestReward():
  return Script.Quest.QR202 , Script.Quest.QR203

def GetitemListType():
  return 1 , 2

def GetItemList():
  return Script.Item.ItemList106 , Script.Item.ItemList116

def Talk( player ):
# print "talk to Nemea_1_014"
  return "Nemea_1_014"

