import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1074 , Script.Quest.QI1075 , Script.Quest.QI1076 , Script.Quest.QI1079

def GetQuestReward():
  return Script.Quest.QR1073 , Script.Quest.QR1074 , Script.Quest.QR1075 , Script.Quest.QR1078


def Talk( player ):
# print "talk to Parnitha_1_004"
  return "Parnitha_1_004"

