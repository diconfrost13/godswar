import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER+Script.NPCConfig.NPC_FLAG_VENDOR)

def GetQuest():
  return Script.Quest.QI1151 , Script.Quest.QI1152

def GetQuestReward():
  return Script.Quest.QR1151 , Script.Quest.QR1152

def GetitemListType():
  return 3 , 4 , 5 , 6

def GetItemList():
  return Script.Item.ItemList302 , Script.Item.ItemList312 , Script.Item.ItemList322 , Script.Item.ItemList332

def Talk( player ):
# print "talk to Athens_Newbie_014"
  return "Athens_Newbie_014"

