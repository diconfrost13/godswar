import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1101 , Script.Quest.QI1102 , Script.Quest.QI1103

def GetQuestReward():
  return Script.Quest.QR1101 , Script.Quest.QR1102 , Script.Quest.QR1103


def Talk( player ):
# print "talk to Athens_019"
  return "Athens_019"

