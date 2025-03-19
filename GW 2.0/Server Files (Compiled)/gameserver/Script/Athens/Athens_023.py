import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER+Script.NPCConfig.NPC_FLAG_VENDOR)

def GetQuest():
  return Script.Quest.QI1153

def GetQuestReward():
  return Script.Quest.QR1153

def GetitemListType():
  return 7 , 8 , 9 , 10

def GetItemList():
  return Script.Item.ItemList401 , Script.Item.ItemList411 , Script.Item.ItemList421 , Script.Item.ItemList431

def Talk( player ):
# print "talk to Athens_023"
  return "Athens_023"

