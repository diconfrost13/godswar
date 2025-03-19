import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER+Script.NPCConfig.NPC_FLAG_VENDOR)

def GetQuest():
  return Script.Quest.QI1001 , Script.Quest.QI1190 , Script.Quest.QI1191 , Script.Quest.QI1197

def GetQuestReward():
  return Script.Quest.QR1000 , Script.Quest.QR1190 , Script.Quest.QR1191 , Script.Quest.QR1197

def GetitemListType():
  return 7 , 8 , 9 , 10

def GetItemList():
  return Script.Item.ItemList402 , Script.Item.ItemList412 , Script.Item.ItemList422 , Script.Item.ItemList432

def Talk( player ):
# print "talk to Athens_Newbie_009"
  return "Athens_Newbie_009"

