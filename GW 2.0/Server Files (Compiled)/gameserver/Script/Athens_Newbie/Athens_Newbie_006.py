import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER+Script.NPCConfig.NPC_FLAG_VENDOR)

def GetQuest():
  return Script.Quest.QI1008 , Script.Quest.QI1009

def GetQuestReward():
  return Script.Quest.QR1007 , Script.Quest.QR1008

def GetitemListType():
  return 11 , 12 , 13 , 14

def GetItemList():
  return Script.Item.ItemList502 , Script.Item.ItemList512 , Script.Item.ItemList522 , Script.Item.ItemList532

def Talk( player ):
# print "talk to Athens_Newbie_006"
  return "Athens_Newbie_006"

