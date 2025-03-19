import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI105

def GetQuestReward():
  return Script.Quest.QR105


def Talk( player ):
# print "talk to Nemea_1_008"
  return "Nemea_1_008"

