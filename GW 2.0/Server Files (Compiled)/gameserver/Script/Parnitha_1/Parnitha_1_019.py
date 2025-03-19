import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1115

def GetQuestReward():
  return Script.Quest.QR1114 , Script.Quest.QR1115


def Talk( player ):
# print "talk to Parnitha_1_019"
  return "Parnitha_1_019"

