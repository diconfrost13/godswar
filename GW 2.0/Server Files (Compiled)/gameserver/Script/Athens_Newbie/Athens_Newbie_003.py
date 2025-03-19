import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER+Script.NPCConfig.NPC_FLAG_VENDOR)

def GetQuest():
  return Script.Quest.QI1004 , Script.Quest.QI1037 , Script.Quest.QI1039

def GetQuestReward():
  return Script.Quest.QR1003 , Script.Quest.QR1036 , Script.Quest.QR1038

def GetitemListType():
  return 3 , 4 , 5 , 6

def GetItemList():
  return Script.Item.ItemList202 , Script.Item.ItemList212 , Script.Item.ItemList222 , Script.Item.ItemList232

def Talk( player ):
# print "talk to Athens_Newbie_003"
  return "Athens_Newbie_003"

