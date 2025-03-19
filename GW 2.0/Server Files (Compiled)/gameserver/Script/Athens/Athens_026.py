import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER+Script.NPCConfig.NPC_FLAG_VENDOR)

def GetQuest():
  return Script.Quest.QI1154 , Script.Quest.QI1155 , Script.Quest.QI1134

def GetQuestReward():
  return Script.Quest.QR1154 , Script.Quest.QR1155 , Script.Quest.QR1129 , Script.Quest.QR1130 , Script.Quest.QR1131 , Script.Quest.QR1132 , Script.Quest.QR1133 , Script.Quest.QR1134

def GetitemListType():
  return 3 , 4 , 5 , 6

def GetItemList():
  return Script.Item.ItemList201 , Script.Item.ItemList211 , Script.Item.ItemList221 , Script.Item.ItemList231

def Talk( player ):
# print "talk to Athens_026"
  return "Athens_026"

