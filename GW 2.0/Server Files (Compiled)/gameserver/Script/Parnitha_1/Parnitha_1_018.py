import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1110

def GetQuestReward():
  return Script.Quest.QR1110


def Talk( player ):
# print "talk to Parnitha_1_018"
  return "Parnitha_1_018"

