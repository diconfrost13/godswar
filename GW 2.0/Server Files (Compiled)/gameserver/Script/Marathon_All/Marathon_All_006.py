import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1064 , Script.Quest.QI1065

def GetQuestReward():
  return Script.Quest.QR1063 , Script.Quest.QR1064


def Talk( player ):
# print "talk to Marathon_All_006"
  return "Marathon_All_006"

