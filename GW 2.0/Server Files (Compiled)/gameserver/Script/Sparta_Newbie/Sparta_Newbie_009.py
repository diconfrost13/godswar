import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER+Script.NPCConfig.NPC_FLAG_VENDOR)

def GetQuest():
  return Script.Quest.QI3

def GetQuestReward():
  return Script.Quest.QR2

def GetitemListType():
  return 1 , 2

def GetItemList():
  return Script.Item.ItemList104 , Script.Item.ItemList114

def Talk( player ):
# print "talk to Sparta_Newbie_009"
  return "Sparta_Newbie_009"

