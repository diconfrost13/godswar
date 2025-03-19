import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER+Script.NPCConfig.NPC_FLAG_VENDOR)

def GetQuest():
  return Script.Quest.QI192 , Script.Quest.QI193 , Script.Quest.QI194 , Script.Quest.QI195

def GetQuestReward():
  return Script.Quest.QR192 , Script.Quest.QR193 , Script.Quest.QR194 , Script.Quest.QR195

def GetitemListType():
  return 15 , 16 , 17

def GetItemList():
  return Script.Item.ItemList602 , Script.Item.ItemList612 , Script.Item.ItemList622

def Talk( player ):
# print "talk to Sparta_Newbie_015"
  return "Sparta_Newbie_015"

