import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1028 , Script.Quest.QI1030

def GetQuestReward():
  return Script.Quest.QR1027 , Script.Quest.QR1029


def Talk( player ):
# print "talk to Athens_006"
  return "Athens_006"

