import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI93 , Script.Quest.QI94 , Script.Quest.QI111 , Script.Quest.QI112

def GetQuestReward():
  return Script.Quest.QR92 , Script.Quest.QR93 , Script.Quest.QR111 , Script.Quest.QR112


def Talk( player ):
# print "talk to Nemea_1_010"
  return "Nemea_1_010"

