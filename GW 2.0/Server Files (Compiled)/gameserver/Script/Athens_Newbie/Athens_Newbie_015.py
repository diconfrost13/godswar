import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER+Script.NPCConfig.NPC_FLAG_VENDOR)

def GetQuest():
  return Script.Quest.QI1192 , Script.Quest.QI1193 , Script.Quest.QI1194 , Script.Quest.QI1195

def GetQuestReward():
  return Script.Quest.QR1192 , Script.Quest.QR1193 , Script.Quest.QR1194 , Script.Quest.QR1195

def GetitemListType():
  return 15 , 16 , 17

def GetItemList():
  return Script.Item.ItemList602 , Script.Item.ItemList612 , Script.Item.ItemList622

def Talk( player ):
# print "talk to Athens_Newbie_015"
  return "Athens_Newbie_015"

