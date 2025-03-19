import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1116 , Script.Quest.QI1117 , Script.Quest.QI1118 , Script.Quest.QI1119 , Script.Quest.QI1120 , Script.Quest.QI1121 , Script.Quest.QI1122

def GetQuestReward():
  return Script.Quest.QR1116 , Script.Quest.QR1117 , Script.Quest.QR1118 , Script.Quest.QR1119 , Script.Quest.QR1120 , Script.Quest.QR1121 , Script.Quest.QR1122


def Talk( player ):
# print "talk to Athens_015"
  return "Athens_015"

