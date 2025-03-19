import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1070 , Script.Quest.QI1071 , Script.Quest.QI1073 , Script.Quest.QI1081

def GetQuestReward():
  return Script.Quest.QR1069 , Script.Quest.QR1070 , Script.Quest.QR1072 , Script.Quest.QR1080


def Talk( player ):
# print "talk to Parnitha_1_002"
  return "Parnitha_1_002"

