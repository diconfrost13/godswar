import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI78 , Script.Quest.QI182

def GetQuestReward():
  return Script.Quest.QR77 , Script.Quest.QR182


def Talk( player ):
# print "talk to Nemea_1_006"
  return "Nemea_1_006"

