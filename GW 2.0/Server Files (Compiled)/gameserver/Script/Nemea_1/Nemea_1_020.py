import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER+Script.NPCConfig.NPC_FLAG_VENDOR)

def GetQuest():
  return Script.Quest.QI159 , Script.Quest.QI160

def GetQuestReward():
  return Script.Quest.QR159 , Script.Quest.QR160

def GetitemListType():
  return 11 , 12 , 13 , 14

def GetItemList():
  return Script.Item.ItemList503 , Script.Item.ItemList513 , Script.Item.ItemList523 , Script.Item.ItemList533

def Talk( player ):
# print "talk to Nemea_1_020"
  return "Nemea_1_020"

