import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1078 , Script.Quest.QI1182

def GetQuestReward():
  return Script.Quest.QR1077 , Script.Quest.QR1182


def Talk( player ):
# print "talk to Parnitha_1_006"
  return "Parnitha_1_006"

