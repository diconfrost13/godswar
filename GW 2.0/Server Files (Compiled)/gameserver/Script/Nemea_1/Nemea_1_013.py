import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI115

def GetQuestReward():
  return Script.Quest.QR114 , Script.Quest.QR115


def Talk( player ):
# print "talk to Nemea_1_013"
  return "Nemea_1_013"

