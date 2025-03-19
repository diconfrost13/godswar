import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1032 , Script.Quest.QI1033 , Script.Quest.QI1041 , Script.Quest.QI1042 , Script.Quest.QI1046

def GetQuestReward():
  return Script.Quest.QR1031 , Script.Quest.QR1032 , Script.Quest.QR1040 , Script.Quest.QR1041 , Script.Quest.QR1045


def Talk( player ):
# print "talk to Athens_008"
  return "Athens_008"

