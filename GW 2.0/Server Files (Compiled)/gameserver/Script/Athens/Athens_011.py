import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1043 , Script.Quest.QI1136

def GetQuestReward():
  return Script.Quest.QR1042 , Script.Quest.QR1135 , Script.Quest.QR1136


def Talk( player ):
# print "talk to Athens_011"
  return "Athens_011"

