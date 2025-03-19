import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER+Script.NPCConfig.NPC_FLAG_VENDOR)

def GetQuest():
  return Script.Quest.QI1202 , Script.Quest.QI1203

def GetQuestReward():
  return Script.Quest.QR1202 , Script.Quest.QR1203

def GetitemListType():
  return 1 , 2

def GetItemList():
  return Script.Item.ItemList105 , Script.Item.ItemList115

def Talk( player ):
# print "talk to Parnitha_1_008"
  return "Parnitha_1_008"

