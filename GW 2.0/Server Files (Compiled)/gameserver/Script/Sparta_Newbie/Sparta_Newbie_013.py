import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER+Script.NPCConfig.NPC_FLAG_VENDOR)

def GetQuest():
  return Script.Quest.QI8 , Script.Quest.QI9

def GetQuestReward():
  return Script.Quest.QR7 , Script.Quest.QR8

def GetitemListType():
  return 11 , 12 , 13 , 14

def GetItemList():
  return Script.Item.ItemList502 , Script.Item.ItemList512 , Script.Item.ItemList522 , Script.Item.ItemList532

def Talk( player ):
# print "talk to Sparta_Newbie_013"
  return "Sparta_Newbie_013"

