import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1068 , Script.Quest.QI1109

def GetQuestReward():
  return Script.Quest.QR1067 , Script.Quest.QR1108 , Script.Quest.QR1109


def Talk( player ):
# print "talk to Marathon_All_007"
  return "Marathon_All_007"

