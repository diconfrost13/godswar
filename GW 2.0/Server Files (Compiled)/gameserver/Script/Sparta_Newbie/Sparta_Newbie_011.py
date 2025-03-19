import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER+Script.NPCConfig.NPC_FLAG_VENDOR)

def GetQuest():
  return Script.Quest.QI151 , Script.Quest.QI152

def GetQuestReward():
  return Script.Quest.QR151 , Script.Quest.QR152

def GetitemListType():
  return 3 , 4 , 5 , 6

def GetItemList():
  return Script.Item.ItemList302 , Script.Item.ItemList312 , Script.Item.ItemList322 , Script.Item.ItemList332

def Talk( player ):
# print "talk to Sparta_Newbie_011"
  return "Sparta_Newbie_011"

