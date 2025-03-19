import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI69 , Script.Quest.QI90 , Script.Quest.QI99

def GetQuestReward():
  return Script.Quest.QR68 , Script.Quest.QR89 , Script.Quest.QR98


def Talk( player ):
# print "talk to Nemea_1_001"
  return "Nemea_1_001"

