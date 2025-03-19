import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER+Script.NPCConfig.NPC_FLAG_VENDOR)

def GetQuest():
  return Script.Quest.QI154 , Script.Quest.QI155 , Script.Quest.QI134

def GetQuestReward():
  return Script.Quest.QR154 , Script.Quest.QR155 , Script.Quest.QR129 , Script.Quest.QR130 , Script.Quest.QR131 , Script.Quest.QR132 , Script.Quest.QR133 , Script.Quest.QR134

def GetitemListType():
  return 3 , 4 , 5 , 6

def GetItemList():
  return Script.Item.ItemList201 , Script.Item.ItemList211 , Script.Item.ItemList221 , Script.Item.ItemList231

def Talk( player ):
# print "talk to Sparta_024"
  return "Sparta_024"

