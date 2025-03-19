import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1048 , Script.Quest.QI1181 , Script.Quest.QI1185

def GetQuestReward():
  return Script.Quest.QR1047 , Script.Quest.QR1181 , Script.Quest.QR1184


def Talk( player ):
# print "talk to Marathon_All_003"
  return "Marathon_All_003"

