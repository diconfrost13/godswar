import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1016 , Script.Quest.QI1017 , Script.Quest.QI1061 , Script.Quest.QI1067

def GetQuestReward():
  return Script.Quest.QR1015 , Script.Quest.QR1016 , Script.Quest.QR1060 , Script.Quest.QR1066


def Talk( player ):
# print "talk to Athens_002"
  return "Athens_002"

