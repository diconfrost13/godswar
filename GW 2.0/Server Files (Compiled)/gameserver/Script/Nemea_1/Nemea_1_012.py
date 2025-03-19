import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI110

def GetQuestReward():
  return Script.Quest.QR110


def Talk( player ):
# print "talk to Nemea_1_012"
  return "Nemea_1_012"

