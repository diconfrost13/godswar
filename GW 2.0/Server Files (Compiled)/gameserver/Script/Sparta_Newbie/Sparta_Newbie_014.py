import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER+Script.NPCConfig.NPC_FLAG_VENDOR)

def GetQuest():
  return Script.Quest.QI1 , Script.Quest.QI190 , Script.Quest.QI191 , Script.Quest.QI197

def GetQuestReward():
  return Script.Quest.QR0 , Script.Quest.QR190 , Script.Quest.QR191 , Script.Quest.QR197

def GetitemListType():
  return 7 , 8 , 9 , 10

def GetItemList():
  return Script.Item.ItemList402 , Script.Item.ItemList412 , Script.Item.ItemList422 , Script.Item.ItemList432

def Talk( player ):
# print "talk to Sparta_Newbie_014"
  return "Sparta_Newbie_014"

