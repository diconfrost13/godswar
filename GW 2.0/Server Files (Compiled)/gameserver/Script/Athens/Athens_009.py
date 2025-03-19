import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1024 , Script.Quest.QI1027 , Script.Quest.QI1031 , Script.Quest.QI1034 , Script.Quest.QI1047 , Script.Quest.QI1060 , Script.Quest.QI1108

def GetQuestReward():
  return Script.Quest.QR1023 , Script.Quest.QR1026 , Script.Quest.QR1030 , Script.Quest.QR1033 , Script.Quest.QR1046 , Script.Quest.QR1059 , Script.Quest.QR1107


def Talk( player ):
# print "talk to Athens_009"
  return "Athens_009"

