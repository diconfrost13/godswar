import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER+Script.NPCConfig.NPC_FLAG_VENDOR)

def GetQuest():
  return Script.Quest.QI157 , Script.Quest.QI200 , Script.Quest.QI201

def GetQuestReward():
  return Script.Quest.QR157 , Script.Quest.QR200 , Script.Quest.QR201

def GetitemListType():
  return 1 , 

def GetItemList():
  return Script.Item.ItemList102 , Script.Item.ItemList0

def Talk( player ):
# print "talk to Peloponnese_All_009"
  return "Peloponnese_All_009"

