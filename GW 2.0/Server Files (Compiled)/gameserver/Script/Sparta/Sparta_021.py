import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI114

def GetQuestReward():
  return Script.Quest.QR113


def Talk( player ):
# print "talk to Sparta_021"
  return "Sparta_021"

