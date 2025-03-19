import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1077 , Script.Quest.QI1156

def GetQuestReward():
  return Script.Quest.QR1076 , Script.Quest.QR1156


def Talk( player ):
# print "talk to Marathon_All_008"
  return "Marathon_All_008"

