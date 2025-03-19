import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER+Script.NPCConfig.NPC_FLAG_VENDOR)

def GetQuest():
  return Script.Quest.QI4 , Script.Quest.QI37 , Script.Quest.QI39

def GetQuestReward():
  return Script.Quest.QR3 , Script.Quest.QR36 , Script.Quest.QR38

def GetitemListType():
  return 3 , 4 , 5 , 6

def GetItemList():
  return Script.Item.ItemList202 , Script.Item.ItemList212 , Script.Item.ItemList222 , Script.Item.ItemList232

def Talk( player ):
# print "talk to Sparta_Newbie_010"
  return "Sparta_Newbie_010"

