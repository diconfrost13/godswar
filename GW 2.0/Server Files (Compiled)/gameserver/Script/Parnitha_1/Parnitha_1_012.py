import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER+Script.NPCConfig.NPC_FLAG_VENDOR)

def GetQuest():
  return Script.Quest.QI1158

def GetQuestReward():
  return Script.Quest.QR1158

def GetitemListType():
  return 7 , 8 , 9 , 10

def GetItemList():
  return Script.Item.ItemList403 , Script.Item.ItemList413 , Script.Item.ItemList423 , Script.Item.ItemList433

def Talk( player ):
# print "talk to Parnitha_1_012"
  return "Parnitha_1_012"

