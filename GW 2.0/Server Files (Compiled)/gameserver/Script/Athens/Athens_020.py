import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1128

def GetQuestReward():
  return Script.Quest.QR1123 , Script.Quest.QR1124 , Script.Quest.QR1125 , Script.Quest.QR1126 , Script.Quest.QR1127 , Script.Quest.QR1128


def Talk( player ):
# print "talk to Athens_020"
  return "Athens_020"

