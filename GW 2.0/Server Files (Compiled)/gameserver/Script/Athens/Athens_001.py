import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1015 , Script.Quest.QI1097 , Script.Quest.QI1148 , Script.Quest.QI1149

def GetQuestReward():
  return Script.Quest.QR1014 , Script.Quest.QR1096 , Script.Quest.QR1148 , Script.Quest.QR1149


def Talk( player ):
# print "talk to Athens_001"
  return "Athens_001"

